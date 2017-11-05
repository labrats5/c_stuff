#include<stdio.h>
#include<stdlib.h>

void merge(int *A, int lenA, int *B, int lenB, int *C) {
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

void merge_sort(int *A, int lenA) {
	int *L, *R;
	int lenL, lenR, i;
	if (lenA > 1) {
		lenL = lenA / 2;
		lenR = lenA - lenL;

		L = (int *)malloc(lenL * sizeof(int));
		R = (int *)malloc(LenR * sizeof(int));

		for (i=0; i<lenL; i++) L[i] = A[i];
		for (i=0; i<lenR; i++) R[i] = A[i+lenL];

		merge_sort(L, lenL);
		merge_sort(R, lenR);

		merge(L, lenL, R, lenR, A);

		free(L);
		free(R);
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};
	merge_sort(arr, sizeof arr / sizeof(int));
	printf("%d ", arr);
}

/*
 * and this is the strangest life I have ever known
 * waiting for the sun
 * waiting for the sun
 * waiting for the sun
 * can you feel it now that spring has come
 * when its time to live in the scattered sun
 */




