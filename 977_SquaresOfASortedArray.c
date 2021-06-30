/*
* @Author: zero
* @Date:   2021-06-28 22:42:32
* @Last Modified time: 2021-06-30 11:29:57
* @Description: 
* Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/

#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int left = 0, right = numsSize - 1;
	int* res = (int*)malloc(sizeof(int)*numsSize);
	int pos = numsSize - 1;
	while (left <= right) {
		if (nums[left] * nums[left] > nums[right] * nums[right]) {
			res[pos--] = nums[left] * nums[left];
			left++;
		}
		else {
			res[pos--] = nums[right] * nums[right];
			right--;
		}
	}
	*returnSize = numsSize;
	return res;
}

void printfArray(int* nums, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", nums[i]);
}

int main() {
	int a[] = {-2, -1, -1, 0, 3, 4};
	int numsSize = 6;
	int* returnSize = (int*)malloc(sizeof(int));
	printfArray(sortedSquares(a, numsSize, returnSize), numsSize);
	return 0;
}
