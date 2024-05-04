//
// Created by tinti on 2024-04-24.
//

#ifndef LABORATION_2_ALGOS_H
#define LABORATION_2_ALGOS_H


#include <queue>
#include <stack>
#include <set>

void insertion_sort(std::vector<int> &vec);

void selection_sort(std::vector<int> &vec);

int partition_piv_right(std::vector<int> &vec, int low, int high) ;

void quicksort_piv_right(std::vector<int> &vec, int low, int high) ;

int partition_piv_median(std::vector<int> &vec, int low, int high);

void quicksort_piv_median(std::vector<int> &vec, int low, int high) ;


#endif //LABORATION_2_ALGOS_H
