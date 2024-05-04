//
// Created by tinti on 2024-04-24.
//

#include <algorithm>
#include "Algos.h"


void insertion_sort(std::vector<int> &vec) {
    // Iterate over the vector starting from the second element
    for (int current_index = 1; current_index < vec.size(); current_index++) {
        // While the current element is smaller than the previous one, swap them
        while(current_index > 0 && vec[current_index - 1] > vec[current_index]){
            std::swap(vec[current_index], vec[current_index - 1]);
            current_index--;
        }
    }
}

void selection_sort(std::vector<int> &vec) {
    for (int current_index = 0; current_index < vec.size(); current_index++) {
        // Find the smallest element in the unsorted part of the vector
        int min = current_index;
        for (int comparison_index = current_index + 1; comparison_index < vec.size(); comparison_index++) {
            if (vec[comparison_index] < vec[min]) {
                min = comparison_index;
            }
        }
        // Swap the current element with the smallest found
        std::swap(vec[current_index], vec[min]);
    }
}

int partition_piv_right(std::vector<int> &vec, int low, int high) {
    // Pivot is the last element
    int pivot = vec[high];
    // Index of the last element smaller than the pivot
    int last_smaller_index = low - 1;
    // Iterate over the vector
    for (int current_index = low; current_index < high; current_index++) {
        // If current element is smaller than pivot, swap it with the element at last_smaller_index + 1
        if (vec[current_index] < pivot) {
            last_smaller_index++;
            std::swap(vec[last_smaller_index], vec[current_index]);
        }
    }
    // Swap the pivot with the first element larger than it
    std::swap(vec[last_smaller_index + 1], vec[high]);
    // Return the index of the pivot
    return last_smaller_index + 1;
}

void quicksort_piv_right(std::vector<int> &vec, int low, int high) {
    if (low < high) {
        int pivot = partition_piv_right(vec, low, high);
        quicksort_piv_right(vec, low, pivot - 1);
        quicksort_piv_right(vec, pivot + 1, high);
    }
}

int partition_piv_median(std::vector<int> &vec, int low, int high) {
    // Calculate the index of the middle element
    int mid = low + (high - low) / 2;
    // Sort the first, middle and last elements
    if (vec[high] < vec[low]) {
        std::swap(vec[low], vec[high]);
    }
    if (vec[mid] < vec[low]) {
        std::swap(vec[mid], vec[low]);
    }
    if (vec[high] < vec[mid]) {
        std::swap(vec[high], vec[mid]);
    }
    // Return the index of the median
    return mid;
}

void quicksort_piv_median(std::vector<int> &vec, int low, int high) {
    if (low < high) {
        // Partition the vector around the median and get the median index
        int pivot_index = partition_piv_median(vec, low, high);
        // Move the pivot to the end of the vector
        std::swap(vec[pivot_index], vec[high]);
        // Pivot is the last element
        int pivot = vec[high];
        // Index of the last element smaller than the pivot
        int i = low - 1;
        for (int current = low; current < high; current++) {
            // If current element is smaller than or equal to pivot, swap it with the element at i + 1
            if (vec[current] <= pivot) {
                i++;
                std::swap(vec[i], vec[current]);
            }
        }
        // Move the pivot to its final place
        std::swap(vec[i + 1], vec[high]);
        // Pivot is now at i + 1
        pivot = i + 1;
        // Recursively sort the elements smaller than the pivot
        quicksort_piv_median(vec, low, pivot - 1);
        // Recursively sort the elements larger than the pivot
        quicksort_piv_median(vec, pivot + 1, high);
    }
}
