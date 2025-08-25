/*Write a program to perform Quick sort. Display the partial pass-wise sorting done.


Sample Test Cases
Test case 1
number·of·elements:·4	
elements:·5 8 9 4	
Original·array:·5·8·9·4·⏎	
Pass:·4·8·9·5·⏎	
Pass:·5·9·8·⏎	
Pass:·8·9·⏎	
Sorted·array:·4·5·8·9·⏎	
Test case 2
number·of·elements:·6	
elements:·5 1 10 8 9 7	
Original·array:·5·1·10·8·9·7·⏎	
Pass:·5·1·7·8·9·10·⏎	
Pass:·1·5·⏎	
Pass:·8·9·10·⏎	
Pass:·8·9·⏎	
Sorted·array:·1·5·7·8·9·10·⏎*/


//quickSort.c

#include <stdio.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        printf("Pass:");
        for (int i = low; i <= high; i++) {
            printf(" %d", arr[i]);
        }
        printf(" \n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf(" \n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf(" \n");

    return 0;
}
