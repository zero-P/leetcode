/*
* @Author: zero
* @Date:   2021-07-02 20:14:42
* @Last Modified time: 2021-07-04 16:42:09
* @Description: Given an integer array nums, find the contiguous subarray (containing at least one number)
* which has the largest sum and return its sum.
*/

int maxSubArray(int* nums, int numsSize) {
    int ans = nums[0];
    int sum = nums[0], pre = 0;
    for (int i = 1; i < numsSize; i++) {
        pre = pre < sum ? pre : sum;
        sum += nums[i];
        ans = sum - pre > ans ? sum - pre : ans;
    }
    return ans;
}