/*
* @Author: zero
* @Date:   2021-06-23 16:28:18
* @Last Modified time: 2021-07-04 16:44:18
* @Description: 
* Given a non-negative integer x, compute and return the square root of x.
* Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
*/

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;
    /* 二分思想 */
    int left = 0, right = x, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;  // 防溢出
        if (x / mid == mid)
            return mid;
        else if (x / mid > mid)  // 防溢出
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

int main() {
    printf("%d", mySqrt(8));
    return 0;
}
