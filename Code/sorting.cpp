#include<iostream>
#include <vector>
#include "sorting.h"
#include <algorithm>

static void reportSwap(int i, int j) {

    selectedIdx = i;
    otherIdx = j;
    ready.release();
    value.acquire();
}

static void finishSort() {

    completed = true;
    ready.release();
}

void bubble_sort(std::vector<int>& vec) {

    for (auto it = vec.begin(); it != vec.end() - 1; it++) {
        bool isSwap = false;

        for (auto jt = vec.begin(); jt != vec.end() - (it - vec.begin()) - 1; jt++) {
            if (*jt > *(jt + 1)) {

                reportSwap(jt - vec.begin(), (jt + 1) - vec.begin());
                std::swap(*jt, *(jt + 1));
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
        }
    }

    finishSort();
}

void selection_sort(std::vector<int>& vec) {

    for (auto it = vec.begin(); it != vec.end() - 1; it++) {
        auto min = it;

        for (auto jt = it + 1; jt != vec.end(); jt++) {
            if (*jt < *min)
                min = jt;
        }

        if (min != it) {
            reportSwap(it - vec.begin(), min - vec.begin());
            std::swap(*it, *min);
        }
    }

    finishSort();
}

void insertion_sort(std::vector<int>& vec) {

    for (auto it = vec.begin() + 1; it != vec.end(); it++) {

        int curr = *it;
        auto prev = it;

        while (prev != vec.begin() && *(prev - 1) > curr) {
            reportSwap((prev - 1) - vec.begin(), prev - vec.begin());
            
            *prev = *(prev - 1);
            prev--;
        }

        *prev = curr;
    }

    finishSort();
}