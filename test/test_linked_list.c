#include<stdio.h>
#include "../testLib/mocha.h"
#include "../list.h"

__testStatus add_to_end_in_empty_list() {
  List_ptr list = create_list();
  Status s = add_to_end(list, 10);
  if(list->head->value == list->last->value && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus add_to_end_in_list_with_one_number() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = add_to_end(list, 20);
  if(list->last->value == 20 && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus add_to_start_in_empty_list() {
  List_ptr list = create_list();
  Status s = add_to_start(list, 10);
  if(list->head->value == 10 && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus add_to_start_in_list_with_one_number() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = add_to_start(list, 20);
  if(list->head->value == 20 && list->head != list->last && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus insert_at_given_position() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = insert_at(list, 20, 0);
  if(list->head->value == 20 && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus insert_at_invalid_position() {
  List_ptr list = create_list();
  Status s1 = insert_at(list, 10, 1);
  Status s2 = insert_at(list, 10, -1);
  if(list->count == 0 && !s1 && !s2) {
    return __Success;
  }
  return __Failure;
}

__testStatus add_unique_already_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = add_unique(list, 10);
  if(list->count == 1 && !s) {
    return __Success;
  }
  return __Failure;
}

__testStatus add_unique_does_not_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = add_unique(list, 30);
  if(list->count == 2 && s) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_beginning_in_empty_list() {
  List_ptr list = create_list();
  Status s = remove_from_start(list);
  if(!s && list->head == NULL && list->last == NULL && list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_beginning_in_list_with_one_number() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = remove_from_start(list);
  if(s && list->head == NULL && list->last == NULL && list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_start_in_list() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  add_to_end(list, 30);
  Status s = remove_from_start(list);
  if(s && list->head->value == 20 && list->last->value == 30 && list->count == 2) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_end_of_empty_list() {
  List_ptr list = create_list();
  Status s = remove_from_end(list);
  if(!s && list->head == NULL && list->last == NULL && list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_end_of_one_element_list() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = remove_from_end(list);
  if(s && list->head == NULL && list->last == NULL && list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_from_end_of_list() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  add_to_end(list, 30);
  Status s = remove_from_end(list);
  if(s && list->head->value == 10 && list->last->value == 20 && list->count == 2) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_at_invalid_position() {
  List_ptr list = create_list();
  Status s1 = remove_at(list, 1);
  Status s2 = remove_at(list, -1);
  if(!s1 && !s2 && list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_at_given_valid_position() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  add_to_end(list, 30);
  Status s = remove_at(list, 1);
  if(list->count == 2 && s && list->head->value == 10 && list->last->value == 30) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_first_occurrence_element_not_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  Status s = remove_first_occurrence(list, 15);
  if(!s && list->count == 2) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_first_occurrence_number_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  Status s = remove_first_occurrence(list, 20);
  if(s && list->count == 1 && list->last->value == 10) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_all_occurrences_number_not_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  Status s = remove_all_occurrences(list, 20);
  if(!s && list->count == 1) {
    return __Success;
  }
  return __Failure;
}

__testStatus remove_all_occurrences_number_exist() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  add_to_end(list, 30);
  add_to_end(list, 10);
  add_to_end(list, 10);
  Status s = remove_all_occurrences(list, 10);
  if(s && list->count == 2 && list->head->value == 20 && list->last->value == 30) {
    return __Success;
  }
  return __Failure;
}

__testStatus clear_empty_list() {
  List_ptr list = create_list();
  clear_list(list);
  if(list->count == 0) {
    return __Success;
  }
  return __Failure;
}

__testStatus clear_list_with_elements() {
  List_ptr list = create_list();
  add_to_end(list, 10);
  add_to_end(list, 20);
  clear_list(list);
  if(list->count == 0 && list->head == NULL && list->last == NULL) {
    return __Success;
  }
  return __Failure;
}

__testStatus check_if_number_exist_in_list() {
  List_ptr list = create_list();
  Status s1 = does_exist(list, 10);
  add_to_end(list, 10);
  Status s2 = does_exist(list, 10);
  if(!s1 && s2) {
    return __Success;
  }
  return __Failure;
}

int main(void) {
  describe("add to end of the list");
  test_case("should add to the end of empty list", add_to_end_in_empty_list());
  test_case("should add to the end of list with one number", add_to_end_in_list_with_one_number());

  describe("add to start of the list");
  test_case("should add to the start of empty list", add_to_start_in_empty_list());
  test_case("should add to the start of list with one number", add_to_start_in_list_with_one_number());

  describe("insert at given position in the list");
  test_case("should not insert at invalid position", insert_at_invalid_position());
  test_case("should insert_at given position in list", insert_at_given_position());

  describe("add unique number to list");
  test_case("should not add if number already exist in list", add_unique_already_exist());
  test_case("should add to end if number doesn't exist in list", add_unique_does_not_exist());

  describe("remove from beginning of list");
  test_case("should not remove if list is empty", remove_from_beginning_in_empty_list());
  test_case("should remove the only number of list if list has one element", remove_from_beginning_in_list_with_one_number());
  test_case("should remove the first element of list with many elements", remove_from_start_in_list());

  describe("remove from end of the list");
  test_case("should not remove if list is empty", remove_from_end_of_empty_list());
  test_case("should remove from end in list with only element", remove_from_end_of_one_element_list());
  test_case("should remove from end in list with many elements", remove_from_end_of_list());

  describe("remove a number at given position in the list");
  test_case("should not remove if position is invalid", remove_at_invalid_position());
  test_case("should remove element from list given a valid position", remove_at_given_valid_position());

  describe("remove first occurrence of the element");
  test_case("should not remove if number doesn't exist in list", remove_first_occurrence_element_not_exist());
  test_case("should remove first occurrence of number if number exist in the list", remove_first_occurrence_number_exist());

  describe("remove all occurrences of the element");
  test_case("should not remove if number doesn't exist", remove_all_occurrences_number_not_exist());
  test_case("should remove all occurrences if number exist in the list", remove_all_occurrences_number_exist());

  describe("clear the list");
  test_case("should not clear if list is empty", clear_empty_list());
  test_case("should remove all elements from list", clear_list_with_elements());

  describe("check if number exist in list");
  test_case("should check if number exist in the list", check_if_number_exist_in_list());

  return 0;
}
