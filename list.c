#include<stdio.h>
#include<stdlib.h>
#include "list.h"

Status add_to_start(List_ptr list, int value) {
  Node_ptr new_node = create_node(value);
  if(new_node == NULL) {
    return Failure;
  }
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
  Node_ptr new_node = create_node(value);
  if(new_node == NULL) {
    return Failure;
  }
  if(list->last == NULL) {
    list->head = new_node;
  } else {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position) {
  Node_ptr new_node, p_Walk;
  if(position <= 0 || position > list->count + 1) {
    return Failure;
  }
  if(position == 1) {
    return add_to_start(list, value);
  }
  if(position == list->count + 1) {
    return add_to_end(list, value);
  }
  new_node = create_node(value);
  if(new_node == NULL) {
    return Failure;
  }
  p_Walk = list->head;
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
  Node_ptr node_to_free;
  if(list->count == 1) {
    return clear_list(list);
  }
  if(list->head != NULL) {
    node_to_free = list->head;
    list->head = list->head->next;
    list->count--;
    free(node_to_free);
    return Success;
  }
  return Failure;
}

Status remove_from_end(List_ptr list) {
  Node_ptr p_Walk, node_to_free;
  if(list->last == NULL) {
    return Failure;
  }
  if(list->count == 1) {
    return clear_list(list);
  }
  p_Walk = list->head;
  unsigned int counter = 1;
  while(counter < list->count - 1) {
    p_Walk = p_Walk->next;
    counter++;
  }
  free(list->last);
  p_Walk->next = NULL;
  list->last = p_Walk;
  list->count--;
  return Success;
}

Status remove_at(List_ptr list, int position) {
  Node_ptr p_Walk, node_to_free;
  if(position <= 0 || position > list->count) {
    return Failure;
  }
  if(position == list->count) {
    return remove_from_end(list);
  }
  if(position == 1) {
    return remove_from_start(list);
  }
  p_Walk = list->head;
  while(position != 2) {
    p_Walk = p_Walk->next;
    position--;
  }
  node_to_free = p_Walk->next;
  p_Walk->next = p_Walk->next->next;
  list->count--;
  free(node_to_free);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value) {
  Node_ptr p_Walk = list->head;
  Node_ptr previous_node = NULL, node_to_free = NULL;
  unsigned int position = 1;
  while(p_Walk != NULL) {
    if(p_Walk->value == value) {
      if(position == 1) {
        return remove_from_start(list);
      }
      node_to_free = previous_node->next;
      if(position == list->count) {
        previous_node->next = NULL;
        list->last = previous_node;  
      } else {
        previous_node->next = p_Walk->next;
      }
      list->count--;
      free(node_to_free);
      return Success;
    }
    previous_node = p_Walk;
    p_Walk = p_Walk->next;
    position++;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value) {
  Node_ptr p_Walk = list->head;
  Node_ptr previous_node = NULL, node_to_free = NULL;
  Status status = Failure;
  unsigned int position = 1;
  while(p_Walk != NULL) {
    if(p_Walk->value == value) {
      if(position == 1) {
        status = remove_from_start(list);
      } else {
        node_to_free = previous_node->next;
        if(position == list->count) {
          previous_node->next = NULL;
          list->last = previous_node;
        } else {
          previous_node->next = p_Walk->next;
        }
        p_Walk = previous_node;
        free(node_to_free);
        list->count--;
      }
      status = Success;
      position--;
    }
    previous_node = p_Walk;
    p_Walk = p_Walk->next;
    position++;
  }
  return status;  
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
  Node_ptr p_Walk = list->head;
  Node_ptr node_to_free;
  while(p_Walk != NULL) {
    node_to_free = p_Walk;
    p_Walk = p_Walk->next;
    free(node_to_free);
  }
  list->last = NULL;
  list->head = NULL;
  list->count = 0;
  return Success;
}

void display(List_ptr list) {
  Node_ptr p_Walk = list->head;
  printf("No. of values in the list: %d\n", list->count);
  while(p_Walk != NULL) {
    printf("%d\n", p_Walk->value);
    p_Walk = p_Walk->next;
  }
}

Node_ptr create_node(int value) {
  Node_ptr new_node = malloc(sizeof(Node));
  if(new_node == NULL) {
    return NULL;
  }
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
  clear_list(list);
  free(list);
}
