#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertElements(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    
    if(val<root->data){
        root->left=insertElements(root->left, val);
    }
    else{
        root->right=insertElements(root->right, val);
    }
    return root;
}
 void inorder(Node* root){
     if(root==NULL){
         return;
     }
     
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
 }

int main()
{
    Node* root=NULL;
    root=insertElements(root, 5);
    insertElements(root, 1);
    insertElements(root, 3);
    insertElements(root, 4);
    insertElements(root, 2);
    insertElements(root, 7);
    
    //print inorder
    inorder(root);
    return 0;
}