#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    int ans=0;
    
    for(int i=0;i<n;i++){
        int minh=INT_MAX;
        for(int j=i;j<n;j++){
            minh=min(minh, a[j]);
            int l=j-i+1;
            ans=max(ans, minh*l);
        }
    }
    cout<<ans<<endl;
    return 0;
}
