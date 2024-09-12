#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        int lth,rth;
        node *left,*right;
};

class thread
{
    public:
        node *head;
        node *newnode,*root,*temp,*parent;
        thread()
        {
            root=NULL;
        }

        void create()
        {
            newnode=new node;
            newnode->left=NULL;
            newnode->right=NULL;
            newnode->lth=0;
            newnode->rth=0;
            cout<<"\n Enter The Element: ";
            cin>>newnode->data;
            if(root==NULL)
            {
                root=newnode;
                head=new node;
                head->data=-999;
                head->left=root;
                root->left=head;
                root->right=head;
            }
            else
                insert(root,newnode);
        }

        void insert(node *ptr,node *newnode)
        {
            if(newnode->data<ptr->data)
            {
                if(ptr->lth==0)
                {
                    newnode->left=ptr->left;
                    newnode->right=ptr;
                    ptr->left=newnode;
                    ptr->lth=1;
                }
                else
                    insert(ptr->left,newnode);
            }
            if(newnode->data>ptr->data)
            {
                if(ptr->rth==0)
                {
                    newnode->right=ptr->right;
                    newnode->left=ptr;
                    ptr->rth=1;
                    ptr->right=newnode;
                }
                else
                    insert(ptr->right,newnode);
            }
        }

        void display_inorder(node * temp,node *d)
        {
            while(temp!=d)
            {
                while(temp->lth==1)
                {
                    temp=temp->left;
                }
                cout<<" "<<temp->data;
                while(temp->rth==0)
                {  
                    temp=temp->right;
                    if(temp==d)
                    return;
                    cout<<" "<<temp->data;
                }
                temp=temp->right;
            }

        }

        void display_preorder(node *temp,node *head)
        {
            int flag=0;
            while(temp!=head)
            {
                if(flag==0)
                    cout<<" "<<temp->data;
                if((temp->lth==1) && (flag==0))
                {
                    temp=temp->left;
                }
                else
                {
                    while(1)
                    {
                        if(temp->rth==1)
                        {
                            flag=0;
                            temp=temp->right;
                            break;
                        }
                        else
                        {
                            if(temp!=head)
                            {
                                flag=1;
                                temp=temp->right;
                                break;
                            }
                        }
                    }
                }
            }
        }
};

int main()
{
    int choice;
    thread th;
    cout<<"\nProgram For Threaded Binary Tree\n";
    do
    {
        cout<<"\n==============================================";
        cout<<"\n1)Create \n2)Display Inorder\n3)Display Preorder\n4)Exit";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                th.create();
                break;
            case 2:
                th.display_inorder(th.root,th.head);
                break;
            case 3:
                th.display_preorder(th.root,th.head);
                break;
        }
    }while(choice!=4);
    return 0;
}
