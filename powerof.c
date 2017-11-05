int isPowerOfTwo (unsigned int n) {
	return (n != 0 && !(n & (n-1)));
}

int isPowerOfFour (unsigned int n) {
	if (n == 0 || n & (n-1)) return 0;
	while (n > 1) {
		n >>= 2;
	}
	return n;
}
