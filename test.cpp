#include <SFML/Graphics.hpp>
#include <optional>
int main() { sf::RenderWindow w(sf::VideoMode({800,600}), "Test Window"); while(w.isOpen()) { while(const std::optional e = w.pollEvent()) { if(e->is<sf::Event::Closed>()) w.close(); } w.clear(sf::Color::Blue); w.display(); } return 0; }
