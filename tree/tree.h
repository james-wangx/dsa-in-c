/**
 * @file tree.h
 * @date 2022-03-25
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Declaration of binary search tree.
 */

#ifndef _DSAA_TREE_H
#define _DSAA_TREE_H

#include <stdio.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree TreeEmpty(SearchTree tree);
SearchTree TreeInsert(SearchTree tree, const ElementType element);
SearchTree TreeDelete(SearchTree tree, const ElementType element);
Position TreeFind(const SearchTree tree, const ElementType element);
Position TreeFindMin(const SearchTree tree);
Position TreeFindMax(const SearchTree tree);
ElementType TreeRetrieve(Position pos);

#define throw_error(str) fprintf(stderr, "%s\n", str)

#endif // _DSAA_TREE_H
