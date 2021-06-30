/*
* @Author: zero
* @Date:   2021-06-24 12:23:36
* @Last Modified time: 2021-06-30 11:26:20
* @Description: 
* Given a positive integer num, write a function which returns True if num is a perfect square else False.
*/

#include <stdio.h>

bool isPerfectSquare(int num) {
	if (num == 0 || num == 1)
		return true;
	int left = 0, right = num, mid;
	while (left <= right){
		mid = left + (right - left) / 2;
		if (num / mid == mid && num % mid == 0)
			return true;
		else if (num / mid > mid)
			left = mid + 1;
		else if (num / mid < mid)
			right = mid - 1;
		else
			return false;
	}
	return false;
}

int main() {
	isPerfectSquare(2) ? printf("T") : printf("F");
	return 0;
}
