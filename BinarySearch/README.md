# Binary Search Exercises

## Classical Algorithm 
The classic binary search algorithm is: given a sorted array a[] of N
elements, i.e. monotonic, and a target t, find the index i such that
i is the first index that satisfies a[i] >= target. The condition is the
predicate, and it holds that the predicate is false for all a[j] such that
`j<i`. And it holds that the predicate is always true for all k such that
k>=i. The algorithm returns the index i such that, if the target exists, i is
the target's position, otherwise i is the value where the target should be
inserted if it existed. This way the return range is [0, N]; when
the target is outside the interval, the algorithm returns N, i.e. a
position outside the array, which goes up to N-1. 

```c
int binary_search (int * a, int len, int target) {
    // search in the [0, right) interval
    // len value is not included in the
    // possibles answers
    int left = 0;
    int right = len;
    while (left < right) {
        int mid = (right + left) / 2;
        if (a[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    // left contains the first index
    // in which the predicates holds
    return left;
}
```

## Checking existence
The algorithm returns the position where the target should be inserted; to
indicate whether the target exists we can define the following function that
returns -1 if the target does not exist, or the position if it exists.


```c
int search(int * a, int len, int target){
    int ret;
    ret = binary_search(a, len, target);
    if (ret < len && a[ret] == target) {
        return ret;
    } else {
       return -1;
    }
}
```

## Right boundary
The `binary_search()` function returns i such that i is the first index that
satisfies `a[i] >= target` (including duplicates), therefore all k <
i, i.e. from 0..i-1, are less than a[i]. The number of elements
strictly less than i is then i, from 0 to i-1, which is the
return value of the function.  

## First and last occurrence
Use binary_search() with target, which gives you the first occurrence, and
then with target+1. One is subtracted from the position of target+1, and
that is the position of the last occurrence of target.

```c
int first_and_last(int * a, int len, int target, int * first, int * last) {
    int ret = binary_search(a, len, target);
    if (ret < len && a[ret] == target) {
        int ret2 = binary_search(a, len, target +1);
        ret2 -= 1;
        *first = ret;
        *last = ret2;
        return 0;
    }
    *first = -1;
    *last = -1;
    return 0;
}

```
## Search on answer
This is an optimization problem. The problem asks that, given a number N of
days, we find the minimum capacity that allows that distribution. Given an
array of N values, each value is the weight of a package. The distribution
order of these packages cannot be altered. The capacity indicates the total
weight per day that can be supported. The capacity is constant per day.
For a given array of N weights and a number of days, the minimum value of C
lies between max(weights[]) < Copt < Sum(weights[]). We have to find the
minimum value in that range that allows the distribution for a given number
of days. If we fix the days, the values of C are monotonic. For a given
number of days, there exists a C such that for all C'>C, the distribution
can also occur.
This problem is split into two parts:
1. A feasibility function that returns true if, for a given C and days, the
   distribution is possible.
2. Binary search using the feasibility function as the predicate
  
```c
bool feasible (int * pesos, int n, int c, int days) {

    int count_days = 1;
    int sum = 0 ;

    for (int j=0; j< n; j++){
        if (pesos[j] > c)
            return false;
        if (pesos[j] + sum > c) {
            count_days += 1;
            sum = pesos[j];
        } else {
            sum += pesos[j];
        }
    }
    
    return  count_days <= days;
}

```
The modification to binary_search is the following:

```c
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
```

##  Rotated sorted array
In this problem, the target is searched for in a sorted array that has been
rotated. Unlike the classic algorithm, here we search for a particular value,
so the intervals are inclusive. The same procedure is followed, calculating
left, right and mid, and then checking which interval is sorted. To do this
we check whether a[left] <= a[mid]; in that case the left interval is
sorted. Otherwise, the right one is sorted. Then, within the sorted
interval, we check whether target lies in a[mid] <= target <
a[right] (right side) or a[left] <= target < a[mid] (left side). If these
conditions are not met, target is in the unsorted side. left or
right is recalculated depending on where target is. mid is discarded from the interval.
```c
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
```
## Minimum Size Subarray Sum
Given an array of positive numbers and a target value, find the minimum
subarray whose element sum is equal to or greater than target. If it does
not exist, return 0. This problem can be solved using binary_search over the
possible values of the length. The interval containing the possible values
of the length is monotonic. If there is a value L that satisfies that the
sum of its elements is greater than or equal to target, adding one more
element will only make the sum increase, since all elements are positive
integers. We can use binary_search with a feasibility function that returns
true if there exists a subarray of length L that satisfies that the sum is
>= target. The range of tested values is then [1, NumSize + 1): 
```c
bool feasible(int target, int * nums, int numsSize, int len){
    int sum=0;
    for (int j=0; j < len; j++){
        sum +=nums[j];
    }

    if (sum >= target)
        return true;

    int last = len;
    int start = 0;
    while (last < numsSize) {
        sum -= nums[start];
        start++;
        sum += nums[last];
        last++;

        if (sum >= target)
            return true;
    }

    return false;
}
```
```c
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 1;
    int right = numsSize + 1; // numsSize is a valid solution
    // so it is inclusive

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (feasible(target, nums, numsSize, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return (left == numsSize + 1) ? 0 : left;
}
```
This exercise is a variation of the optimization one done previously.
