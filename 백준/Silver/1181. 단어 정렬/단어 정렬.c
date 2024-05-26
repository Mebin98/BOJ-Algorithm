// Source from https://www.javatpoint.com/tim-sort

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int RUN = 32;

int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

void insertionSort(char** arr, int beg, int end)
{
    for (int i = beg + 1; i <= end; i++) {
        char* temp = arr[i];
        int j = i - 1;
        while (j >= beg && (strlen(arr[j]) > strlen(temp) ||
            (strlen(arr[j]) == strlen(temp) && strcmp(arr[j], temp) > 0))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void merge(char** arr, int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    char** LeftArray = (char**)malloc(n1 * sizeof(char*));
    char** RightArray = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) {
        LeftArray[i] = arr[beg + i];
    }
    for (int j = 0; j < n2; j++) {
        RightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2) {
        if (strlen(LeftArray[i]) < strlen(RightArray[j]) ||
            (strlen(LeftArray[i]) == strlen(RightArray[j]) && strcmp(LeftArray[i], RightArray[j]) <= 0)) {
            arr[k] = LeftArray[i];
            i++;
        }
        else {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }

    free(LeftArray);
    free(RightArray);
}

void timSort(char** arr, int n)
{
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, findMin((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int beg = 0; beg < n; beg += 2 * size) {
            int mid = beg + size - 1;
            int end = findMin((beg + 2 * size - 1), (n - 1));
            if (mid < end)
                merge(arr, beg, mid, end);
        }
    }
}

void printArr(char** arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char** arr = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(51 * sizeof(char));
        scanf("%s", arr[i]);
    }

    timSort(arr, n);

    char** uniqueArr = (char**)malloc(n * sizeof(char*));
    int uniqueCount = 0;

    uniqueArr[uniqueCount++] = arr[0];
    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) != 0) {
            uniqueArr[uniqueCount++] = arr[i];
        }
    }

    printArr(uniqueArr, uniqueCount);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(uniqueArr);

    return 0;
}