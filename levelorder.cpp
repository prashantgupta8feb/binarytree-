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
void levelorder(bstnode *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<bstnode *>Q;
    Q.push(root);
    while(!Q.empty())
    {
        bstnode* current=Q.front();
        cout<<current->data<<" ";
        Q.pop();
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
    }
    cout<<endl;
}
bstnode* findmaximum(bstnode* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
bstnode* DeleteNode(bstnode* root,int key)
{
    if(root==NULL) return root;
    else if(key<root->data)
    {
        DeleteNode(root->left,key);
    }
    else if(key>root->data)
    {
        DeleteNode(root->right,key);
    }
    else
    {
            // case 1 : No Child 
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                root=NULL;
                return root;
            }
            //case 2 : 1 Child
            else if(root->left==NULL)
            {
                struct bstnode *temp=root;
                root=root->right;
                delete temp;
                return root;
            }
            else if(root->right==NULL)
            {
                struct bstnode *temp=root;
                root=root->left;
                delete temp;
                return root;
            }
            // case 3 : 2 children 
            else
            {
                struct bstnode *temp=findmaximum(root->left);
                root->data=temp->data;
                root->left=DeleteNode(root->left,temp->data);
                return root;
            }
    
    }
}
int main(){
    bstnode* root=NULL;
    root=insert(root,15);root=insert(root,10);root=insert(root,20);
    root=insert(root,8);root=insert(root,12);root=insert(root,16);
    root=insert(root,30);root=insert(root,35);root=insert(root,25);
    inorder(root);
    cout<<endl;
    levelorder(root);
    DeleteNode(root,10);DeleteNode(root,20);
    cout<<endl;
    inorder(root);
return 0;
 }