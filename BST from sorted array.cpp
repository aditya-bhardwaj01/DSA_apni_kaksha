#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* bstFromArray(int arr[], int l, int e){
    if(l>e){
        return NULL;
    }
    
    int mid=(l+e)/2;
    Node* root=new Node(arr[mid]);
    root->left=bstFromArray(arr, l, mid-1);
    root->right=bstFromArray(arr, mid+1, e);
    
    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[]={10,20,30,40,50};
    Node* root=bstFromArray(arr, 0, 4);
    preorder(root);
    

    return 0;
}
