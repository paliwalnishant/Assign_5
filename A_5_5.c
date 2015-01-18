#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next;
}*list;


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

// i am taking a count variable and then traversing a link list . First node of link list is assumed with count 0 . Now for every
// even count (odd node link list) remove it from original link list form a new link (inserion in begining so that reverse can be done )
// at the append both link list.
void remove_alter(list *head)
{

    list temp,curr,temp1,curr1;
    temp=*head;
    curr=temp->next;
    curr1=curr;
    temp1=NULL;

    int count=0;

    while(curr->next!=NULL)
    {

        if(count%2==0)
        {
            curr=curr->next;
            curr1->next=temp1;  //node is linked to new link list with insertion in begining
            temp1=curr1;
            curr1=curr;
            temp->next=curr;
            count++;
        }
        else{
            temp=temp->next;
            curr=curr->next;
            curr1=curr;
            count++;
        }

    }

    curr->next=temp1; // append both link list



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
    int dat;
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

    printf("alterred list is \n");
    remove_alter(&head);
    display(head);

}
