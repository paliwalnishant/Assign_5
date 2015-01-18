#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next;
}*list;

// first traverse upto mth node and then delete n node one by one and check also if node is empty or not
void add_node(list *head,int dat){
    list temp,curr;
    temp=(list)malloc(sizeof(struct node));
    temp->data=dat;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else{
        curr=*head;
        while(curr->next!=NULL)
        {

            curr=curr->next;
        }
        curr->next=temp;

    }

}

void remove_node(list *head ,int m,int n)
{
    list curr,temp,del,temp1;
    curr=*head;
    while(--m) //traverse link list upto mth position
    {
        curr=curr->next;
    }
    temp=curr->next;


    while(n--||temp->next!=NULL) // delete n node or check if list is empty or not
    {
   del=temp;
    temp=temp->next;
    free(del);
   curr->next=temp;
    }

}

void display(list head)
{
    list curr;
    curr=head;
    while(curr!=NULL)
    {
        printf("%d",curr->data);
        curr=curr->next;
    }
}


int main()
{
    list head;
    head=NULL;
    char ch;
    int dat,a,b;
    printf("Do you want to make link list?y/Y\n");
    scanf("\n%c",&ch);
    while(ch=='y'||ch=='Y')
    {

        printf("Enter the data.\n");
        scanf("%d",&dat);
        add_node(&head,dat);
        printf("Enter more data?y/Y\n");
        scanf("\n%c",&ch);


    }
    display(head);
    printf("Enter the no. after which you hav to delete ?\n");
    scanf("%d",&a);
    printf("Enter the no. of nodes to be deleted ?\n");
    scanf("%d",&b);
    remove_node(&head,a,b);
    display(head);

}
