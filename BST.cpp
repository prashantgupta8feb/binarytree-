//binary search tree implementation
#include<iostream>
#include<queue>
using namespace std;
//tree definition
struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};
//function to create a new node if tree is empty
bstnode* getnewnode(int data){
	bstnode* newnode = new bstnode();
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}
//funtion to insert the value in tree
bstnode* insert(bstnode* root,int data){
	if(root == NULL){
		root = getnewnode(data);
	}
	else if(data <= root->data) {
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	} 
	return root;
}
//function to find the data in the tree
bool search(bstnode* root,int data){
	if(root == NULL) {
	return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data<=root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}
//function to find minimum node of tree
int FindMin(bstnode* root){
	if(root==NULL){
		cout<<"ERROR : Tree is Empty\n";
		return 0;
		}
	bstnode* current= root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current->data;
}
//function to find maximum node of tree
int FindMax(bstnode* root){
	bstnode* current=root;
	if(root==NULL){
		cout<<"Tree is empty\n";
	}
	do{
		current=current->right;
		}while(current->right!=NULL);
		return current->data;
}
//function to find the height
int FindHeight(bstnode* root){
	if(root==NULL){
		return -1;
	}
	return max(FindHeight(root->left),FindHeight(root->right))+1; //how this line is working?-
}
//function to tell BFS(Breadth-First_Search) order
void LevelOrder(bstnode *root){
	if(root == NULL) return;
	queue<bstnode*> Q;
	Q.push(root);
	while(!Q.empty()){
		bstnode* current = Q.front();
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
} 
int main()
{
	bstnode* root = NULL;
	root=insert(root,15); root=insert(root,10); root=insert(root,20); 
	root=insert(root,25); root=insert(root,8); root=insert(root,12);
	root=insert(root,16); root=insert(root,30);root=insert(root,35);
	// cout<<root->data<<"\t"<<root->left->data<<"\t"<<root->right->data<<endl;
	int num,min,maximum,height;
	min=FindMin(root);
	maximum=FindMax(root);
	height=FindHeight(root);
	cout<<"MINIMUM node value is : "<<min<<endl;
	cout<<"MAXIMUM node value is :"<<maximum<<endl;
	cout<<"Height of tree is :"<<height<<endl;
	cout<<"BFS Order :"; LevelOrder(root);
	cout<<"\nEnter number to search : ";
	cin>>num;
	if(search(root,num)==true) cout<<"Found!\n" ;
	else cout<<"Not Found!\n";
	return 0;
}
