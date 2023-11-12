#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node*add;
}
*start=NULL,*prev,*temp,*ptr;
void insertbeg();
void insertend();
void insert_spec();
void deletebeg();
void deleteend();
void deletespec();
void display();

int main()
{
    int ch;
    cout<<"                  Linked List by YASH LADE \n";
	do{
	
	cout<<"\n main menu\n";
	cout<<"press 1 for insertion at beginning \n";
	cout<<"press 2 for insertion at end\n";
	cout<<"press 3 for insertion at specific position\n";
	cout<<"press 4 for deletion at beginning\n";
	cout<<"press 5 for deletion at end\n";
	cout<<"press 6 for deletion at specific position\n";
	cout<<"press 7 for display linked list\n";
	cout<<"press 8 for exit \n";
	
	cout<<"Enter your choice :";
	cin>>ch;
	
	switch(ch)
	{
		case 1:insertbeg();break;
		case 2:insertend();break;
		case 3:insert_spec();break;
		case 4:deletebeg();break;
		case 5:deleteend();break;
		case 6:deletespec();break;
		case 7:display();break;
		case 8:break;
		default:cout<<"/wrong choice";
	}
	
}
	 while(ch!=8);
    
}




void insertbeg()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	cout<<"Linked list is empty";
	
	else
	{
		int no;
		cout<<"Enter the number :";
		cin>>no;
		
		ptr->data=no;
		ptr->add=start;
		start=ptr;
	}
}

void insertend()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	cout<<"Linked list is empty";
	
	else
	{
		int no;
		cout<<"Enter the number :";
		cin>>no;
		ptr->data=no;
		ptr->add=NULL;
		
		temp=start;
		while(temp->add!=NULL)
		{ temp=temp->add;
		}
		temp->add=ptr;
	}
}

void insert_spec()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	cout<<"Linked list is empty";
	
	else
	{    node* data;
		int no,i,pos;
		
		cout<<"Enter the position :";
		cin>>pos;
		
		cout<<"Enter the number :";
		cin>>no;
		
		ptr->data=no;
		
		temp=start;
		
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
		}
		ptr->add=temp;
		prev->add=ptr;
	}
}

void deletebeg()
{
	if(start==NULL)
	cout<<"Linked list is empty :";
	
	else
	{
		cout<<"Deleted elemet is :"<<start->data;
		
		temp=start;
		start=start->add;
		
		free(temp);
	}
}

void deleteend()
{
 if(start==NULL)
 cout<<"Linked list is empty :";
 else
	{
		
		
		temp=start;
		while(temp->add!=NULL)
		{
			prev=temp;
			temp=temp->add;
			
		}
		prev->add=NULL;
		cout<<"Deleted elemet is :"<<temp->data;
		free(temp);
}
}
void deletespec()
{
  if(start==NULL)
  cout<<"Linked list is empty :";
	
  else
	{   int pos,i;
		cout<<"Enter the position";
		cin>>pos;
		
		temp=start;
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
		}
		
		prev->add=temp->add;
		cout<<"Deleted element is :"<<temp->data;
		free(temp);
	}
}

void display()
{
	if(start==NULL)
	cout<<"Linked list is empty ";
	else
	{
     temp=start;
     while(temp!=NULL)
     {cout<<temp->data<<" ";
     temp=temp->add;
     }
     cout<<"\n";
    }

}

