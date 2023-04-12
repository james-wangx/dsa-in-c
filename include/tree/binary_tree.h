/**
 * @file binary_tree.h
 * @date 2023-04-10
 * @author James Wang
 * @email james_wangx@163.com
 * @brief Binary tree
 */
#ifndef DSA_BINARY_TREE_H
#define DSA_BINARY_TREE_H

typedef int ElementType;
typedef struct node *Node;
typedef struct tree *Tree;

Node node_init(ElementType ele);
Tree tree_init(void);
void node_set_left(Node node, Node left);
void node_set_right(Node node, Node right);
void tree_set_root(Tree tree, Node node);
void tree_foreach_preorder(Tree tree);
void tree_foreach_inorder(Tree tree);
void tree_foreach_postorder(Tree tree);

#endif // DSA_BINARY_TREE_H