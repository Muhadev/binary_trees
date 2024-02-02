#include "binary_trees.h"
/**
 * binary_tree_height_d - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree. If tree is NULL, return 0.
 */
size_t binary_tree_height_d(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height_d(tree->left);
	right_height = binary_tree_height_d(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}
/**
 * binary_tree_size_d - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the binary tree. If tree is NULL, return 0.
 */
size_t binary_tree_size_d(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size_d(tree->left) + binary_tree_size_d(tree->right) + 1);
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);
	height = binary_tree_height_d(tree);
	size = binary_tree_size_d(tree);
	return (size == (size_t)((1 << (height + 1)) - 1));
}
