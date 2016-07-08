/*
 Lab 7 Sorting Algorithms
 Jordan Chalupka 0928258
*/

/*
 The below code was found on 
 https://courselink.uoguelph.ca/d2l/le/content/414492/viewContent/1331517/View
*/
#include "sorting.h"

void swap (int * x, int * y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Iterative Bubble Sort
void bubbleSort (int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n-i-1; j++) {
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

// Recursive Bubble Sort
void rbubbleSort (int a[], int n) {
	for (int j = 0; j < n-1; j++) {
		if (a[j] > a[j+1]) {
			swap(&a[j], &a[j+1]);
		}
	}
	if (n > 2) {
		rbubbleSort(a, n-1);
	}
}
