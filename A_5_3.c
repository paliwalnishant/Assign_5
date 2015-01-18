#include<stdio.h>

//swap function
void swap(int *first,int *second)
{
int temp;
temp=*first;
*first=*second;
*second=temp;
}

//sorting function
void quicksort(int x[20],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}


int main()
{
int x[20],s,i,j;
printf("Enter the size of array:\n");
scanf("%d",&s);
printf("Enter the array elements:\n");
for(i=0;i<=s;i++){
scanf("%d",&x[i]);
}
printf("Next number is:\n");

//first traverse from last untill we will find the number whose previous number is smaller .


for(i=s-1;i>0;i--)
{
    if(x[i]>x[i-1])
        break;
}
if(i==0){
    printf("NO Number possible\n");
}


//now find the number which is smallest greatest number from the above number
int t=x[i-1],k=i;
for(j=i+1;j<=s;j++)
{
   if(t<x[j]&&x[j]<x[k]){
    k=j;//for comparision and finding smallest number
   }
}

//swap both numbers and then sort the array from the above position till end
swap(&x[k],&x[i-1]);
quicksort(x,i,s);
for(i=0;i<=s;i++)
{
 printf("%d",x[i]);
}

return 0;

}
