#include<stdio.h>
#include "list.h"

void print_main_menu(void);
int get_input(char *);
void exec_operation(List_ptr, char);
char get_user_choice(void);
void print_search_result(Status, int);
void print_operation_status(Status);

void print_main_menu() {
  printf("\nMain menu\n-----------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end (if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");
}

void print_search_result(Status status, int value) {
  if(status) {
    printf("%d exist in the list\n", value);
  } else {
    printf("%d doesn't exist in the list\n", value);
  }
}

void print_operation_status(Status status) {
  if(status) {
    printf("Operation Completed!\n");
  } else {
    printf("Operaion Failed!\n");
  }
}

int get_input(char *question) {
  int input;
  printf("%s\n", question);
  scanf("%d", &input);
  return input;
}

void exec_operation(List_ptr list, char choice) {
  int value, position;
  Status status;
  switch(choice) {
    case 'a':
      value = get_input("Enter the value");
      status = add_to_end(list, value);
      break;
    case 'b':
      value = get_input("Enter the value");
      status = add_to_start(list, value);
      break;
    case 'c':
      value = get_input("Enter the value");
      position = get_input("Enter the position");
      status = insert_at(list, value, position);
      break;
    case 'd':
      value = get_input("Enter the value");
      status = add_unique(list, value);
      break;
    case 'e':
      status = remove_from_start(list);
      break;
    case 'f':
      status = remove_from_end(list);
      break;
    case 'g':
      position = get_input("Enter the position");
      status = remove_at(list, position);
      break;
    case 'h':
      value = get_input("Enter the value");
      status = remove_first_occurrence(list, value);
      break;
    case 'i':
      value = get_input("Enter the value");
      status = remove_all_occurrences(list, value);
      break;
    case 'j':
      status = clear_list(list);
      break;
    case 'k':
      value = get_input("Enter the value");
      Status s = does_exist(list, value);
      print_search_result(s, value);
      return;
    case 'l':
      display(list);
      return;
    default:
      printf("Invalid option!\n");
      return;
  }
  print_operation_status(status);
}

char get_user_choice() {
  char choice;
  fflush(stdin);
  printf("Please enter the alphabet of the operation you would like to perform: ");
  scanf("%c", &choice);
  return choice;
}

int main(void) {
  List_ptr list = create_list();
  if(list == NULL) {
    printf("Memory allocation failed!\n");
    return 0;
  }
  print_main_menu();
  char choice = get_user_choice();
  while(choice != 'm') {
    exec_operation(list, choice);
    print_main_menu();
    choice = get_user_choice();
  }
  destroy_list(list);
  return 0;
}
