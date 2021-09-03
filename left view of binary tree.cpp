#include <iostream>
#include <queue>
#include <stack>
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

void leftView(Node* root){
    if(root==NULL){
        return;
    }
    
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    cout<<root->data<<" ";
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            Node* leftEle=q.front();
            cout<<leftEle->data<<" ";
            q.push(NULL);
        }
    }
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);
    
    leftView(root);
    return 0;
}