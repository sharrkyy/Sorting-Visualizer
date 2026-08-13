#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <semaphore>
#include "measure.h"
#include "sorting.h"
#include <thread>

std::binary_semaphore ready(0);
std::binary_semaphore value(0);

bool completed = false;
int selectedIdx = -1, otherIdx = -1;

int main() {

    std::cout << "Sorting Visualizer!!" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Insertion Sort" << std::endl;
    std::cout << "3. Selection Sort" << std::endl;

    int choice;

    while (true) {

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 3) break;

        if (choice < 1 || choice > 3) {
            std::cout << "Oops, that's not possible. Try again, mate \n";
            continue;
        }
    }

    std::vector<void (*)(std::vector<int>&)> algorithms = { bubble_sort,
                                                            insertion_sort,
                                                            selection_sort };

    int numBars = 100;
    std::vector<int> bars;

    for (int i = 0; i < numBars; i++) {

        int height = 10 + i * (HEIGHT - 10) / numBars;
        bars.push_back(height);
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(bars.begin(), bars.end(), rng);

    std::thread worker(algorithms[choice - 1], std::ref(bars));
    worker.detach();

    sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(WIDTH),
                                             static_cast<unsigned int>(HEIGHT) }),
                             "Sorting Visualizer");
    window.setFramerateLimit(60);

    int barWidth = WIDTH / numBars - 1;
    int stride = barWidth + 1;

    int slideAmount = 0;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (!completed && slideAmount == 0) {
            ready.acquire();
        }

        window.clear(sf::Color::Black);

        int distance = (otherIdx - selectedIdx) * stride;
        int direction = (distance >= 0) ? 1 : -1;
        bool swapping = !completed && selectedIdx != -1 && otherIdx != -1;

        if (swapping && slideAmount < std::abs(distance)) {
            slideAmount += 4;
        }

        for (int i = 0; i < numBars; i++) {

            sf::RectangleShape rect(sf::Vector2f(static_cast<float>(barWidth),
                                                  static_cast<float>(bars[i])));
            int x = i * stride;

            if (swapping && i == selectedIdx) {
                x += slideAmount * direction;
                rect.setFillColor(sf::Color::Red);
            }

            else if (swapping && i == otherIdx) {
                x -= slideAmount * direction;
                rect.setFillColor(sf::Color::Red);
            }

            else {
                rect.setFillColor(sf::Color::White);
            }

            rect.setPosition(sf::Vector2f(static_cast<float>(x),
                                           static_cast<float>(HEIGHT - bars[i])));
            window.draw(rect);
        }

        window.display();

        if (swapping && slideAmount >= std::abs(distance)) {

            slideAmount = 0;
            value.release();
        }

        else if (!completed && slideAmount == 0) {
            value.release();
        }

    }

    return 0;
}