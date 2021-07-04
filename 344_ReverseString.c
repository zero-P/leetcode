/*
* @Author: zero
* @Date:   2021-07-04 19:27:44
* @Last Modified time: 2021-07-04 19:32:43
* @Description: Write a function that reverses a string. The input string is given as an array of characters s.
*/
void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right){
        s[left] ^= s[right];
        s[right] ^= s[left];
        s[left] ^= s[right];
        left++;
        right--;
    }
}
