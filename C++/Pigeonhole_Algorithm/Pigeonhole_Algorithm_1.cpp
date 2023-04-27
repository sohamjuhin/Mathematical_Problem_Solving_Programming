#include <iostream>
#include <vector>
#include <algorithm>

/* Sorts the vector using pigeonhole algorithm */
void pigeonhole_sort(std::vector<int>& arr) {
    // Find minimum and maximum values in arr
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    int range = max - min + 1; // Find range

    // Create an array of vectors. Size of array
    // range. Each vector represents a hole that
    // is going to contain matching elements.
    std::vector<int> holes[range];

    // Traverse through input array and put every
    // element in its respective hole
    for (int& num : arr) {
        holes[num - min].push_back(num);
    }

    // Traverse through all holes one by one. For
    // every hole, take its elements and put in
    // array.
    int index = 0; // index in sorted array
    for (int i = 0; i < range; i++) {
        for (int& num : holes[i]) {
            arr[index++] = num;
        }
    }
}

// Driver program to test the above function
int main() {
    std::vector<int> arr = {8, 3, 2, 7, 4, 6, 8};

    pigeonhole_sort(arr);

    std::cout << "Sorted order is: ";
    for (int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
