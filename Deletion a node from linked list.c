#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* deleteBegin(struct node *head)
{
    if(head==NULL)
        return NULL;
    struct node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* deleteEnd(struct node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    free(temp->next);
    temp->next=NULL;
    return head;
}
struct node* deleteValue(struct node *head,int key)
{
    struct node *temp =head,*prev=NULL;
    if(temp!=NULL&&temp->data==key)
    {
        head=temp->next;
        free(temp);
        return head;
    }
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
       return head;
    prev->next=temp->next;
    free(temp);
    return head;
}
void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=(struct node*)malloc(sizeof(struct node));
    head->next->data=2;
    head->next->next=(struct node*)malloc(sizeof(struct node));
    head->next->next->data=3;
    head->next->next->next=(struct node*)malloc(sizeof(struct node));
    head->next->next->next->data=4;
    head->next->next->next->next=NULL;
    head=deleteBegin(head);
    head=deleteEnd(head);
    head=deleteValue(head, 3);
    display(head);
    return 0;
}
