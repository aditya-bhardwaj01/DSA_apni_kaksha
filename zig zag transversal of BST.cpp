#include <iostream>
#include <vector>
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

void zigZagTransversal(Node* root){
    if(root==NULL){
        return;
    }
    
    stack <Node*> currLevel;
    stack <Node*> nextLevel;
    
    bool leftToRight=true;
    currLevel.push(root);
    
    while(!currLevel.empty()){
        
        Node* temp=currLevel.top();
        currLevel.pop();
        
        if(temp){
            cout<<temp->data<<" ";
        }
        
        if(leftToRight){
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right){
                nextLevel.push(temp->right);
            }
        }
        
        else{
            if(temp->right){
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }
        
        if(currLevel.empty()){
            swap(currLevel, nextLevel);
            leftToRight=!leftToRight;
        }
    }
}

int main()
{
    /*
         12
        /   \
       9       15
      / \     /  \
     5   10  13  17
    */
    Node* root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);
    root->right->left=new Node(13);
    root->right->right=new Node(17);
    
    zigZagTransversal(root);
    
    return 0;
}
