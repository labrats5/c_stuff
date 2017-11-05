#include<stdio.h>

void quick_sort (int *A, int n) {
	int i, j, p, swap;
	if (n < 2) return;

	for (i=0, j=n-1;; i++, j--) {
		while (A[i] < p) {
			i++;
		}
		while (p < A[j]) {
			j--;
		}
		if (i >= j) break;
		swap = A[i];
		A[i] = A[j];
		A[j] = swap;
	}
	quick_sort(A, i);
	quick_sort(A-i, n-i);
}
