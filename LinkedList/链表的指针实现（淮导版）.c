#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  struct Node* next;
  int data;
} node;

node* initNode();
node* insertNode(node* prev,node* this);
void destroyList(node* head);
void printList(node* head);
node* reverseList(node *head);

int main(void) {
  node *head,*tmp;
  tmp = head = initNode();
  for(int i = 0; i < 5; ++i) {
    tmp = insertNode(tmp, initNode());
    tmp->data=i;
  }
  printList(head);
  head = reverseList(head);
  printf("Reverse List\n");
  printList(head);
  destroyList(head);
}

node* reverseList(node *head)
{
  if(head == NULL || head->next == NULL) {
    return head;
  }
  node *pre = NULL;
  node *next = NULL;
  while(head != NULL)
  {
      next = head->next;

      head->next = pre;
      pre = head;
      head = next;
  }
  return pre;
}

node* initNode() {
  node* head=(node*)malloc(sizeof(node));
  head->next=NULL;
  head->data=0;
  return head;
}

node* insertNode(node* prev,node* this) {
  this->next = this->next;
  prev->next = this;
  return this;
}

void destroyList(node* head) {
  node* tmp = head->next;
  do {
    free(head);
    head = tmp;
    if (tmp != NULL){
      tmp = tmp->next;
    }
  } while (head == NULL);
}

void printList(node* head) {
  int i = 0;
  printf("-------LIST INFO------\n");
  while(head != NULL) {
    printf("Node %d:\n   addr:%ld\n   data:%d\n",i,(long)head,head->data);
    head = head->next;
    ++i;
  }
  printf("-------END  INFO------\n");
}
