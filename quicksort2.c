void quicksort(int *A, int c) {
	int i, j, p, swap;
	if (c<2)
		return;
	p = c/2;
	for (i=0, j=c-1;; ++i, --j) {
		while (A[i] < A[p]) {
			++i;
		}
		while (A[j] > A[p]) {
			--j;
		}
		if (i>=j)
			break;
		swap = A[i];
		A[i] = A[j];
		A[j] = swap;
	}
	quicksort(A, i);
	quicksort(A+i, c-i);
}

void merge(int *L, int lenL, int *R, int lenR, int *out) {
	int i, j, k;
	while (i < lenL && j < lenR) {
		if (L[i] < R[j]) {
			out[k] = L[i];
			++i;
			++k;
		}
		else {
			out[k] = R[j];
			++j;
			++k;
		}
	}
	while (i < lenL) {
		out[k] = L[i];
		++i;
		++k;
	}
	while (j < lenR) {
		out[k] = R[j];
		++j;
		++k;
	}
}

void mergesort(int *A, int c) {
	int i, lenL, lenR;
	int *L, *R;
	if (c<2)
		return;
	lenL = c/2;
	lenR = c - lenL;
	L = (int *)malloc(lenL * sizeof(int));
	R = (int *)malloc(lenR * sizeof(int));
	for (i=0; i<lenL; ++i) {L[i] = A[i];}
	for (i=0; i<lenR; ++i) {R[i] = A[i+lenL];}
	mergesort(L, lenL);
	mergesort(R, lenR);
	merge(L, lenL, R, lenR, A);
	free(L);
	free(R);
	char thing[5] = "hello";
}
