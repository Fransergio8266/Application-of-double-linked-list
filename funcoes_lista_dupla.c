#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista_dupla.h"



void push_begin(struct List **n,int x)
{
struct List * neo = (struct List *) malloc(sizeof(struct List));
if(neo==NULL)
	{
	printf("\nNode alocation fail\n");
	return;
	}

neo->value = x;
neo->next = *n;
neo->last = NULL;
if(*n != NULL)
	{
	(*n)->last = neo;
	}
*n = neo;
}

void push_end(struct List **n, int x)
{
struct List * neo = (struct List *) malloc(sizeof(struct List));
if(neo==NULL)
	{
	printf("\nNode allocation fail\n");return;
	}

neo->value = x;
neo->next = NULL;
if(*n == NULL)
	{
	neo->last = NULL;
	*n =  neo;
	}
else
	{
	struct List * aux = *n;
	while(aux->next != NULL)
		{
		aux = aux->next;
		}
	neo->last = aux;
	aux->next = neo;
	}

}

void push_middle(struct List **n, int x, int before)
{
struct List * neo = (struct List *) malloc(sizeof(struct List));
if(neo==NULL)
	{
	printf("\nNode allocation fail\n");return;
	}
neo->value = x;

if(*n==NULL)
	{
	neo->next = NULL;
	neo->last = NULL;
	*n = neo;
	}

else
	{
	struct List * aux = *n;
	while((aux->value != before) && (aux->next))
		{
		aux=aux->next;
		}
	if(aux->next)
		{
		aux->next->last = neo;
		}
	neo->next = aux->next;
	neo->last = aux;
	aux->next = neo;
	}
}

void ordered_up_push(struct List **n, int x)
{
struct List * neo = (struct List *) malloc(sizeof(struct List));
if(neo==NULL)
        {
        printf("\nNode allcation fail\n");
	return;
        }
neo->value = x;

if(*n==NULL)
        {
        neo->next = NULL;
        neo->last = NULL;
        *n = neo;
	return;
        }

else
        {
	struct List * aux = *n;
	 if(x <= aux->value)
                { 
                neo->next = aux;
		aux->last = neo;
		neo->last = NULL;
		*n = neo;
		return;
                }

        while(aux->next && (x > aux->next->value))
		{
		aux = aux->next;
		}
	if(aux->next)
		{
		aux->next->last = neo;
		}
	neo->next = aux->next;
	aux->next = neo;
	neo->last =  aux;
	}
}

void ordered_down_push(struct List **n, int x)
{
struct List * neo = (struct List *) malloc(sizeof(struct List));
if(neo==NULL)
        {
        printf("\nNode allocation fail\n");
        return;
        }
neo->value = x;

if(*n==NULL)
        {
        neo->next = NULL;
        neo->last = NULL;
        *n = neo;
        return;
        }

else
        {
        struct List * aux = *n;
         if(x >= aux->value)
                { 
                neo->next = aux;
                aux->last = neo;
                neo->last = NULL;
		*n = neo;
                return;
                }

        while(aux->next && (x < aux->next->value))
                {
                aux = aux->next;
                }
        if(aux->next)
                {
                aux->next->last = neo;
                }
        neo->next = aux->next;
        aux->next = neo;
        neo->last =  aux;
        }
}

void print(struct List **n)
{
struct List * aux = *n;
if(*n==NULL)
	{
	printf("\nEmpty List\n");return;
	}

printf("\nList from begining to end:\n");
while(aux)
	{
	printf("\n%d\n",aux->value);
	if(aux->next)
		{
		aux = aux->next;
		}
	else
		{
		break;
		}
	}
printf("\nList from end to begining:\n");
while(aux)
        {
        printf("\n%d\n",aux->value);
        if(aux->last)
                { 
                aux=aux->last;
                }
        else
                { 
                break;
                }
        }
}

void pop_only_at_begin(struct List **n)
{
if(*n==NULL)
	{
	printf("\nEmpty List\n");return;
	}
struct List * aux = *n;
*n = (*n)->next;
(*n)->last = NULL;
free(aux);
}

void pop_only_at_end(struct List **n)
{
if(*n==NULL)
        {
        printf("\nEmpty List\n");return;
        }
struct List * aux = *n;
struct List * f_node = *n;
while(aux->next)
	{
	aux = aux->next;
	}
(*n) = aux;
(*n) = (*n)->last;
(*n)->next = NULL;
free(aux);
*n = f_node;
}

void pop_any_node(struct List **n,int node_val)
{
if(*n==NULL)
        {
        printf("\nEmpty List\n");
	return;
        }
struct List * aux = *n;
while((aux->value != node_val) && (aux->next))
	{
	aux = aux->next;
	}
if(aux->value != node_val)
	{
	printf("\nNode in absence\n");return;
	}
if(aux->next && !(aux->last))
	{
	*n = (*n)->next;
	(*n)->last = NULL;
	free(aux);
	}
else if(!(aux->next) && aux->last)
        {
        struct List * f_node = *n;
	(*n) = aux;
	(*n) = (*n)->last;
	(*n)->next = NULL;
	free(aux);
	*n = f_node;
        }
else if(aux->next && aux->last)
        {
	struct List * f_node = *n;
        (*n) = aux;
	(*n) = (*n)->last;
	(*n)->next = aux->next;
	aux->next->last= (*n);
	free(aux);
	(*n) = f_node;
        }

}


