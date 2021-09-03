#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;
    cout<<"Enter the number of varieties: ";
    cin>>n;
    vector<vector<int>> v;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;
    
    for(int i=0;i<n;i++){
        int weight;
        int value;
        cin>>value>>weight;
        v.push_back({value, weight});
    }
    
    for(int i=0;i<n;i++){
        v[i][0]=v[i][0]/v[i][1];
    }
    
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        return a[0]>b[0];
    });
    
    int earned=0;
    int filled=0;
    int i=0;
    while(filled+v[i][1]<capacity){
        earned+=(v[i][0]*v[i][1]);
        filled+=v[i][1];
        i++;
    }
    
    earned+=(v[i][0]*(capacity-filled));
    cout<<earned<<endl;
    return 0;
}

