/*1.1.2. Write a Program to Search an element using Binary Search and Recursion

Write a program to search the given element from a list of elements with binary search technique using recursion.

Note: Write the functions read(), bubbleSort(), display() and binarySearch() in Program912a.c

Sample Test Cases
Test case 1
Enter·value·of·n·:·5	
Enter·5·elements·:·33 55 22 44 11	
After·sorting·the·elements·are·:·11·22·33·44·55·⏎	
Enter·key·element·:·11	
The·given·key·element·11·is·found·at·position·:·0⏎	
Test case 2
Enter·value·of·n·:·4	
Enter·4·elements·:·23 67 45 18	
After·sorting·the·elements·are·:·18·23·45·67·⏎	
Enter·key·element·:·24	
The·given·key·element·24·is·not·found⏎	*/

//Program912.c




#include <stdio.h>
#include "Program912a.c"
void main() {
	int a[20], n, key, flag;
	printf("Enter value of n : ");
	scanf("%d", &n);
	read1(a, n);
	bubbleSort(a, n);
	printf("After sorting the elements are : ");
	display(a, n);
	printf("Enter key element : ");
	scanf("%d", &key);
	flag = binarySearch(a, 0, n - 1, key);
	if (flag == -1) {
		printf("The given key element %d is not found\n", key);
	} else {
		printf("The given key element %d is found at position : %d\n", key, flag);
	}
}

// Program912a.c

#include <stdio.h>

void read1(int a[], int n) {
    printf("Enter %d elements : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void bubbleSort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int binarySearch(int a[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] == key) {
        return mid;
    } else if (key < a[mid]) {
        return binarySearch(a, low, mid - 1, key);
    } else {
        return binarySearch(a, mid + 1, high, key);
    }
}
