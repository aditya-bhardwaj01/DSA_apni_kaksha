#include <iostream>
#include <stack>
using namespace std;

void put_sorted(stack<int> &st, int ele){
    if(st.empty() || st.top()>ele){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    put_sorted(st, ele);
    st.push(topele);
}

void sort(stack <int> &st){
    
    if(st.empty()){
        return;
    }
    
    int ele=st.top();
    st.pop();
    sort(st);
    put_sorted(st, ele);
    
}

int main()
{
    stack <int> st;
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(5);
    
    sort(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}
