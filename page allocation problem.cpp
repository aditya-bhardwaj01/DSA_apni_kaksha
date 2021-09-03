#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int i=0;
    int res=0;
    
    while(res+arr[i]<=mid){
        res+=arr[i];
        i++;
    }
    
    int res1=0;
    while(i<n){
        res1+=arr[i];
        i++;
    }
    if(res1<=mid){
        return true;
    }
    return false;
}

int allocateMinimum(int arr[], int n, int m){
    int sum=0;
    if(n<m){
        return -1;
    }
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    int start=0, end=sum, ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(isPossible(arr, n, m, mid)){
            end=mid-1;
            ans=min(ans, mid);
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main()
{
    int arr[]={12, 34, 67, 90};
    int n=4;
    int m=2;
    cout<<allocateMinimum(arr, 4, 2);
    return 0;
}