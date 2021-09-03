#include <bits/stdc++.h>
using namespace std;
string binarysum(int a, int b){ //10101  11011
    string sum="";
    int carry=0;
    while(a>0){
        int x=a%10,y=b%10;
        if(x==0 && y==0){ //10101  11011
            if(carry==0){
                sum+='0';
                carry=0;
            }
            else{
                sum+='1';
                carry=0;
            }
        }
        else if((x==0 && y==1) || (x==1 && y==0)){  //10101  11011
            if(carry==0){
                sum+='1';
                carry=0;
            }
            else{
                sum+='0';
                carry=1;
            }
        }
        else{              //10101  11011
            if(carry==0){
                sum+='0';
                carry=1;
            }
            else{
                sum+='1';
                carry=1;
            }
        }
        a=a/10; b=b/10;
        cout<<sum;endl;
    }
    if(carry==1){
        sum+='1';
    }
    string str_cpy="";
    for(int i=sum.size()-1;i>=0;i++){
        str_cpy+=sum[i];
    }
    return str_cpy;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<binarysum(a,b);
    return 0;
}