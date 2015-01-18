#include<stdio.h>
#include<stdlib.h>
//Program works only when you will input link list.



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


//Function for removing duplicate elements

void remove_dup(list *head)
{
    list temp,curr,dup;
    temp=*head;
    curr=temp->next;
    while(temp->next!=NULL)  //loop for traversing till the end of link list
    {
    if(temp->data==curr->data)   //if duplicate element found then remove it
    {
        dup=curr;
        curr=curr->next;
        free(dup);
        temp->next=curr;

    }
    else{                      // if not found then traverse ahead
        curr=curr->next;
        temp=temp->next;
    }
    }

}

void display(list head)  // display function
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
    remove_dup(&head);
    printf("After removing duplicates elements:\n");
    display(head);


}
