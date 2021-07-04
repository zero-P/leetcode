/*
* @Author: zero
* @Date:   2021-07-02 17:06:11
* @Last Modified time: 2021-07-04 16:46:31
* @Description: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>

struct hashtable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashtable *set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashtable *tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (!tmp) {
            tmp = (struct hashtable*)malloc(sizeof(struct hashtable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else
            return true;
    }
    return false;
}

int main() {
    int nums[] = {1, 1, 2, 3};
    int size = 4;
    if (containsDuplicate(nums, size))
        printf("y");
    else
        printf("n");
    return 0;
}
