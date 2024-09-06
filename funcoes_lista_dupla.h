






#ifndef __FUNCOES_LISTA_DUPLA_H__
#define __FUNCOES_LISTA_DUPLA_H__

#include <stdio.h>
#include <stdlib.h>

struct List
{
int value;
struct List * next;
struct List * last;
};


void push_begin(struct List **n,int x);

void push_end(struct List **n, int x);

void push_middle(struct List **n, int x, int before);

void ordered_up_push(struct List **n, int x);

void ordered_down_push(struct List **n, int x);

void print(struct List **n);

void pop_only_at_end(struct List **n);

void pop_only_at_begin(struct List **n);

void pop_any_node(struct List **n,int node_val);

#endif
