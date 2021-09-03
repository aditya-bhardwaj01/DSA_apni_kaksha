#include <bits/stdc++.h>
using namespace std;
int hexatodecimal(string n){
    int x=1;
    int sum=0;
    for(int i=(n.size())-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            sum+=x*(n[i]-'0');
        }
        else if(n[i]>='A' && n[i]<='F'){
            sum+=x*(n[i]-'A'+10);
        }
        x*=16;
        cout<<sum<<" ";
    }
    return sum;
}

int main()
{
    string n;
    cin>>n;
    cout<<hexatodecimal(n);

    return 0;
}