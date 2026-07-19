#include <stdio.h>


// find the first index that satisfies
// a[i] >= target
int binary_search(int * a, int len, int target){
	int right = len;
	int left = 0;
	while (left < right) {
		int mid = (right + left) / 2;
		if (a[mid] >= target) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	// left contains the first index 
	// in which the condition begins to be true
	return left;
}

int search(int * a, int n, int target) {
	int ret = binary_search(a, n, target);

	if (ret < n && a[ret] == target){
		return ret;
	} else {
		return -1;
	}
}
