#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;

}*list;

//Sir I am getting an extra "-1" in every output , rest of my output is correct.

void add_node(list *head,int dat)
{
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

//program to merge two sorted list
list merge_list(list *head1,list *head2)
{
    list temp1,temp2,temp3,head3;
    temp1=*head1;
    temp2=*head2;
    temp3=head3; // new linked list which will store merged list
    while(1)
    {
        if(temp1==NULL) //if first link list is empty
        {
            temp3->next=temp2;
            break;
        }
        else if(temp2==NULL) // if second link list is empty
        {
            temp3->next=temp1;
            break;
        }
        if(temp1->data<temp2->data) //merging in new link list and then traversing to new element
        {
            temp3->next=temp1;
            temp3=temp1;
            temp1=temp1->next;
            temp3->next=NULL;
            }
        else if(temp1->data>temp2->data)
        {
            temp3->next=temp2;
            temp3=temp2;
            temp2=temp2->next;
            temp3->next=NULL;

        }




    }
return head3;

}


void display(list head){
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
list head1,temp,head2,head3;
head1=NULL;
head2=NULL;

char ch;
int dat;
printf("create first link listy/Y\n");
scanf("\n%c",&ch);
while(ch=='y'||ch=='Y'){
printf("Enter data\n");
scanf("%d",&dat);
add_node(&head1,dat);
printf("ENter more elements ?y/Y\n");
scanf("\n%c",&ch);
}

printf("create second link listy/Y\n");
scanf("\n%c",&ch);
while(ch=='y'||ch=='Y'){
printf("Enter data\n");
scanf("%d",&dat);
add_node(&head2,dat);
printf("ENter more elements ?y/Y\n");
scanf("\n%c",&ch);
}
display(head1);
printf("second link list\n");
display(head2);

printf("Final list is\n");
head3=merge_list(&head1,&head2);
display(head3);

}
