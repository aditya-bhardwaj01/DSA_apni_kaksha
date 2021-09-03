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

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];c
    arr[j]=temp;
}

void recoverBST(int arr[], int n){
    int first;
    int mid;
    int last;
    bool last_found=false;
    bool first_found=false;
    for(int i=0;i<n;i++){
        if(i<(n-1) && arr[i]>arr[i+1] && !first_found){
            first=i;
            mid=i+1;
            first_found=true;
        }
        
        if(i>0 && arr[i]<arr[i-1]){
            last=i;
            last_found=true;
        }
    }
    if(last_found){
        swap(arr, first, last);
    }
    else{
        swap(arr, first, mid);
    }
}

int main()
{
    int inorder[]={1, 2, 4, 3, 5, 6, 7, 8};
    
    recoverBST(inorder, 8);
    
    for(int i=0;i<8;i++){
        cout<<inorder[i]<<" ";
    }
    
    return 0;
}

