#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	int number;
	struct node*next;
 } 
 Linknode,*Link;
 
 Link LinkCreat(int n)
 {
 	Link headp=NULL,currentp=NULL,temp=NULL;
 	headp=(Link)malloc(sizeof(Linknode));
 	if(NULL==headp)
 	{
 		cout<<"erro";
	 }
	 headp->number=1;
	 headp->next=NULL;
	 currentp=headp;
	 for(int i=2;i<=n;i++)
	 {
	 	temp=(Link)malloc(sizeof(Linknode));
	 	temp->number=i;
	 	currentp->next=temp;
	 	currentp=temp;
	 }
	 currentp->next=headp;
	 return currentp;
 }
 
void LinkDel(Link prev)
 {
 	Link currentp;
 	currentp=prev->next;
 	prev->next=currentp->next;
 	free(currentp);
 }
 
 void LinkJudge(int n)
 {
 	Link prev=NULL;
 	for(int x=1;x<=n;x++)
 	{
 		for(int y=1;y<=n;y++)
 		{
 			Link lastp=LinkCreat(n);
 			for(int i=1;i<x;i++)                     
 			{
 				lastp=lastp->next;
			 }
			 prev=lastp;
			 //LinkDel(prev);
			 for(int j=1;j<=n-1;j++)
			 {
			 	for(int k=1;k<=y-1;k++)
			 	{
			 		prev=prev->next;
				 }
				 LinkDel(prev);
			 }
			 if(prev->number==1)
			 {
			 	cout<<"x="<<x<<"\t"<<"y="<<y<<endl;
			 }
			 prev=NULL;
		 }
	 }
 }
 
 int main()
 {
 	int n;
 	cout<<"请输入大于或等于2的整数n"<<endl;
 	cin>>n;
 	if(n<=1)
 	{
 		cout<<"输入错误";
	 }
 	else
 	{
 		cout<<"符合情况的x y的值可以为:"<<endl;
 		LinkJudge(n);
	 }
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
