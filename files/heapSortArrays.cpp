#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i) { // Added an index for easier tracking
    // Build the minHeap -> arr[] represents the heap, n is size, i is index

    int smallest = i; // Initializing root as the smallest
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If the left child is smaller than the root
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If the right child is smaller than the smallest value so far
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If the smallest is not the root, swap them and continue the heapify
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest); // Heapify the subtree again
    }
}

// Main function to perform heap sort on the array
void heapSort(int arr[], int n) {
    // Step 1: Build a max-heap
    // Parent of the last element is at index n / 2 - 1
    // Nodes from there onwards are leaf nodes
    // Loop processes backwards so that all child nodes are heapify checked
    for(int i = (n/2) - 1; i >= 0; i--) {
        heapify(arr, n, i); // In case new heap violates heap property
    }

    // Step 2: Extract elements from the heap one by one, moving current root to the end
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        // Step 3: Heapify the newly reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test cases
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr2[] = {}; // Empty array
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {50}; // One element
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    int arr4[] = {1, 1, 1, 1}; // All the same elements
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    int arr5[] = {2, 3, 6, 9, 11, 15}; // Arrasy is already sorted
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    int arr6[] = {-1, -8, -2, -5, -3}; // Negative numbers
    int n6 = sizeof(arr6) / sizeof(arr6[0]);

    int arr7[] = {5, 4, 3, 2, 1}; // Reverse order
    int n7 = sizeof(arr7) / sizeof(arr7[0]);

    int arr8[] = {1, 0, -3, 7, 10, -5, 11}; // Mix of positive, negative, and zero
    int n8 = sizeof(arr8) / sizeof(arr8[0]);


    // === //
    cout << "Original array:\n";
    printArray(arr, n);
    cout << endl;

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr2, n2);
    cout << endl;

    // Call the heapSort function
    heapSort(arr2, n2);

    cout << "Sorted array:\n";
    printArray(arr2, n2);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr3, n3);
    cout << endl;

    // Call the heapSort function
    heapSort(arr3, n3);

    cout << "Sorted array:\n";
    printArray(arr3, n3);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr4, n4);
    cout << endl;

    // Call the heapSort function
    heapSort(arr4, n4);

    cout << "Sorted array:\n";
    printArray(arr4, n4);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr5, n5);
    cout << endl;

    // Call the heapSort function
    heapSort(arr5, n5);

    cout << "Sorted array:\n";
    printArray(arr5, n5);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr6, n6);
    cout << endl;

    // Call the heapSort function
    heapSort(arr6, n6);

    cout << "Sorted array:\n";
    printArray(arr6, n6);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr7, n7);
    cout << endl;

    // Call the heapSort function
    heapSort(arr7, n7);

    cout << "Sorted array:\n";
    printArray(arr7, n7);
    // === //

    // === //
    cout << "Original array:\n";
    printArray(arr8, n8);
    cout << endl;

    // Call the heapSort function
    heapSort(arr8, n8);

    cout << "Sorted array:\n";
    printArray(arr8, n8);
    // === //


    return 0;
}