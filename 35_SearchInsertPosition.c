/*
* @Author: zero
* @Description: 
* Given a sorted array of distinct integers and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;  //防溢出
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1; 
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 7;
    int numsSize = 4;
    int result = searchInsert(nums, numsSize, target);
    printf("%d\n", result);
    return 0;
}

