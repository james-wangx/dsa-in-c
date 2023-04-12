/**
 * @file test_binary_tree.c
 * @date 2023-04-12
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Test binary tree
 */
#include <stdio.h>

#include "tree/binary_tree.h"

int main(void) {
    Node node1 = node_init(1);
    Node node2 = node_init(2);
    Node node3 = node_init(3);
    Node node4 = node_init(4);
    Node node5 = node_init(5);
    Node node6 = node_init(6);
    Tree tree = tree_init();

    node_set_left(node1, node2);
    node_set_right(node1, node3);
    node_set_left(node2, node4);
    node_set_right(node2, node5);
    node_set_left(node3, node6);
    tree_set_root(tree, node1);

    tree_foreach_preorder(tree);
    printf("\n");
    tree_foreach_inorder(tree);
    printf("\n");
    tree_foreach_postorder(tree);

    return 0;
}
