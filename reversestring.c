void reverse_string (unsigned char *A, int n) {
	int i;
	char swap;
	if (n < 2) return;
	for (i=0; i<n/2; i++) {
		swap = A[i];
		A[i] = A[n-i-1];
		A[n-i-1] = swap;
	}
}

void reverse_UTFstring (unsigned char *A, int n) {
	int i, letlenj;
	unsigned char *temp;
	temp = (unsigned char *)malloc(n);

	for (i=0; i<n; i++) {
		letlen = 1;
		while (A[n-i-1] >> 6 == (unsigned char)2) {
			i++;
			letlen++;
		}

