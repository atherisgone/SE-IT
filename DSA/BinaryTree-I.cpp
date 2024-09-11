#include<iostream>
using namespace std;

struct tree
{
	int data;
	tree *left;
	tree *right;
};

//=============================================================
class BinaryTree
{
	public:
		tree *root=NULL,*newnode,*ptr,*loc,*par,*suc,*parsuc,*save;
		
	void insertNode(int i_item)
	{
		newnode = new tree;
		newnode->data = i_item;
		newnode->left = NULL;
		newnode->right = NULL;
		
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			ptr = root;
			while(ptr!=NULL)
			{
				par = ptr;		
				if(i_item>ptr->data)
				{
					ptr = ptr->right;
				}
				else
				{
					ptr = ptr->left;
				}
			}
			
			if(i_item>par->data)
			{
				par->right = newnode;
			}
			else
			{
				par->left = newnode;
			}
		}
	}
	
	//=============================================================	
	void caseA(tree *loc, tree *par)
	{
		tree *child;
		if(loc->left == NULL && loc->right == NULL)
		{
			child = NULL;
		}
		else if(loc->left!=NULL)
		{
			child = loc->left;
		}
		else
		{
			child = loc->right;
		}
		
		if(par!=NULL)
		{
			if(loc == par->left)
			{
				par->left = child;
			}
			else
			{
				par->right = child;
			}
		}
		else
		{
			root = child;
		}
	}
		
	void caseB(tree *loc, tree *par)
	{
		ptr = loc->right;
		save = loc;
		
		while(ptr->left!=NULL)
		{
			save = ptr;
			ptr = ptr->left;
		}
		
		suc = ptr;
		parsuc = save;
		caseA(suc,parsuc);
		
		if(par!=NULL)
		{
			if(loc == par->left)
			{
				par->left = suc;
			}
			else
			{
				par->right = suc;
			}
		}
		else
		{
			root = suc;
		}
		
		suc->left = loc->left;
		suc->right = loc->right;
	}

	void deleteNode(int d_item)
	{
		loc = root;
		par = NULL;
		
		while(loc!=NULL && d_item!=loc->data)
		{
			par = loc;
			if(d_item<loc->data)
			{
				loc = loc->left;
			}
			else
			{
				loc = loc->right;
			}
		}
		
		if(loc == NULL)
		{
			cout<<"Node not found";
		}
		if(loc->right!=NULL && loc->left!=NULL)
		{
			caseB(loc,par);
		}
		else
		{
			caseA(loc,par);
		}
		delete loc;
		cout<<"Node deleted";
	}
		
	//=============================================================
	void searchNode(int s_item)
	{
		ptr = root;
		while(ptr!=NULL)
		{
			if(ptr->data == s_item)
			{
				cout<<s_item<<" found";
				break;
			}
			else if(s_item>ptr->data)
			{
				ptr = ptr->right;
			}
			else
			{
				ptr = ptr->left;
			}
		}
		if(ptr == NULL)
		{
			cout<<s_item<<" not found";
		}
	}
	
	//=============================================================
	void inOrder(tree *ptr)
	{
		if(ptr!=NULL)
		{
			inOrder(ptr->left);
			cout<<ptr->data<<" ";
			inOrder(ptr->right);
		}
	}
	
	void preOrder(tree *ptr)
	{
		if(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			preOrder(ptr->left);
			preOrder(ptr->right);
		}
	}	
	
	void postOrder(tree *ptr)
	{
		if(ptr!=NULL)
		{
			postOrder(ptr->left);
			postOrder(ptr->right);
			cout<<ptr->data<<" ";
		}
	}	
	
	//=============================================================
	int depthTree(tree *ptr)
	{
		if(ptr == NULL)
		{
			return 0;
		}
		int lefth = depthTree(ptr->left);
		int righth = depthTree(ptr->right);
		
		return(max(lefth,righth)+1);
	}
	
	//=============================================================
	void mirrorTree(tree *ptr)
	{
		tree *temp;
		if(ptr!=NULL)
		{
			temp = ptr->left;
			ptr->left = ptr->right;
			ptr->right = temp;		
			
			mirrorTree(ptr->left);
			mirrorTree(ptr->right);
		}
		return;
	}
	//=============================================================
	void displayLeafNodes(tree *ptr)
	{
		if(ptr == NULL)
		{
			return;
		}
		
		if(ptr->left == NULL && ptr->right == NULL)
		{
			cout<<ptr->data<<" ";
			return;
		}
		
		if(ptr->left)
		{
			displayLeafNodes(ptr->left);
		}
		if(ptr->right)
		{
			displayLeafNodes(ptr->right);
		}
	}
};

//=============================================================
int main()
{
	BinaryTree bt;
	int item,loc,ch,i;

	do
	{
		cout<<"\n";
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Search";
		cout<<"\n4.Display tree";
		cout<<"\n5.Display depth";
		cout<<"\n6.Display mirror image";
		cout<<"\n7.Display leaf nodes";
		cout<<"\n8.Exit.";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout<<"\nEnter data to insert: ";
				cin>>item;
				bt.insertNode(item);
			    break;
			case 2: 
				cout<<"\nEnter data to delete: ";
				cin>>item;
				bt.deleteNode(item);
			    break;
			case 3:
				cout<<"\nEnter data to search: ";
				cin>>item;
				bt.searchNode(item);
				break;
			case 4:
				cout<<"\nInorder: ";
				bt.inOrder(bt.root);
				cout<<"\n=========================";
				cout<<"\nPreorder: ";
				bt.preOrder(bt.root);
				cout<<"\n=========================";
				cout<<"\nPostorder: ";
				bt.postOrder(bt.root);
				break;
			case 5:
				item = bt.depthTree(bt.root);
				cout<<"\nDepth of the tree: "<<item;
				break;
			case 6:
				bt.mirrorTree(bt.root);
				cout<<"\nInorder display of mirrored tree: ";
				bt.inOrder(bt.root);
				break;
			case 7:
				bt.displayLeafNodes(bt.root);
				break;		
		}
	}while(ch!=8);
	return 0;
}
