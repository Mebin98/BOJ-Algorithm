// Source from https://www.javatpoint.com/tim-sort

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int RUN = 32;

int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

void insertionSort(int a[], int beg, int end)
{
    int i, j, temp;
    for (i = beg + 1; i <= end; i++) {
        temp = a[i];
        j = i - 1;

        while (j >= beg && temp < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int* LeftArray = (int*)malloc(n1 * sizeof(int));
    int* RightArray = (int*)malloc(n2 * sizeof(int));

    if (!LeftArray || !RightArray) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }

    free(LeftArray);
    free(RightArray);
}

void timSort(int a[], int n)
{
    for (int i = 0; i < n; i += RUN)
        insertionSort(a, i, findMin((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int beg = 0; beg < n; beg += 2 * size)
        {
            int mid = beg + size - 1;
            int end = findMin((beg + 2 * size - 1), (n - 1));

            if (mid < end)
                merge(a, beg, mid, end);
        }
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
}

int main()
{
    int* a = (int*)malloc(1000000 * sizeof(int));
    int arrSize;

    if (!a) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (scanf("%d", &arrSize) != 1) {
        printf("Failed to read array size.\n");
        free(a);
        return 1;
    }

    for (int i = 0; i < arrSize; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Failed to read array element.\n");
            free(a);
            return 1;
        }
    }


    timSort(a, arrSize);
    printArr(a, arrSize);

    free(a);
    return 0;
}