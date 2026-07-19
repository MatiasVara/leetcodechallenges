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

int first_and_last(int * a, int len, int target, int * first, int * last) {
	int ret;
	// binary_search always return the first index
	// that satisfies a[i] >= target
	ret = binary_search(a, len, target);
	if (ret < len && a[ret] == target){
		// we get the following value and then 
		// we decrement the index
		int ret2 = binary_search(a, len, target + 1);
		ret2 -= 1;
		*first = ret;
		*last = ret2;
	} else {
		*first = -1;
		*last = -1;
	}
	return 0;
}
