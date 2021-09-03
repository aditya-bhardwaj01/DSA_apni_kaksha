#include <iostream>
#include <climits>
using namespace std;

int minSubarraySize(int arr[], int x, int n){
    int i=0;
    int sum=0;
    int ans;
    while(i<n && sum<=x){
        sum+=arr[i];
        i++;
    } 
    ans=i;
    int start=0;
    
    for(int j=i;j<n;j++){
        while(sum-arr[start]>x){
            //ans=min(ans, j-start+1);
            sum-=arr[start];
            start++;
            ans=min(ans, j-start);
        }
        
        sum+=arr[j];
    }
    
    cout<<sum<<endl;
    return ans;
}

int main()
{
    int arr[]={1, 4, 45, 6, 10, 19};
    
    int n=6;
    int x=51;
    cout<<minSubarraySize(arr, x, n);
    return 0;
}
