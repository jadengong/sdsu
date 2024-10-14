#include <iostream>
using namespace std;

// Inserts elements one by one and up-heapifies
void heapify(int arr[], int n) {
    // Build the heap -> arr[] represents the heap, n is size

    // Start with the first element and iterate through the array
    for (int i = 0; i < n; i++) {
        int currentIndex = i; // Index of the element being inserted

        // Up-heapify the newly inserted element
        bool swapped = true;
        while (currentIndex > 0 && swapped) {
            swapped = false;
            int parentIndex = (currentIndex - 1) / 2; // Calculate parent index

            // If the current element is smaller than its parent, swap them
            if (arr[currentIndex] < arr[parentIndex]) {
                swap(arr[currentIndex], arr[parentIndex]);
                currentIndex = parentIndex; // Move up to the parent
                swapped = true;
            }
        }
    }

}

// Destroys elements one by one and down-heapifies
void heapSort(int arr[], int n) {
    // Step 1: Build a min-heap
    heapify(arr, n);

    // Step 1.5: Create a temp array to store sorted elements
    int* sortedArr = new int[n];

    // Step 2: Extract smallest (root) element and store in temp array
    for(int i = 0; i < n; i++) {
        sortedArr[i] = arr[0];
        // Move the last element to the root
        arr[0] = arr[n - 1- i];

        // Step 3: Heapify the newly reduced heap -> downHeap
        int smallest = 0;
        bool heapified = false;
        int heapSize = n - 1 - i; // Reduce size

        while(!heapified) {
            int left = 2 * smallest + 1;
            int right = 2 * smallest + 2;
            int next = smallest;

            // Check if left is < than current smallest AND we haven't reached a leaf node
            if(left < heapSize && arr[left] < arr[next]) {
                next = left;
            }

            // Check if right is < than current smallest AND we haven't reached a leaf node
            if(right < heapSize && arr[right] < arr[next]) {
                next = right;
            }

            // If no change in smallest, that means we've reached the end successfully
            if(next == smallest) {
                heapified = true;
            }

            // Otherwise swap smallest with the root
            swap(arr[smallest], arr[next]);

            // Continue heapify at new root until heap size is reduced to one
            smallest = next;
            }
    }

    // Step 3.5: Copy sorted elements back into original array
    for(int i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }

    // Free allocated memory for temp array
    delete[] sortedArr;
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

    cout << "Original array:\n";
    printArray(arr, n);
    cout << endl;

    // Call the heapSort function
    heapSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);
    cout << endl;

    return 0;
}