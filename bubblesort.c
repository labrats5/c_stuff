void bubble_sort (int *A, n) {
	int i, j, swap;
	for (i=0;i<n;i++) {
		for (j=0;j<n-i;j++) {
			if (A[j] > A[j+1]) {
				swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;
			}
		}
	}
}
