#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=1;i<n;i+=2){
        if(arr[i]<arr[i-1]){
            swap(arr, i, i-1);
        }
        else if(arr[i+1]>arr[i]){
            swap(arr, i, i+1);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
