/*
* @Author: zero
* @Date:   2021-06-26 14:45:27
* @Last Modified time: 2021-06-26 15:15:35
* @Description: 
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
*/

#include <stdio.h>

/*我的解法*/
void moveZeroes1(int* nums, int numsSize){
	if(numsSize){
		int slow = 0;
		for (int fast = 0;fast < numsSize;fast ++){
			if (nums[fast])
				nums[slow++] = nums[fast];
	
	}
		while(slow < numsSize)  //覆盖
			nums[slow++] = 0;
	}
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

/*官解*/
void moveZeroes2(int *nums, int numsSize) {
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right]) {
            swap(nums + left, nums + right);  //交换
            left++;
        }
        right++;
    }
}

/*两种解法各有优劣*/ 

int main(){
	int nums[] = {0};
	int numsSize = 1;
	moveZeroes2(nums, numsSize);
	for (int i = 0; i < numsSize; ++i)
		printf("%d\n", nums[i]);
	return 0;
}