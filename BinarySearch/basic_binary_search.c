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

int main() {
	// array must be monotonic
	int a[4] = {0, 2, 4, 9};

	int ret = binary_search(a, 4, 10);

	// the function can return len index 
	// which is not in the array thus indicating
	// that the target is bigger than all the numbers
	// that case is always not found
        if (ret < 4 && a[ret] == 10){
		printf("found\n");
	} else {
		printf("not found: %d\n", ret);
	}
}
