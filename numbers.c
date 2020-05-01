#include<stdio.h>
#include "list.h"

void print_main_menu(void);
int get_input(char *);
Status exec_operation(List_ptr, char);
char get_user_choice(void);

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

int get_input(char *question) {
  int input;
  printf("%s\n", question);
  scanf("%d", &input);
  return input;
}

Status exec_operation(List_ptr list, char choice) {
  int value, position;
  switch(choice) {
    case 'a':
      value = get_input("Enter the value");
      return add_to_end(list, value);
    case 'b':
      value = get_input("Enter the value");
      return add_to_start(list, value);
    case 'c':
      value = get_input("Enter the value");
      position = get_input("Enter the position");
      return insert_at(list, value, position);
    case 'd':
      value = get_input("Enter the value");
      return add_unique(list, value);
    case 'e':
      return remove_from_start(list);
    case 'f':
      return remove_from_end(list);
    case 'g':
      position = get_input("Enter the position");
      return remove_at(list, position);
    case 'h':
      value = get_input("Enter the value");
      return remove_first_occurrence(list, value);
    case 'i':
      value = get_input("Enter the value");
      return remove_all_occurrences(list, value);
    case 'j':
      return clear_list(list);
    case 'k':
      value = get_input("Enter the value");
      Status s = does_exist(list, value);
      if(s) {
        printf("%d exist in the list\n", value);
      } else {
        printf("%d doesn't exist in the list\n", value);
      }
      return Success;
    case 'l':
      display(list);
      return Success;
    default:
      printf("Invalid option!\n");
      return Success;
  }
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
  print_main_menu();
  char choice = get_user_choice();
  while(choice != 'm') {
    Status status = exec_operation(list, choice);
    if(!status) printf("Operation failed!\n");
    print_main_menu();
    choice = get_user_choice();
  }
  destroy_list(list);
  return 0;
}
