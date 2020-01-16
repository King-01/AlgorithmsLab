#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left, *right;
	node(int a)
	{
		val = a;
		left = NULL;
		right = NULL;
	}
};
class BST{
	private:
	node* head;
	public:
	BST()
	{
		head = NULL;
	}
	void assigner(int val, int i)
	{
		if(i == 1)insert(val);
		else if(i == 2){
			int presence = present(val);
			if(presence == 1)
			{
				cout << "Element is present in BST" << endl;
			}
			else if(presence == 2) 
				cout << "Element is not present in BST" << endl;
		}
		else if(i == 3)traverse();
		else deletenode(val);
	}
	void insert(int val)
	{
		node *temp = new node(val);
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			node *pointer = head;
			while(true)
			{
				if(pointer->val >= val){
					if(pointer->left!=NULL)
						pointer = pointer->left;
					else{
						pointer->left = temp;
						break;
					}
				}
				else{
					if(pointer->right!=NULL)
						pointer = pointer->right;
					else 
					{
						pointer->right = temp;
						break;
					}
				}
			}
		}
		cout << "Insertion Successful!" << endl;
	}
	int present(int val)
	{
		if(head == NULL)
		{
			cout << "The tree is empty!" << endl;
			return 3;
		}
		node *pointer = head;
		while(true)
		{
			if(val == pointer->val)
			{
				return 2;
			}
			if(val > pointer->val)
			{
				if(pointer->right == NULL)return 1;
				pointer = pointer->right;
			}
			else{
			 if(pointer->left == NULL)return 1;
			 pointer = pointer->left; 
			}
		}
	}
	void traverse()
	{
		if(head == NULL)
		{
			cout << "The tree is empty!" << endl;
			return ;
		}
		node *pointer = head;
		stack <node*> s;
		node *cur = head;
		cout << "Tree:" << endl;
		while(cur != NULL || !s.empty())
		{
			while(cur!=NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			cout << cur->val << " ";
			cur = cur->right;
		}
		cout << endl;
	}
    void deletenode(int val)
    {
    	int ok = present(val);
    	if(ok == 1)
    	{
    		cout << "Node not in BST" << endl;
    		return;
    	}
    	else if(ok == 3)return;
    	else
    	{
    		cout<<"Node " << val << " was deleted successfully!" << endl;
    		if(head->val == val)
    		{
    			if(head->left == NULL)
    			{
    				head = head->right;
    			}
    			else 
    			{
    				if(head->right == NULL)
    					head = head->left;
    				else
    				{
    					node *replacement = head->left, *parent;
    					while(replacement->right != NULL){
    						parent = replacement;
    						replacement = replacement->right;
    					}
    					node *dummy = replacement;
    					if(replacement == head->left)
    					{
    						replacement->right = head->right;
    						head = replacement;
    						return;
    					}
    					if(replacement->left != NULL)
    						parent->right = replacement->left;
    					else
    						parent->right = 0;
    					head->val = dummy->val;
    					return;
    				}
    			}
    		}
    		else
    		{
    			node *pointer = head, *parent = head;
    			while(val != pointer->val)
    			{
    				parent = pointer;
    				if(val > pointer->val)pointer = pointer->right;
    				else
    					pointer = pointer->left;
    			}
    			if(pointer->left == NULL)
    			{
    				if(pointer->right == NULL)
    				{
    					if(parent->right == pointer)parent->right = NULL;
    					else parent->left = NULL;
    				}
    				else
    				{
    						pointer->val = pointer->right->val;
    						pointer->left = pointer->right->left;
    						pointer->right = pointer->right->right;
    				}
    			}
    			else
    			{
    				if(pointer->right == NULL)
    				{
    					pointer->val = pointer->left->val;
    					pointer->left = pointer->left->left;
    					pointer->right = pointer->left->right;
    				}
    				else
    				{
    					node *nextparent = pointer, *replacement = pointer->left;
    					while(replacement->right != NULL)
    					{
    						nextparent = replacement;
    						replacement = replacement->right;
    					}
    					if(nextparent == pointer)
    					{
    						pointer->val = replacement->val;
    						pointer->left = replacement->left;
    						return;
    					}
    					else
    					{
    						pointer->val = replacement->val;
    						replacement = replacement->left;
    						return;
    					}
    				}
    			}
    		}
    	}
    }
};
int main()
{
	cout << "---------------Welcome---------------" << endl;
	int input = 1;
	BST tree;
	int flag = 1;
	while(input-5)
	{
		if(!(flag-1)){
			cout << "Select one of the operations to execute:" << endl;
			cout << "1. Insert" << endl;
			cout << "2. Search" << endl;
			cout << "3. Inorder Traversal" << endl;
			cout << "4. Delete" << endl;
			cout << "5. Quit" << endl;
		}
		cout << "Select operations from above-";
		cin >> input;
		int val = 0;
		if(input-3&&input<5)
		{
			cout << "Enter value of the node" << endl;
			cin >> val;
		}
		if(input<5)
		tree.assigner(val, input);
		else if(input > 5){
			cout << "Invalid Input, please try again!" << endl;
			continue;
		}
		flag++;
	}
	cout << "Thank You!" << endl;
	return 0;
}	