/**
 * @file test_array_list.c
 * @date 2023-03-13
 * @author James Wang
 * @email james_wangx@163.com
 * @brief 
 */
#include "list/array_list.h"
#include <assert.h>


List test_list_init(void ) {
    List list = list_init(10);
    assert(list->last == -1);
    assert(list->max_size == 10);

    return list;
}


void test_list_add(List list) {
    for (int i = 1; i <= 10; ++i)
        assert(list_add(list, i * 10) == 0);
    assert(list_add(list, 1) == -1);
    assert(list_size(list) == 10);
}


void test_list_del(List list) {
    assert(list_del(list, 1) == -2);
    for (int i = 1; i <= 10; ++i)
        assert(list_del(list, i * 10) == 0);
    assert(list_del(list, 1) == -1);
    assert(list_size(list) == 0);
}


int main(void) {
    List list = test_list_init();
    test_list_add(list);
    test_list_del(list);

    list_clear(list);

    return 0;
}
