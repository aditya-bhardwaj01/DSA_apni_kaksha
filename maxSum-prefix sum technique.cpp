#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int cumsum[n+1];
    cumsum[0]=0;
    for(i=1;i<=n;i++){
        cumsum[i]=cumsum[i-1]+arr[i-1];
    }
    int maxSum=INT_MIN;
    for(i=1;i<=n;i++){
        int sum=0;
        //maxSum=max(maxSum,cumsum[i]);
        for(j=1;j<=i;j++){
            sum=cumsum[i]-cumsum[j-1];
            maxSum=max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}