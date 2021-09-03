#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, * right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isIdentical(Node* root1, Node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }

    else if(root1==NULL || root2==NULL){
        return false;
    }
    
    else{
        bool cond1= root1->data==root2->data;
        bool cond2=isIdentical(root1->left, root2->left);
        bool cond3=isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}

int main()
{
    Node* root1, *root2;
    root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);

    root2=new Node(2);
    root2->left=new Node(1);
    root2->right=new Node(3);

    cout<<isIdentical(root1, root2);
    return 0;
}
