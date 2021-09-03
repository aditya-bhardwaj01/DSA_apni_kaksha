#include <iostream>
#include <climits>
using namespace std;

int maxSum(int arr[], int n, int k, int size){
    if(k>size){
        return -1;
    }
    
    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    
    int start=0;
    for(int i=k;i<size;i++){
        if(sum<n){
            ans=max(sum, ans);
        }
        
        sum=sum+arr[i]-arr[start];
        start++;
    }
    
    return ans;
}

int main()
{
    int arr[]={7, 5, 4, 6, 8, 9};
    
    int n=20;
    int k=3;
    int size=6;
    cout<<maxSum(arr, n, k, size);
    return 0;
}