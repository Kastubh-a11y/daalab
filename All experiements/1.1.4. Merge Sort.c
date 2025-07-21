/*1.1.4. Merge Sort
Write a C program to perform Merge sort. Display the partial pass-wise sorting done.

Sample Test Cases
Test case 1
no·of·elements:·5	
elements:·5 3 7 1 9	
Given·array:⏎	
5·3·7·1·9·⏎	
Pass:·3·5·⏎	
Pass:·3·5·7·⏎	
Pass:·1·9·⏎	
Pass:·1·3·5·7·9·⏎	
Sorted·array:⏎	
1·3·5·7·9·⏎	
Test case 2
no·of·elements:·8	
elements:·8 4 2 7 1 5 3 6	
Given·array:⏎	
8·4·2·7·1·5·3·6·⏎	
Pass:·4·8·⏎	
Pass:·2·7·⏎	
Pass:·2·4·7·8·⏎	
Pass:·1·5·⏎	
Pass:·3·6·⏎	
Pass:·1·3·5·6·⏎	
Pass:·1·2·3·4·5·6·7·8·⏎	
Sorted·array:⏎	
1·2·3·4·5·6·7·8·⏎	
*/



//Merge Sort.c
#include <stdio.h>

void printPass(int arr[], int start, int end) {
    printf("Pass:");
    for (int i = start; i <= end; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    printPass(arr, l, r);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("no of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Given array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
