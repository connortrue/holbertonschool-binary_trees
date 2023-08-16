#include "binary_tree.h"
#include "binary_trees.h"
/**
 * enqueue - Add an element to the queue
 * @queue: Pointer to the queue
 * @data: Pointer to the data to be added
 */
void enqueue(queue_t **queue, void *data)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return;

	new_node->data = data;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = malloc(sizeof(queue_t));
		if (*queue == NULL)
		{
			free(new_node);
			return;
		}
		(*queue)->front = new_node;
		(*queue)->rear = new_node;
	}
	else
	{
		(*queue)->rear->next = new_node;
		(*queue)->rear = new_node;
	}
}

/**
 * dequeue - Remove and return the front element of the queue
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the data of the front element, or NULL if the queue is
 * empty
 */
void *dequeue(queue_t **queue)
{
	void *data;
	queue_node_t *temp;

	if (*queue == NULL || (*queue)->front == NULL)
		return (NULL);

	temp = (*queue)->front;
	data = temp->data;

	(*queue)->front = (*queue)->front->next;
	if ((*queue)->front == NULL)
		(*queue)->rear = NULL;

	free(temp);
	return (data);
}

/**
 * queue_size - Get the number of elements in the queue
 * @queue: Pointer to the queue
 *
 * Return: The number of elements in the queue
 */
size_t queue_size(const queue_t *queue)
{
	size_t count = 0;
	queue_node_t *current = queue->front;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	const binary_tree_t *current;
	queue_t *queue = NULL;

	if (tree == NULL)
		return (0);

	enqueue(&queue, (void *)tree);

	while (queue != NULL)
	{
		size_t level_size = queue_size(queue);
		size_t i;

		for (i = 0; i < level_size; i++)
		{
			current = (const binary_tree_t *)dequeue(&queue);

			if (current->left != NULL)
				enqueue(&queue, (void *)current->left);
			if (current->right != NULL)
				enqueue(&queue, (void *)current->right);
		}

		height++;
	}

	return (height - 1);
}
