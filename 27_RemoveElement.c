/*
* @Author: zero
* @Date:   2021-06-26 10:56:36
* @Last Modified time: 2021-06-26 11:06:03
* @Description: 
* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
* The relative order of the elements may be changed.
* Return k after placing the final result in the first k slots of nums.
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
	int slow = 0;
	for (int fast = 0; fast < numsSize; ++fast){
		if (val != nums[fast])
			nums[slow++] = nums[fast];
	}
	return slow;
}

int main(){
	int nums[] = {2};
	printf("%d\n", removeElement(nums, 1, 0));
	return 0;
}
