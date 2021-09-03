#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int lowerSum=0;
    int upperSum=0;
    for(int i=0;i<n/2;i++){
        lowerSum+=arr[i];
    }
    for(int i=n/2;i<n;i++){
        upperSum+=arr[i];
    }
    
    int maxDiff=abs(upperSum-lowerSum);
    
    int evenSum=0;
    int oddSum=0;
    for(int i=0;i<n;i+=2){
        evenSum+=arr[i];
    }
    
    for(int i=1;i<n;i+=2){
        oddSum+=arr[i];
    }
    
    int minDiff=abs(evenSum-oddSum);
    
    cout<<maxDiff<<" "<<minDiff;
    
    return 0;
}