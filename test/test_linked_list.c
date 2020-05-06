#include "../src/list.h"
#include "../src/list.c"
#include "../testLib/mocha.c"

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

  return 0;
}
