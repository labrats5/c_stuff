#include<stdio.h>
#include<stdlib.h>

void merge (int *A, int lenA, int *B, int lenB, int *C) {
	int i = 0, j = 0, k = 0;
	while (i < lenA && j < lenB) {
		if (A[i] < B[j]) {
			C[k] = A[i];
			i++;
			k++;
		}
		else {
			C[k] = B[j];
			j++;
			k++;
		}
	}
	while (i < lenA) {
		C[k] = A[i];
		i++;
		k++;
	}
	while (j < lenB) {
		C[k] = B[j];
		j++;
		k++;
	}
}

void merge_sort (int *A, int lenA) {
	int *L, *R;
	int lenL, lenR, i;

	if (lenA > 1) {
		lenL = lenA / 2;
		lenR = lenA - lenL;

		L = (int *)malloc(lenL * sizeof(int));
		R = (int *)malloc(lenR * sizeof(int));

		for (i=0; i<lenL; i++) L[i] = A[i];
		for (i=0; i<lenR; i++) R[i] = A[i+lenL];

		merge_sort(L, lenL);
		merge_sort(R, lenR);

		merge(L, lenL, R, lenR, A);

		free(L);
		free(R);
	}
}
