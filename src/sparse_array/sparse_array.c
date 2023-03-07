/**
 * @file sparse_array.c
 * @date 2023-02-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 稀疏数组
 */
#include <stdio.h>
#include <string.h>

#define LINE 10
#define COLUMN 10

int main(void) {
    // 创建原始数组
    int array1[LINE][COLUMN] = {0};
    array1[1][2] = 1;
    array1[2][3] = 2;

    // 统计非 0 元素个数
    int sum = 0;
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            int item = array1[i][j];
            if (item != 0) {
                sum++;
            }
        }
    }

    // 创建稀疏数组
    int sparse_array[sum + 1][3];
    memset(array1, 0, (sum + 1) * 3 * sizeof(int));
    sparse_array[0][0] = 11;
    sparse_array[0][1] = 11;
    sparse_array[0][2] = sum;

    int count = 0;
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            int item = array1[i][j];
            if (item != 0) {
                sparse_array[++count][0] = i;
                sparse_array[count][1] = j;
                sparse_array[count][2] = item;
            }
        }
    }

    // 打印稀疏数组
    printf("稀疏数组\n");
    for (int i = 0; i < sum + 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", sparse_array[i][j]);
        }
        printf("\n");
    }

    // 转为原始数组
    int array2[sparse_array[0][0]][sparse_array[0][1]];
    memset(array2, 0, sizeof(array2));
    for (int i = 1; i < sum + 1; ++i) {
        array2[sparse_array[i][0]][sparse_array[i][1]] = sparse_array[i][2];
    }

    // 打印原始数组
    printf("原始数组\n");
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
