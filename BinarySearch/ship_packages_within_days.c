#include <stdio.h>
#include <stdbool.h>

bool feasible(int * pesos, int n, int c, int days) {
	int s = 0;
	int count_days = 1;

	// count the days that we require
	// for a given c and pesos[]
	for (int i=0; i<n; i++){
		// false if one weight is
		// more than c
		if (pesos[i] > c)
			return false;
		// if current weitgh does
		// not fit in a day move to
		// the next one
		if (pesos[i] + s > c) {
			s = pesos[i];
			count_days += 1;
		// keeping cummulating weights
		} else {
			s += pesos[i];
		}
	}

	// if we require more days that asked
	// just return false
	return count_days <= days;

}

int binary_search_with_days(int * pesos, int n, int days){
	int right = 0;
	int left = pesos[0];
	
	// calculate max and sum
	for (int i=0; i<n; i++){
		if (pesos[i] > left)
			left = pesos[i];
		right += pesos[i];
	}

	// include sum() in the range
	// since the search must be between
	// [max, sum + 1)
	right++;

	while (left < right) {
		// TODO: this may overflow
		// replace with
		// left - left / 2 + right / 2 
		int mid = (right + left) / 2;
		// if featible is true in mid
		// it is true for all C <= mid
		if (feasible(pesos, n, mid, days)) {
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
}
