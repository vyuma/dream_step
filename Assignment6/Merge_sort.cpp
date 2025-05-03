/*
What is the time complexity of Merge Sort?
The time complexity of Merge Sort is O(n log n) in all cases (best, average, and worst).
This is because the algorithm always divides the array into two halves and takes linear time to merge them.

What would be the estimated number of key comparisons when the size of the array is 100?
For an array of size n, Merge Sort makes approximately n log₂(n) comparisons.
For n = 100:
Estimated comparisons = 100 * log₂(100) ≈ 100 * 6.64 ≈ 664 comparisons

Compare the estimated number with the x11 that you obtained from Part 1. Are these two numbers pretty close?
The average number of comparisons from the 10 runs (x11) is approximately 619, which is reasonably close to
the theoretical estimate of 664. The slight difference is because the theoretical calculation is an upper bound,
and the actual number can vary depending on the specific distribution of the random numbers in each run.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function prototypes
void mergeSort(int arr[], int temp[], int left, int right, long long &comparisons);
void merge(int arr[], int temp[], int left, int mid, int right, long long &comparisons);
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    const int ARRAY_SIZE = 100; // Size of the array
    const int NUM_RUNS = 10; // Number of runs for averaging
    const int MAX_VALUE = 1000; // Maximum value for random numbers

    int arr[ARRAY_SIZE];
    int temp[ARRAY_SIZE];
    long long totalComparisons = 0; // Total comparisons across all runs
    long long runComparisons[NUM_RUNS]; // Comparisons for the current run

    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation

    // Perform 10 runs of the merge sort
    for (int run = 0; run < NUM_RUNS; run++) {
        generateRandomArray(arr, ARRAY_SIZE);

        long long comparisons = 0;

        mergeSort(arr, temp, 0, ARRAY_SIZE - 1, comparisons);

        runComparisons[run] = comparisons; // Store the number of comparisons for this run
        totalComparisons += comparisons; // Add to the total comparisons

        cout << "#" << (run + 1) << endl;
        cout << setw(12) << runComparisons[run] << " comparisons" << endl;
    }

    double averageComparisons = static_cast<double>(totalComparisons) / NUM_RUNS;
    cout << "Average" << endl;
    cout << setw(12) << fixed << setprecision(0) << averageComparisons << " comparisons" << endl;

    return 0;
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + rand() % 1000; // Generate random numbers between 1 and 1000
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int temp[], int left, int right, long long &comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first half
        mergeSort(arr, temp, left, mid, comparisons);
        // Sort the second half
        mergeSort(arr, temp, mid + 1, right, comparisons);
        // Merge the sorted halves
        merge(arr, temp, left, mid, right, comparisons);
    }
}

void merge(int arr[], int temp[], int left, int mid, int right, long long &comparisons) {
    int i = left; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left; // Starting index to be sorted

    while (i <= mid && j <= right) {
        comparisons++; // Increment comparison count
        if (temp[i] <= temp[j]) {
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid) {
        arr[k++] = temp[i++];
    }

    // Copy remaining elements of right subarray, if any
    while (j <= right) {
        arr[k++] = temp[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i]; // Copy back to the original array
    }
}