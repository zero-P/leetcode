/*
* @Author: zero
* @Date:   2022-03-14 19:10:43
* @Description: 找出数组中任一重复的数字
*/
#include <stdio.h>

int findRepeatNumber(int* nums, int numsSize){
    int i = 0, tmp;
    while (i < numsSize){
        if (nums[i] == i){
            i++;
            continue;
        }
        if (nums[nums[i]] == nums[i])
            return nums[i];
        tmp = nums[nums[i]];
        nums[nums[i]] = nums[i];
        nums[i] = tmp;
    }
    return numsSize;
}

int main(){
    int nums[] = {1, 2, 2, 4, 4};
    printf("%d", findRepeatNumber(nums, 5));
}