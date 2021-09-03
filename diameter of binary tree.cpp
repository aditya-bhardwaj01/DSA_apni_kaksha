#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*       1
        / \  
       2   3
      /\   /\ 
     4  5 6  7
     
*/     

pair<int,int> heightDiameter(Node* root){
    if(root==NULL){
        pair <int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    
    pair<int,int> leftans=heightDiameter(root->left);
    pair<int,int> rightans=heightDiameter(root->right);
    
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;
    
    int height=1+max(lh,rh);
    int diameter=max(lh+rh+1,max(ld,rd));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}

int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    pair<int,int> p=heightDiameter(root);
    cout<<p.first<<" "<<p.second;
    return 0;
}