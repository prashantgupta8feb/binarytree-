#include<iostream>
#include<queue>

using namespace std;
struct bstnode{
    int data;
    bstnode* left;
    bstnode* right;
   };
 bstnode* getnewnode(int x){
       bstnode* newnode = new bstnode();
       newnode->data=x;
       newnode->left=NULL;
       newnode->right=NULL;
       return newnode;
   }

bstnode* insert(bstnode* root,int data){
        if(root==NULL){
         root=getnewnode(data);
        }
        else if(data <= root->data){
            root->left=insert(root->left,data);
        }
        else{
            root->right=insert(root->right,data);
        }
        return root;
}
void inorder(bstnode* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        }
}
void preorder(bstnode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(bstnode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void levelorder(bstnode* root)
{
    if(root==NULL)
    return;
    queue<bstnode *>q;
    q.push(root);
    while(q.empty()==false)
    {
        bstnode* current=q.front();
        cout<<current->data<<" ";
        q.pop();
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
    }

}
// function to find data in the tree 
void serach(bstnode* root,int key){
    if(root->data==key){
        cout<<"\nKey is present in the BST at "<<root<<"!\n";
        
    }
    else if(root->data<key){
        serach(root->left,key);
    }
    else{
        serach(root->right,key);
    }
}
// function to find minimum node in th tree 
int findminimum(bstnode* root){
    if(root==NULL){
        cout<<"\nError : Tree is Empty !\n";
    }
    bstnode* current = root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current->data;
}
//function to find maximum node in the tree
int findmaximum(bstnode* root){
    if(root==NULL){
        cout<<"\nError : Tree is Empty !\n";
        return 0;
    }
    bstnode* current=root;
    while(current->right!=NULL){
        current=current->right;
    }
    return current->data;
}
//function to search the given key in BST
bool search(bstnode* root,int key){
    if(root==NULL){
        cout<<"\n\tError : Can't search in an Empty tree!";
        return false;
    }
    else if(key==root->data){
        cout<<"\n\t"<<key<<" is found in BST!\n";
        return true;
    }
    else if(key<root->data){
            search(root->left,key);
        }
    else{
            search(root->right,key);
        }
    }
// }
int main(){
    bstnode* root=NULL;
    root=insert(root,15);root=insert(root,10);root=insert(root,20);root=insert(root,25);
    root=insert(root,8);root=insert(root,12);root=insert(root,16);
    root=insert(root,30);root=insert(root,35);
    int max=findmaximum(root);
    cout<<"\n\tNode with Maximum key value is "<<max;
    int min=findminimum(root);
    cout<<"\n\tNode with Minimum key value is "<<min;
    cout<<"\n\tIn-Order traversal of the Binary Search Tree is: ";
    inorder(root);
    cout<<"\n\tPre-Order traversal of the Binary Search Tree is: ";
    preorder(root);
    cout<<"\n\tPost-Order traversal of the Binary Search Tree is: ";
    postorder(root);
    cout<<"\n\tLevel-Order traversal of the Binary Search Tree is: ";
    levelorder(root);
    search(root,10);
    bstnode* root1=NULL;
    search(root1,10);
    return 0;
}