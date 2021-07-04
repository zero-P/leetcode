/*
* @Author: zero
* @Date:   2021-06-26 11:14:49
* @Last Modified time: 2021-06-30 11:22:57
* @Description: 
* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
* such that each unique element appears only once. The relative order of the elements should be kept the same.
* Return k after placing the final result in the first k slots of nums.
*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[slow] != nums[fast])
            nums[++slow] = nums[fast];
    }
    return slow + 1;
}

int main() {
    int nums[] = {};
    printf("%d\n", removeDuplicates(nums, 0));
    return 0;
}
