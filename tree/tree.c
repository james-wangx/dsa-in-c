/**
 * @file tree.c
 * @date 2022-03-25
 * @author James Wang (pineapple_cpp@163.com)
 * 
 * @brief The implementation of binary search tree.
 */

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

struct TreeNode {
	int element;
	SearchTree left;
	SearchTree right;
};

/**
 * @brief Make tree empty
 * 
 * @param tree 
 * @return SearchTree 
 */
SearchTree TreeEmpty(SearchTree tree)
{
	if (tree != NULL) {
		TreeEmpty(tree->left);
		TreeEmpty(tree->right);
		free(tree);
	}

	return NULL;
}

/**
 * @brief Find the element's position in tree, implemented with recursion
 * 
 * @param tree 
 * @param element 
 * @return Position 
 */
Position TreeFind(const SearchTree tree, const ElementType element)
{
	if (tree == NULL)
		return NULL;
	if (element < tree->element)
		return TreeFind(tree->left, element);
	else if (element > tree->element)
		return TreeFind(tree->right, element);
	else
		return tree;
}

/**
 * @brief Find the element's position in tree, implement by 'goto' statement
 *
 * @param tree
 * @param element
 * @return Position
 */
static Position __tree_find(SearchTree tree, const ElementType element)
{
top:
	if (tree == NULL)
		return NULL;
	if (element < tree->element) {
		tree = tree->left;
		goto top;
	} else if (element > tree->element) {
		tree = tree->right;
		goto top;
	} else
		return tree;
}

/**
 * @brief Find the minmum element's position in tree, implemented with recursion
 * 
 * @param tree 
 * @return Position 
 */
Position TreeFindMin(const SearchTree tree)
{
	if (tree == NULL)
		return NULL;
	else if (tree->left != NULL)
		return TreeFindMin(tree->left);
	else
		return tree;
}

/**
 * @brief Find the maxmum element's position in tree, implemented with 'while'
 * 
 * @param tree 
 * @return Position 
 */
static Position __tree_find_min(SearchTree tree)
{
	if (tree != NULL)
		while (tree->left != NULL)
			tree = tree->left;

	return tree;
}

/**
 * @brief Find the maxmum element's position in tree, implemented with recursion
 * 
 * @param tree 
 * @return Position 
 */
Position TreeFindMax(const SearchTree tree)
{
	if (tree == NULL)
		return NULL;
	else if (tree->right != NULL)
		return TreeFindMax(tree->right);
	else
		return tree;
}

/**
 * @brief Find the maxmum element's position in tree, implemented with 'while'
 * 
 * @param tree 
 * @return Position 
 */
static Position __tree_find_max(SearchTree tree)
{
	if (tree != NULL)
		while (tree->right != NULL)
			tree = tree->right;

	return tree;
}

/**
 * @brief Insert an element in the tree, and return the root position
 * 
 * @param tree 
 * @param element 
 * @return SearchTree 
 */
SearchTree TreeInsert(SearchTree tree, ElementType element)
{
	if (tree == NULL) {
		// Create and return a one-node tree
		tree = malloc(sizeof(struct TreeNode));
		tree->element = element;
		tree->left = NULL;
		tree->right = NULL;
	} else if (element < tree->element)
		TreeInsert(tree->left, element);
	else if (element > tree->element)
		TreeInsert(tree->right, element);
	// else element is in the tree already, we'll do nothing

	return tree; // Don't forget this line!!!
}

/**
 * @brief Delete an element in the tree
 * 
 * @param tree 
 * @param element 
 * @return SearchTree 
 */
SearchTree TreeDelete(SearchTree tree, const ElementType element)
{
	Position temp_pos;

	if (tree == NULL)
		throw_error("Element not found.");
	else if (element < tree->element)
		TreeDelete(tree->left, element);
	else if (element > tree->element)
		TreeDelete(tree->right, element);
	else if (tree->left && tree->right) { // Tow children
		temp_pos = TreeFindMin(tree->right);
		tree->element = temp_pos->element;
		tree->right = TreeDelete(tree->right, tree->element);
	} else { // One or zero children
		temp_pos = tree;
		if (tree->left == NULL) // Alse handles 0 children
			tree = tree->right;
		else if (tree->right == NULL)
			tree = tree->left;
		free(temp_pos);
	}

	return tree;
}
