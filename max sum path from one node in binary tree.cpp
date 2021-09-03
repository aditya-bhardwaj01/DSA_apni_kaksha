#include <bits/stdc++.h>
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

int maxPathSumUtil(Node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    
    int left=maxPathSumUtil(root->left, ans);
    int right=maxPathSumUtil(root->right, ans);

    int max_straight=max(max(left,right)+root->data, root->data); //case-1
    int max_caseval=max(max_straight, root->data+left+right);    //case 2 and 1 compared
    ans=max(max_caseval, ans);
    
    return max_straight;
}

int maxPathSum(Node* root){
    int ans=INT_MIN;
    maxPathSumUtil(root, ans);
    
    return ans;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->right=new Node(3);
    root->right->right=new Node(5);
    cout<<maxPathSum(root);
    return 0;
}
