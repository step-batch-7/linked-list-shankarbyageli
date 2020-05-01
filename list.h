#ifndef __LIST_H
#define __LIST_H

typedef enum {
  Failure,
  Success
} Status;

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct {
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

List_ptr create_list(void);
Node_ptr create_node(int value);

Status add_to_end(List_ptr list, int value);
Status add_to_start(List_ptr list, int value);
Status insert_at(List_ptr list, int value, int position);
Status add_unique(List_ptr list, int value);

void display(List_ptr list);

Status remove_from_start(List_ptr list);
Status remove_from_end(List_ptr list);
Status remove_at(List_ptr list, int position);

Status remove_first_occurrence(List_ptr list, int value);
Status remove_all_occurrences(List_ptr list, int value);
Status does_exist(List_ptr list, int value);

Status clear_list(List_ptr list); // Removes all elements in the list

void destroy_list(List_ptr list); // Frees the elements and the list structure from memory

#endif
