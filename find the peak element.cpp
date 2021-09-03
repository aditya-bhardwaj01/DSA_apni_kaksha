#include <iostream>
#include <vector>
using namespace std;

int findPeak(int arr[], int low, int high, int n){
    int mid=low+(high-low)/2;
    
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        return mid;
    }
    
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeak(arr, low, mid-1, n);
    }
    
    else{
        return findPeak(arr, mid+1, high, n);
    }
}

int main()
{
    int arr[]={0, 6, 8, 5, 7, 9};
    int n=6;
    cout<<findPeak(arr, 0, 5, 6);
    return 0;
}