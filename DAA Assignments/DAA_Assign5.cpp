#include <bits/stdc++.h>
using namespace std;

// Deterministic partition function
int partition(int start, int end, vector<int> &arr)
{
    int pivot = arr[start]; // Choose the first element as the pivot
    int i = start + 1;      // Pointer for elements greater than the pivot

    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] < pivot)
        { // Move elements smaller than pivot to the left
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[start], arr[i - 1]); // Place the pivot at its correct position
    return i - 1;                 // Return the index of the pivot
}

// Function to generate a random pivot
int generateRandomPivot(int start, int end)
{
    return start + rand() % (end - start + 1);
}

// Randomized partition function
int randomised_partition(int start, int end, vector<int> &arr)
{
    int pivotIndex = generateRandomPivot(start, end);
    swap(arr[pivotIndex], arr[start]);

    int pivot = arr[start];
    int i = start + 1;
    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[start], arr[i - 1]);
    return i - 1;
}

// Quick Sort function
void quicksort(int start, int end, vector<int> &arr, bool rand)
{
    if (start >= end)
    {
        return;
    }

    int p;
    if (rand)
    {
        p = randomised_partition(start, end, arr);
    }
    else
    {
        p = partition(start, end, arr);
    }

    quicksort(start, p - 1, arr, rand);
    quicksort(p + 1, end, arr, rand);
}

int main()
{
    srand(time(0)); // Seed for random number generation

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size." << endl;
        return 0;
    }

    vector<int> arr(n), arrCopy(n);

    // Taking input for the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Copy the array for comparison
    arrCopy = arr;

    // Quick Sort with deterministic pivot
    cout << "\nSorting using deterministic Quick Sort:" << endl;
    quicksort(0, n - 1, arr, false);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Quick Sort with randomized pivot
    cout << "\nSorting using randomized Quick Sort:" << endl;
    quicksort(0, n - 1, arrCopy, true);
    for (int i = 0; i < n; i++)
    {
        cout << arrCopy[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Enter the size of the array: 5
Enter the elements of the array: 4 1 3 9 7

Sorting using deterministic Quick Sort:
1 3 4 7 9

Sorting using randomized Quick Sort:
1 3 4 7 9
*/
