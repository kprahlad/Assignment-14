#include<iostream>
using namespace std;
class node
{
	public:
	node* parent;
	node* left;
	node* right;
	int data;	
	node()
	{
		parent=left=right=NULL;
	}
};
class tree
{
	public:
	node * root;
	tree()
	{
		root=NULL;
	}
	void insert(int data);
	void display(node *blah);
}ob;
void tree::insert(int data)
{
	node *temp=new node;
	if(!temp) cout<<"Overflow!";
	else
	{
		temp->data=data; 
		if(root==NULL) root=temp;
		else
		{
			node *curr=root;
			int flag=1;
			while(flag)
			{
				if(curr->data<data) 
				{
					if(curr->right) curr=curr->right;
					else 
					{
						temp->parent=curr;
						curr->right=temp;
						flag=0;
					}
				}
				else 
				{
					if(curr->left) curr=curr->left;
					else
					{
						temp->parent=curr;
						curr->left=temp;
						flag=0;
					}
				}
			}
	    }  
	}
}
void tree::display(node *blah)
{
	node* curr=blah;
	if(curr)
	{
		display(curr->left);
		cout<<curr->data<<" ";
		display(curr->right);
	}
}
int main()
{
	ob.insert(1);
	ob.insert(12);
	ob.insert(-1);
	ob.insert(5);
	ob.insert(14);
	ob.insert(0);
	ob.insert(3);
	ob.insert(-8);
	ob.display(ob.root);
	return 0;
}
