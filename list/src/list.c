#include "list/inc/list.h"

#include <stdio.h>
#include <stdlib.h>
#include "node/inc/node.h"

struct _Head {
    Node* front;
};

typedef Node*(* node_func)(Node*);
typedef void(* user_func)(void*, Node*);

static void list_util_iter(Head* head, node_func node_fptr, user_func user_fptr, void *user_func_args)
{
    if(!node_fptr) {
        printf("\nNeed to provide function for node iteration\n");
    }
    
    if(head) {
        Node* front = head->front;
        while(front) {
            if(user_fptr) {
                user_fptr(user_func_args, front);
            }
            front = node_fptr(front); 
        }
    }
}

static void list_util_count_nodes(void* args, Node* node)
{
    if(!args) {
        printf("\nPass unsigned type output storage\n");
    }
    unsigned *count = (unsigned *)args;
    if(count) {
        ++(*count);
    }
}

Head* create_list(void)
{
    Head* head = calloc(1, sizeof(Head));
    if(head) return head;
    return NULL;
}

void destroy_list(Head* head)
{
    list_util_iter(head, destroy_node, NULL, NULL);
}

unsigned count_nodes(Head* head)
{
    unsigned count = 0;
    list_util_iter(head, get_next_node, list_util_count_nodes, &count);
    return count;
}

void append_to_list(Head* head, unsigned size, void* data) // TODO: how would I know if my operation fails? return type should be bool
{
    if(head) {
        if(!(head->front)) {
            head->front = create_node();
            fill_node_data(head->front, size, data);
        } else {
            Node* this_node  = head->front;
            Node* next_node = get_next_node(this_node);
            while(next_node) {
                this_node = next_node;
                next_node = get_next_node(next_node);
            }
            Node* new_node = append_node(this_node, size, data);
        }
    }
}
