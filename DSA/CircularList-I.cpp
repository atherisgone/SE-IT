#include <iostream>
using namespace std;

class CircularQueue
{
	int queue[30];
	int front,rear,n;
	public:
	CircularQueue()
	{
		n=5;
		front=-1;
		rear=-1;
	}
	
	//=================================================
	void enqueue(int item)
	{
		if ((rear+1)%n==front)
		{
			cout<<"!!!Overflow!!!";
		}
		else if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			queue[rear]=item;
		}
		else
		{
			rear=(rear+1)%n;
			queue[rear]=item;
		}
	}
	
	//=================================================
	void dequeue()
	{
		if (front==-1)
		{
			cout<<"Underflow";
		}
		else if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%n;
		}
	}
	//=================================================
	void display()
	{
		cout<<"Queue: \n";
		int i=front;
		if(front==-1 && rear==-1)
		{
			cout<<"Queue is empty.";
		}
		else
		{
			while(i!=rear)
			{
				cout<<queue[i]<<"->";
				i=(i+1)%n;
			}
			cout<<queue[rear];
		}
	}

};

//=================================================
int main()
{
	CircularQueue cq;
	int ch,item;
	do
	{
		cout<<"\n===================================================";
		cout<<"\n1.Enqueue";
		cout<<"\n2.Dequeue";
		cout<<"\n3.Display";
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
                cout<<"\nEnter data to insert: ";
                cin>>item;
                cq.enqueue(item);
                break;
          	case 2:
                cq.dequeue();
                cout<<"\nDequeue executed.";
                break;
           	case 3:
            	cq.display();
            	break;

	    }
    }while(ch!=4);
    return 0;
}

