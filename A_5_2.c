#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


// I have written this code and i also find this method on geek for geeks but there is one limitaion with this method
//if i swap the entries of array a and b (mentioned below) then i get the wrong answer ...this is the limitation
//code only works if first array has elements smaller than array second.
//I found a better way to do this question with the help of merging but unable to understand.

void find_pair(int a[],int b[],int m ,int n,int x)
{
int diff=INT_MAX;

int pos_a,pos_b;
int i=0,j=n-1;


while(i<m && j>0)
{

 //if diff found is less than the new difference.Upadate old diff
if(abs((a[i]+b[j])-x)<diff)
{
    pos_a=i;
    pos_b=j;
    diff=abs((a[i]+b[j])-x);
}
// if the sum of pairs is greater than x
if((a[i]+b[j])>x)
{
    j--;
}
//if  sum of pairs is less than x
else
    i++;
}
printf("pairs are: \n");
printf("%d \t %d",a[pos_a],b[pos_b]);
}



int main()
{
int a[]={1,4,5,7};
int b[]={10,20,30,40};
int m=sizeof(a)/sizeof(a[0]);
int n=sizeof(b)/sizeof(b[0]);
int x=32;
find_pair(a,b,m,n,x);
return 0;
}
