/*
* @Author: zero
* @Date:   2021-06-29 14:34:44
* @Last Modified time: 2021-06-29 15:02:22
* @Description: 
* Given an array of positive integers nums and a positive integer target, return the minimal length of
* a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target.
* If there is no such subarray, return 0 instead.
*/

#include <stdio.h>
#include <math.h>

int minSubArrayLen(int target, int* nums, int numsSize){
	if (numsSize == 0)
        return 0;
	int start = 0;
	int minLen = numsSize + 1;
	int sum = 0;
	for (int end = 0; end < numsSize; end++) {
		sum += nums[end];
		while (sum >= target) {
			minLen = fmin(minLen, end - start + 1);
			sum -= nums[start++];
		}
	}
	return minLen == numsSize + 1 ? 0 : minLen;
}

int main(){
	int nums[] = {1,3,5,7,9};
	printf("%d", minSubArrayLen(16, nums, 5));
	return 0;
}
