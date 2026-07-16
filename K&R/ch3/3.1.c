#include <stdio.h>

int binary_search(int x, int m[], int n) {
	int mid;
	int left = 0;
	int right = n - 1;

	while (left < right) {
		mid = (left + right) / 2;

		if (m[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (m[mid] == x) {
		return mid;
	}
	return -1;
}
