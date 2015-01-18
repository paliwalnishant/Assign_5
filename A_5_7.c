#include<stdio.h>
//code works only for rotation value less than size of link list
//there is case where there is only one node in link list rotation is not possible by this code

typedef struct node
{
int data;
struct node *next;
}*list;
// function to create link list
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
// function to rotate the link list
void counter_rotate(list *head,int p)
{
    list curr,temp,temp1;
    curr=*head;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

        while(--
              p)
        {
            curr=curr->next;

        }
        temp1=curr->next;
        curr->next=NULL;
        temp->next=*head;
        *head=temp1;
        }

void display(list head){
list curr=head;
while(curr!=NULL)
{

    printf("%d\n",curr->data);
    curr=curr->next;

}
}


int main()
{
list head,temp;
char ch;
int dat,p;
head=NULL;
printf("Do you want a link list?y/Y\n");
scanf("\n%c",&ch);
while(ch=='y'|ch=='Y')
    {
        printf("Enter the data?\n");
        scanf("%d",&dat);
        add_node(&head,dat);
        printf("Do you want to add more elements in a link list?y?Y\n");
        scanf("\n%c",&ch);
        }
        display(head);
         // function to rotate link lisr by given position
        printf("Enter the node no. by which you want to rotate?\n");
        scanf("%d",&p);
        counter_rotate(&head,p);
        printf("Rotated node is: \n");
        display(head);





}
