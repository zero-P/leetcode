/*
* @Author: zero
* @Date:   2021-06-30 09:28:54
* @Last Modified time: 2021-06-30 11:13:44
* @Description: Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** matrix = (int**)malloc(sizeof(int*) * n);  //二级指针 matrix
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);  //一级指针 *returnColumnSizes
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);  //一级指针 matrix[i]
        memset(matrix[i], 0, sizeof(int) * n);  //初始化
        (*returnColumnSizes)[i] = n;  //矩阵第 i 列元素的个数
    }
    *returnSize = n;
    int left = 0, right = n - 1, up = 0, down = n - 1;
    int num = 1;
    int i;
    while (left < right && up < down) {
        for (i = left; i < right; i++)
            matrix[up][i] = num++;
        for (i = up; i < down; i++)
            matrix[i][right] = num++;
        for (i = right; i > left; i--)
            matrix[down][i] = num++;
        for (i = down; i > up; i--)
            matrix[i][left] = num++;
        left++;
        right--;
        up++;
        down--;
    }
    if (left == right)
        matrix[left][right] = num;
    return matrix;
}

void print2DArray(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j ++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int* returnSize = (int*)malloc(sizeof(int));
    int** returnColumnSizes = (int**)malloc(sizeof(int*));
    int size = 3;
    print2DArray(generateMatrix(size, returnSize, returnColumnSizes), size);
    return 0;
}