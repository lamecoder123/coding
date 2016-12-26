/* 
################################################################
## linked list1 ->5->9->4->8->2   //number 28495
## linked list2 ->7->2->9->1      //number 1927
##
## result list ->2->2->4->0->3    //number 30422
*/
#include <stdio.h>
#incldue <stdlib.h>

//definition of linked list with data and pointer to next node
struct node {
  int data;
  struct node* next;
};

//function to create a new node in memory and return the address
struct node* newNode(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if(temp) {
    temp->data = data;
    temp->next = NULL;
    return temp;
  }
}

//function to link node at the head end and adjust the head pointer
void pushNode(struct node** headRef, int data) {
  struct node* temp = newNode(data);
  temp->next = *headRef;
  *headRef = temp;
}

void printList(struct node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
struct node* listAddition(struct node* first, struct node* second) {
  struct node *result = NULL;
  struct node *prev, *temp = NULL;
  int carry, sum = 0;
  
  while (first != NULL || second != NULL) {
    
    sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
    if ((sum / 10) == 1) {
      carry = 1;
    }
    else
      carry = 0;
    sum = sum % 10;
    
    //get a newNode with sum as data
    temp = newNode(sum);
    
    //when the result is NULL, adjust the pointers to point to temp
    if (result == NULL)
      result = temp;
    else
      prev->next = temp;
    
    prev = temp;
    
    if(first)
      first->next;
    if(second)
      second->next;
  }
  
  if (carry > 0)
    prev->next = newNode(carry);
  
  return result;
}

int main() {
  struct node *first, *second, *result;
  first = newNode(2);
  pushNode(&first, 8);
  pushNode(&first, 4);
  pushNode(&first, 9);
  pushNode(&first, 5);
  printList(first);
  second = newNode(1);
  pushNode(&second, 9);
  pushNode(&second, 2);
  pushNode(&second, 7);
  printList(second);
  printf("Final list after addition is: ");
  result = listAddition(first, second);
  printList(result);
}
