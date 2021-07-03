/*
* @Author: zero
* @Date:   2021-07-03 17:32:54
* @Last Modified time: 2021-07-03 17:34:53
* @Description: Given an array of integers nums, calculate the pivot index of this array.
* The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
* If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
* Return the leftmost pivot index. If no such index exists, return -1.
*/
int pivotIndex(int* nums, int numsSize) {
    int sums[numsSize];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        sums[i] = sum;
    }
    for (int i = 0; i < numsSize; i++)
        if (sums[i] - nums[i] == sums[numsSize-1] - sums[i])
            return i;
    return -1;
}