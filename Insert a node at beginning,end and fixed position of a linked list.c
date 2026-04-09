#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node*next;
};
struct node*insertBegin(struct node*head,int data)
{
   struct node*newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=data;
   newNode->next=head;
   return newNode;
}
struct node*insertEnd(struct node*head,int data)
{
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL)
    {
        return newNode;
    }

    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    return head;
}
struct node*insertPosition(struct node*head,int data,int pos)
{
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    if(pos==1)
    {
        newNode->next=head;
        return newNode;
    }
    struct node*temp=head;
    for(int i=1;i<pos-1&&temp!=NULL;i++)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
void display(struct node*head)
{
    while(head!=NULL)
        {
            printf("%d-> ",head->data);
            head = head->next;
        }
    printf("NULL\n");
}
int main() {
struct node*head=NULL;
head=insertBegin(head,3);
head=insertBegin(head,1);
head=insertEnd(head, 5);
head=insertPosition(head,2,2);
display(head);
return 0;
}
