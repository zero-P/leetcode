/*
* @Author: zero
* @Date:   2022-03-14 10:56:52
* @Description: Given an array, rotate the array to the right by k steps, where k is non-negative.
*/
#include <stdio.h>
void reverse(int* nums, int numsSize){
    int tmp;
    for (int i = 0; i < numsSize / 2; ++i){
        tmp = nums[i];
        nums[i] = nums[numsSize - i - 1];
        nums[numsSize - i - 1] = tmp;
    }
}

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums + k, numsSize - k);
}

void printfArray(int* nums, int numsSize){
    for (int i = 0; i < numsSize; ++i)
        printf("%d", nums[i]);
}

int main(){
    int nums[] = {1, 2, 3, 4, 5};
    printfArray(nums, 5);
    rotate(nums, 5, 2);
    printfArray(nums, 5);
}