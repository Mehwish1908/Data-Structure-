#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node* insertBegin(struct node *head, int data)
{
struct node* newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=data;
newNode->prev=NULL;
newNode->next=head;
if(head!=NULL)
head->prev=newNode;
return newNode;
}
struct node* insertEnd(struct node *head,int data)
{
struct node* newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=data;
newNode->next=NULL;
if(head==NULL)
{
newNode->prev=NULL;
return newNode;
}
struct node *temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newNode;
newNode->prev=temp;
return head;
}
void displayForward(struct node *head)
{
struct node *temp=head;
while(temp!=NULL) {
printf("%d <-> ",temp->data);
temp=temp->next;
}
printf("NULL\n");
}
void displayBackward(struct node *head)
{
struct node *temp=head;
while(temp->next!=NULL)
temp=temp->next;
while(temp!=NULL)
{
printf("%d <-> ",temp->data);
temp=temp->prev;
}
printf("NULL\n");
}
int main()
{
struct node *head=NULL;
head=insertBegin(head, 2);
head=insertBegin(head, 1);
head=insertEnd(head, 3);
head=insertEnd(head, 4);
printf("Forward Traversal:\n");
displayForward(head);
printf("Backward Traversal:\n");
displayBackward(head);
return 0;
}
