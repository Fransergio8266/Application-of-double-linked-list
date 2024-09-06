#include <stdio.h>
#include <stdlib.h>
#include "funcoes_lista_dupla.h"

int main()
{
struct List *n = NULL;

ordered_down_push(&n,3);
ordered_down_push(&n,4);
ordered_down_push(&n,2);
ordered_down_push(&n,12);
ordered_down_push(&n,8);

print(&n);
pop_any_node(&n,8);
print(&n);

//ordered_up_push(&n,3);
//ordered_up_push(&n,1);
//ordered_up_push(&n,2);
//ordered_up_push(&n,12);
//ordered_up_push(&n,8);

///print(&n);
//pop_any_node(&n,8);
//print(&n);

//push_end(&n,3);
//push_end(&n,5);
//push_end(&n,7);
//push_end(&n,8);
//push_end(&n,12);
//push_middle(&n,23,8);
//push_middle(&n,37,18);
//print(&n);
//pop_any_node(&n,81);
//print(&n);
//pop_only_at_begin(&n);
//print(&n);
//pop_only_at_end(&n);
//print(&n);
}
