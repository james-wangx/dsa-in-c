// choicek2.c -- 更好的算法
#include <stdio.h>
#include <limits.h>

// 冒泡排序
void bsort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
        for (int j = i; j < size; j++)
            if (arr[i] < arr[j]) // 降序排序
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main(void)
{
    const int k = 3;
    int ints[] = {-2, 99, 1, -743, 2, INT_MIN, 4};
    // 临时数组，用来存放ints数组的前k个元素
    int temp[k];
    int size = sizeof ints / sizeof *ints;

    for (int i = 0; i < k; i++) // 将ints的前k个元素赋值到temp
        temp[i] = ints[i];

    bsort(temp, k); // 先进行降序排序

    for (int i = 0; i < size - k; i++)
        // 如果ins剩余的元素有比temp中第k个元素大的，则替换第k个元素，并重新排序temp
        if (ints[i + k] > temp[k - 1])
        {
            temp[k - 1] = ints[i + k];
            bsort(temp, k);
        }

    printf("choice k = %d\n", temp[k - 1]);

    return 0;
}
