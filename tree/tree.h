/**
 * @file tree.h
 * @date 2022-03-25
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief Declaration of binary search tree.
 */

#ifndef _DSAA_TREE_H
#define _DSAA_TREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree TreeEmpty(SearchTree tree);
SearchTree TreeInsert(SearchTree tree, const int element);
SearchTree TreeDelete(SearchTree tree, const int element);
Position   TreeFind(const SearchTree tree, const int element);
Position   TreeFindMin(const SearchTree tree);
Position   TreeFindMax(const SearchTree tree);
int		   TreeRetrieve(Position pos);

#endif // _DSAA_TREE_H
