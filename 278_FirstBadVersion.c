/*
* @Author: zero
* @Date:   2022-03-08 11:03:20
* @Description: 
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n, middle;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}