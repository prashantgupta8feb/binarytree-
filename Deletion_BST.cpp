#include<iostream>
using namespace std;
struct bstnode{
    int data;
    bstnode* left;
    bstnode* right;
};
 bstnode* getnewnode(int x){
       bstnode* newnode=new bstnode();
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
    else              //If key is neither greater nor smaller i.e. key==root->data then do this
    {
            // case 1 : No Child 
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                root=NULL;
                // return root;
            }
            //case 2 : 1 Child
            else if(root->left==NULL)
            {
               struct bstnode *temp=root;
                root=root->right;
                delete temp;
                // return root;
            }
            else if(root->right==NULL)
            {
                struct bstnode *temp=root;
                root=root->left;
                delete temp;
                // return root;
            }
            // case 3 : 2 children 
            else
            {
                struct bstnode *temp=findmaximum(root->left);        //or we can use minimum from root->right
                root->data=temp->data;
                root->left=DeleteNode(root->left,temp->data);
                // return root;
            }
    
    }
    return root;
}
bstnode* deletenodebst(bstnode *root,int key)
{
  if(root==NULL)
  return root;
  else if(root->data<key)
  {
      deletenodebst(root->right,key);
  }
  else if (root->data>key)
  {
      deletenodebst(root->left,key);
  }
  else
  {
      if(root->right==NULL && root->right==NULL)
      {
          delete root;
          root=NULL;
        //   return root;
      }
      else if (root->left==NULL)
      {
          bstnode* temp=root;
          root=root->right;
          delete temp;
        //   return root;
      }
      else if (root->right==NULL)
      {
          bstnode* temp=root;
          root=root->left;
          root=NULL;
        //   return root;
      }
      else
      {
          bstnode* temp=findmaximum(root->left);
          root->data=temp->data;
          root->left=deletenodebst(root->left,temp->data);
        //   return root;
      }
    }
    return root;
}

int main(){
    bstnode* root=NULL;
    root=insert(root,15);root=insert(root,10);root=insert(root,20);
    root=insert(root,25);root=insert(root,8);root=insert(root,12);
    root=insert(root,16);root=insert(root,30);root=insert(root,35);
    /*       
                  15
                /   \
             10       20
            / \      /  \
          8    12  16    25
                           \
                            30
                             \
                             35 
    */
    cout<<"In-Order : ";
    inorder(root);cout<<endl;
    cout<<"Pre-Order : ";preorder(root);cout<<endl;
    DeleteNode(root,10);deletenodebst(root,20);
    cout<<endl;
    inorder(root);cout<<endl;preorder(root);
return 0;
}