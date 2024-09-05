#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*newnode,*head,*ptr,*pre,*temp;

//=============================================================
void insBeg(int item)
{
	newnode=new node;
	newnode->data=item;
	newnode->next=head;
	head=newnode;
}

//=============================================================
void insEnd(int item)
{
	newnode=new node;
	newnode->data=item;
	if (head==NULL)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}

//=============================================================
void insLoc(int item, int loc)
{
	newnode=new node;
	newnode->data=item;
	int c=0;
	
	if(loc==1)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			c++;
			if(loc==c)
			{
				break;
			}
			else
			{
				pre=ptr;
				ptr=ptr->next;
			}
		}
	newnode->next=ptr;
	pre->next=newnode;
	}
}

//=============================================================
void countList()
{
	int count=0;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	cout<<"Number of nodes: "<<count;
}

//=============================================================
void search(int key)
{
	int count=0;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		if(ptr->data==key)
		{
			cout<<"Element found at "<<count;
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	if(ptr==NULL)
	{
		cout<<"Element not found";
	}
}

//=============================================================
void delBeg()
{
	temp=head;
	head=head->next;
	delete temp;
	cout<<"Node deleted";
}

//=============================================================
void delEnd()
{
	ptr=head;
	while(ptr->next!=NULL)
	{
		pre=ptr;
		ptr=ptr->next;
	}
	pre->next=NULL;
	delete ptr;
	cout<<"Node deleted";
}

//=============================================================
void delLoc(int loc)
{
	int c=0;
	if(loc==1)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			c++;
			if(loc==c)
			{
				break;
			}
			else
			{
				pre=ptr;
				ptr=ptr->next;
			}
		}
		pre->next=ptr->next;
	}
	delete ptr;
	cout<<"Node deleted";
}

//=============================================================
void display()
{
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL\n";
}
	
//=============================================================
int main()
{
	int item,loc,ch,key;
	do
	{
		cout<<"\n";
		cout<<"\n1.Insert node at beginning.";
		cout<<"\n2.Insert node at end.";
		cout<<"\n3.Insert node at specified location.";
		cout<<"\n4.Count nodes.";
		cout<<"\n5.Search list.";
		cout<<"\n6.Delete node at beginning.";
		cout<<"\n7.Delete node at end.";
		cout<<"\n8.Delete node at specified location.";
		cout<<"\n9.Display list.";
		cout<<"\n10.Exit.";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter data to insert: ";
					cin>>item;
					insBeg(item);
			        break;
			case 2: cout<<"\nEnter data to insert: ";
					cin>>item;
					insEnd(item);
			        break;
			case 3: cout<<"\nEnter data to insert: ";
					cin>>item;
					cout<<"\nEnter location of insert: ";
					cin>>loc;
					insLoc(item,loc);
			        break;
			case 4: countList();
					break;
			case 5: cout<<"\nEnter key to search: ";
					cin>>key;
					search(key);
			        break;
			case 6: delBeg();
					break;
			case 7:	delEnd();
					break;
			case 8: cout<<"\nEnter location of node to delete: ";
					cin>>loc;
					delLoc(loc);
					break;
			case 9: display();
					break;
		}
	}while(ch!=10);
	return 0;
}

