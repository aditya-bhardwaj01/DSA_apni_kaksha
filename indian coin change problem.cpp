#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector <int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int x;
    cin>>x;
    sort(a.begin(), a.end(), greater<int>());
    int ans=0;
    int sum=0;
    
    int i=0;
    while(i<n and sum<=x){
        if(a[i]<=x){
            while(sum+a[i]<=x){
                sum+=a[i];
                ans++;
            }
        }
        i++;
    }
    /* OR
    for(int i=0;i<n;i++){
        ans+=x/a[i];
        x-=x/a[i]*a[i];
    }
    */
    
    cout<<ans;

    return 0;
}