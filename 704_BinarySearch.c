/*
* @Author: zero
* @Description: 
* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
* If target exists, then return its index. Otherwise, return -1.
*/

#include <stdio.h>

int search(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1, mid;
	while (left <= right) {
		mid = left + (right - left) / 2;  // 防溢出
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main() {
	int nums[] = {-1, 0, 3, 5, 9, 12};
	int target = 9;
	int numsSize = 6;
	int result = search(nums, numsSize, target);
	printf("%d\n", result);
	return 0;
}