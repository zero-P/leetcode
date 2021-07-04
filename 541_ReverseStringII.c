/*
* @Author: zero
* @Date:   2021-07-04 19:42:41
* @Last Modified time: 2021-07-04 20:09:29
* @Description: Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
* If there are fewer than k characters left, reverse all of them.
* If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
*/
char* reverseStr(char* s, int k) {
    char *p = s;
    int len = 0;
    while (*p) {
        len++;
        p++;
    }
    int left, right;
    for (int i = 0; i * 2 * k < len; i++) {
        left = i * 2 * k;
        right = (left + k - 1) > (len - 1) ? (len - 1) : (left + k - 1);
        while (left < right) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];
            left++;
            right--;
        }
    }
    return s;
}