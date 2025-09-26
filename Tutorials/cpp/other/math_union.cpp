int divide_bad(int n, int d) {
	return n / d;
}

int divide_worse(int n, int d) {
	if (d == 0) {
		return -1;
	}

	return n / d;
}

int+Error divide(int n, int d) {
	if (d == 0) {
		return Error{DivByZero};
	}

	return n / d;
}
