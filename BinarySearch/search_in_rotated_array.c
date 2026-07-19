#include <stdio.h>


int binary_search_rotated(int * a, int len, int target){
	// the intervale is inclusive
	// because we look for an existing index
	int right = len - 1;
	int left = 0;
	while (left <= right) {
		// ignore overflow for the moment
		int mid = (right + left ) / 2;
		if (a[mid] == target)
			return mid;
		if (a[left] <= a[mid]) {
			// left part is sorted
			if (a[left] <= target && target < a[mid]){
				right = mid - 1;
			} else {
			// target is in the unsorted part, which is the right one
			        left = mid + 1;
			}
		} else {
			// right part is sorted
			// left part is unsorted
			if (a[right] >= target && target > a[mid]){
			    left = mid + 1;
			} else {
			   // target is in the left part
			   right = mid - 1;
			}
		}

	}
	return -1;
}

int main() {
	// array must be monotonic
	int a[4] = {0, 2, 4, 9};
}
