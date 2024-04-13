#include "binary_trees.h"
#include <stdio.h>

/**
* binary_trees_ancestor - finds the lowest ancestor of two nodes
*
* @first: pointer to the first node
* @second: pointer to the second node
*
* Return: pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *p1, *p2;

	if (first == NULL || second == NULL)
		return (NULL);

	p1 = first;
	while (p1)
	{
		p2 = second;
		while (p2)
		{
			if (p1 == p2)
				return ((binary_tree_t *)p1);
			p2 = p2->parent;
		}
		p1 = p1->parent;
	}
	return (NULL);
}
