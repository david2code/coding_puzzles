#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int merge(int vector[][2], int size)
{
	struct node{
		struct node *prev;
		struct node *next;
		int start;
		int end;
	};


	struct node *head = NULL;

	int i, j;

	for (i = 0; i < size; i++)
	{
		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));
			head->prev = NULL;
			head->next = NULL;
			head->start = vector[i][0];
			head->end = vector[i][1];
		} 
		else
		{
			struct node *p_node = head;
			struct node *p_prev= head;
			while(p_node)
			{
				if (vector[i][1] < p_node->start)
				{
					struct node *p_new = (struct node *)malloc(sizeof(struct node));
					p_new->start = vector[i][0];
					p_new->end = vector[i][1];
					p_new->prev = NULL;
					p_new->next = NULL;

					if (p_node->prev == NULL)
					{
						head = p_new;
						p_new->next = p_node;
						p_node->prev = p_new;
					}
					else
					{
						p_node->prev->next = p_new;
						p_new->prev = p_node->prev;
						p_new->next = p_node;
						p_node->prev = p_new;
						
					}
					break;
				}
				else if (vector[i][0] > p_node->end)
				{
						
				}
				else
				{
					p_node->start = p_node->start < vector[i][0] ? p_node->start : vector[i][0];
					p_node->end = p_node->end > vector[i][1] ? p_node->end : vector[i][1];
					break;
				}

				p_prev = p_node;
				p_node = p_node->next;
			}
			
			if (p_node == NULL)
			{
				p_node = p_prev;
					struct node *p_new = (struct node *)malloc(sizeof(struct node));
					p_new->start = vector[i][0];
					p_new->end = vector[i][1];
					p_new->prev = NULL;
					p_new->next = NULL;

					if (p_node->next == NULL)
					{
						
						p_new->prev = p_node;
						p_node->next = p_new;
					}
					else
					{
						p_new->next = p_node->next;
						p_node->next->prev = p_new;
						p_new->prev = p_node;
						p_node->next = p_new;
					}
			}
		}
	}

	struct node *p_node = head;
	while(p_node)
	{
		printf("[%d,%d],", p_node->start, p_node->end);
		p_node = p_node->next;
	}
	printf("\n");
	return 0;
}

int main()
{
	int vector[][2] = {
		{1,3},
		{2,6},
		{8,10},
		{15,18}
	};

	
	int size = sizeof(vector) / (2 * sizeof(int));

	int i;
	for (i = 0; i < size; i++)
	{
		printf("[%d,%d],", vector[i][0], vector[i][1]);
	}
	printf("\n");
	int ret = merge(vector, size);
	printf("%d", ret);
	return 0;
}
