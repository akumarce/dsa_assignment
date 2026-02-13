#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* =========================================================
   Sorting Algorithms: Bubble, Selection, Insertion, Merge
   Tracks comparisons and swaps where applicable
   ========================================================= */

// Swap two integers
void swap(int *a, int *b, int *swapCount)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

/* ---------------- Bubble Sort ---------------- */
void bubbleSort(int arr[], int n, int *compCount, int *swapCount)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*compCount)++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], swapCount);
            }
        }
    }
}

/* ---------------- Selection Sort ---------------- */
void selectionSort(int arr[], int n, int *compCount, int *swapCount)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            (*compCount)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[i], &arr[min_idx], swapCount);
    }
}

/* ---------------- Insertion Sort ---------------- */
void insertionSort(int arr[], int n, int *compCount, int *swapCount)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            (*compCount)++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                (*swapCount)++;
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}

/* ---------------- Merge Sort ---------------- */
void merge(int arr[], int l, int m, int r, int *compCount)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        (*compCount)++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortHelper(int arr[], int l, int r, int *compCount)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, compCount);
        mergeSortHelper(arr, m + 1, r, compCount);
        merge(arr, l, m, r, compCount);
    }
}

void mergeSort(int arr[], int n, int *compCount)
{
    mergeSortHelper(arr, 0, n - 1, compCount);
}

/* =========================================================
   Main Function
   - Generates random integers
   - User selects sorting algorithm
   - Prints before/after arrays and comparison/swap counts
   ========================================================= */
int main()
{
    int N;
    printf("Enter number of integers (N): ");
    scanf("%d", &N);

    int arr[N], copy[N];
    srand(time(NULL));

    // Generate random numbers
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 1000 + 1; // [1,1000]
        copy[i] = arr[i];
    }

    printf("\nOriginal Array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    int choice;
    scanf("%d", &choice);

    int compCount = 0, swapCount = 0;

    switch (choice)
    {
    case 1:
        bubbleSort(copy, N, &compCount, &swapCount);
        break;
    case 2:
        selectionSort(copy, N, &compCount, &swapCount);
        break;
    case 3:
        insertionSort(copy, N, &compCount, &swapCount);
        break;
    case 4:
        mergeSort(copy, N, &compCount);
        break;
    default:
        printf("Invalid choice!\n");
        return 0;
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", copy[i]);
    printf("\n");

    printf("Total Comparisons: %d\n", compCount);
    if (choice != 4)
        printf("Total Swaps: %d\n", swapCount);

    return 0;
}
