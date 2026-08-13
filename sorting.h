#pragma once

#include <vector>
#include <semaphore>

extern std::binary_semaphore ready;
extern std::binary_semaphore value;
extern bool completed;
extern int selectedIdx, otherIdx;

void bubble_sort(std::vector<int>& vec);
void selection_sort(std::vector<int>& vec);
void insertion_sort(std::vector<int>& vec);

