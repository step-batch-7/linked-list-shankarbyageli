#include<stdio.h>
#include<stdlib.h>
#include "list.h"

Status add_to_start(List_ptr list, int value) {

}

Status add_to_end(List_ptr list, int value) {

}

Status insert_at(List_ptr list, int value, int position) {
  
}

Status add_unique(List_ptr list, int value) {

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

}

Status clear_list(List_ptr list) {

}

void display(List_ptr list) {

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
