#include<stdio.h>
#include<stdlib.h>
#include "list.h"

Status add_to_start(List_ptr list, int value) {
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) {
    list->last = new_node;
  } else {
    new_node->next = list->head;
  }
  list->head = new_node;
  list->count++;
  return Success;
}

Status add_to_end(List_ptr list, int value) {
  return insert_at(list, value, list->count + 1);
}

Status insert_at(List_ptr list, int value, int position) {
  if(position <= 0 || position > list->count + 1) {
    return Failure;
  }
  if(position == 1) {
    return add_to_start(list, value);
  } 
  Node_ptr new_node = create_node(value);
  Node_ptr p_Walk = list->head;
  while(position != 2) {
    p_Walk = p_Walk->next;
    position--;
  }
  new_node->next = p_Walk->next;
  p_Walk->next = new_node;
  list->count++;
  return Success;
} 

Status add_unique(List_ptr list, int value) {
  if(!does_exist(list, value)) {
    return add_to_end(list, value);
  }
  return Failure;
}

Status remove_from_start(List_ptr list) {

}

Status remove_from_end(List_ptr list) {

}

Status remove_at(List_ptr list, int position) {

}

Status remove_first_occurrence(List_ptr list, int value) {

}

Status remove_all_occurrences(List_ptr list, int value) {

}

Status does_exist(List_ptr list, int value) {
  Node_ptr p_Walk = list->head;
  while(p_Walk != NULL) {
    if(p_Walk->value == value) {
      return Success;
    }
    p_Walk = p_Walk->next;
  }
  return Failure;
}

Status clear_list(List_ptr list) {

}

void display(List_ptr list) {
  Node_ptr p_Walk = list->head;
  printf("%d %s in list: \n", list->count, list->count > 1 ? "numbers" : "number");
  while(p_Walk != NULL) {
    printf("%d\n", p_Walk->value);
    p_Walk = p_Walk->next;
  }
}

Node_ptr create_node(int value) {
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void) {
  List_ptr empty_list = malloc(sizeof(List));
  empty_list->head = NULL;
  empty_list->last = NULL;
  empty_list->count = 0;
  return empty_list;
}

void destroy_list(List_ptr list) {
  Node_ptr p_Walk = list->head;
  Node_ptr node_to_free;
  while(p_Walk != NULL) {
    node_to_free = p_Walk;
    p_Walk = p_Walk->next;
    free(node_to_free);
  }
  free(list);
}
