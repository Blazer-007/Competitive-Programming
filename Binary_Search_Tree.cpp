/*
    BST(Binary Search Tree) :- It is a special type of binary tree in which left subtree of a node has a value smaller
                               than that of root data and right subtree has value geater than that of root data .
                               It is followed at every node.

                               InOrder traversal of a BST is always sorted.

*/
#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

// Searching a data in BST
bool search(node *root,int data){
	if(root==NULL){
		return false;
	}
	
	if(root->data==data){
		return true;
	}
	
	// Recursively call on left and right subtree
	if(data<=root->data){
		return search(root->left,data);
	}else{
		return search(root->right,data);
	}
}

node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
}

bool isBST(node *root,int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
        return true;
    }
    return false;
}

int main(){ 
    node*root = build();
    inorder(root);
    cout<<endl;
    bfs(root);
    int val;
    cin>>val;
    if(search(root,val)){
    	cout<<"Present\n";
	}else{
		cout<<"Not Present\n";
	}
	
	int s;
    cin>>s;
    root = deleteInBST(root,s);
    inorder(root);
    cout<<endl;
    bfs(root);
    
	    if(isBST(root)){
	      cout<<"Yes";
	  }
	  else{
	      cout<<"Not a BST!";
	  }

return 0;
}











