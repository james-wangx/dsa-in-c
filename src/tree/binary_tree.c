/**
 * @file binary_tree.c
 * @date 2023-04-12
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Binary tree
 */
#include <stdio.h>
#include <stdlib.h>

#include "tree/binary_tree.h"

struct node {
    ElementType ele;
    Node left;
    Node right;
};

struct tree {
    Node root;
    int size;
};

Node node_init(ElementType ele) {
    Node node = (Node) malloc(sizeof(struct node));
    node->ele = ele;

    return node;
}

Tree tree_init(void) {
    Tree tree = (Tree) malloc(sizeof(struct tree));
    tree->root = (Node) malloc(sizeof(struct node));

    return tree;
}

inline void node_set_left(Node node, Node left) {
    node->left = (Node) malloc(sizeof(struct node));
    node->left = left;
}

inline void node_set_right(Node node, Node right) {
    node->right = (Node) malloc(sizeof(struct node));
    node->right = right;
}

inline void tree_set_root(Tree tree, Node node) {
    tree->root = node;
}

static void __foreach_preorder(Node node) {
    printf("%d ", node->ele);

    if (node->left != NULL)
        __foreach_preorder(node->left);

    if (node->right != NULL)
        __foreach_preorder(node->right);
}

static void __foreach_inorder(Node node) {
    if (node->left != NULL)
        __foreach_inorder(node->left);

    printf("%d ", node->ele);

    if (node->right != NULL)
        __foreach_inorder(node->right);
}

static void __foreach_postorder(Node node) {
    if (node->left != NULL)
        __foreach_postorder(node->left);

    if (node->right != NULL)
        __foreach_postorder(node->right);

    printf("%d ", node->ele);
}

void tree_foreach_preorder(Tree tree) {
    __foreach_preorder(tree->root);
}

void tree_foreach_inorder(Tree tree) {
    __foreach_inorder(tree->root);
}

void tree_foreach_postorder(Tree tree) {
    __foreach_postorder(tree->root);
}