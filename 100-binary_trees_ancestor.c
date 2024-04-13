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
binary_tree_t *binary_trees_ancestor(binary_tree_t *first, binary_tree_t *second)
{
	binary_tree_t *p1, *p2;

	p1 = first;
	while (p1)
	{
		p2 = second;
		while (p2)
		{
			printf("p1-> %d p2-> %d\n", p1->n, p2->n);
			if (p1 == p2)
				return (p1);
			p2 = p2->parent;
		}
		p1 = p1->parent;
	}
	return (NULL);
}
