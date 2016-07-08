// Jordan Chalupka 0928258
#include "testing.h"
int * createArray (int min, int max, int size) {
	//Generate random number arrays
	int * array = malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) {
		//Generate random numbers
		array[i] = rand()%(max+1-min)+min;
	}
	return array;
}

void printArray (int * array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ",array[i]);
	}
	printf("\n");
}

float elapsedTime (sortFunction function, int * array, int size) {
	clock_t start, stop;
	start = clock();
	function(array, size);
	stop = clock();

	double diff = ((double)(stop-start)/ CLOCKS_PER_SEC)*1000;
	return diff;
}


void testSorting (int min, int max, int size) {
	int * array = createArray(min, max, size);
	
	float diff = elapsedTime(bubbleSort, array, size);
	float diff2 = elapsedTime(rbubbleSort, array, size);

	printf("Array Values: min: %d max: %d size: %d\n"
	       "Bubble Sort:\t\t %lf ms\n"
	       "Recursive Bubble Sort:\t %lf ms\n"
	       "########################################\n",min,max,size,diff, diff2);
}

int main (void) {
	// Seed random number generator
	srand(time(NULL));

	// Binary Sort
	printf("Sorting Binary Numbers\n");
	testSorting(0, 1, 1000);

	// Binary Sort Big
	printf("Sorting Lots of Binary Numbers\n");
	testSorting(0, 1, 10000);

	// Medium Gap Sort
	printf("Sorting Medium Sized Numbers\n");
	testSorting(0,100, 1000);

	// Medium Gap Sort Big
	printf("Sorting Lots of Medium Sized Numbers\n");
	testSorting(0, 100, 10000);

	// Large Gap Sort
	printf("Sorting Large Sized Numbers\n");
	testSorting(0, 10000,1000);

	// Large Gap Sort Big
	printf("Sorting Lots of Large Sized Numbers\n");
	testSorting(0, 10000,10000);

	// Test Largest Size Handleable
	printf("Warning: Testing very large array. May become unresponsive.\n");
	printf("Testing very large array\n");
	testSorting(0,1000,100000);
}
