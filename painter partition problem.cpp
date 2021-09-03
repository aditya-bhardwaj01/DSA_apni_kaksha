#include <iostream>
#include <climits>
using namespace std;

int findFeasible(int arr[], int n, int mid){
    int sum=0;
    int painter=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>mid){
            sum=arr[i];
            painter++;
        }
    }
    return painter;
}

int painterPartition(int arr[], int n, int m){
    int totalLength=0;
    
    int k=INT_MIN;
    for(int i=0;i<n;i++){
        totalLength+=arr[i];
        k=max(k, arr[i]);
    }
    
    int low=k;
    int end=totalLength;
    //int ans=INT_MAX;
    while(low<end){
        int mid=(low+end)/2;
        int painter=findFeasible(arr, n, mid);
        if(painter<=m){
            end=mid;
            //ans=max(ans, mid);
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main()
{
    int arr[]={12, 34, 67, 90};
    int n=4;
    int m=2;
    cout<<painterPartition(arr, 4, 2);
    return 0;
}