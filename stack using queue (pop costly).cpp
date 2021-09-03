#include <iostream>
#include <queue>
using namespace std;

class stack{
    queue <int> q1;
    queue <int> q2;
    int N=0;
    public:
    stack(){
        N=0;
    }
    void push(int val){
        q1.push(val);
        N++;
    }
    
    void pop(){
        
        if(q1.empty()){
            return;
        }         
        
        int cpy_n=N;
        while(cpy_n!=1){
            q2.push(q1.front());
            q1.pop();
            cpy_n--;
        }
        
        q1.pop();
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
        N--;
    }
    
    int top(){
        
        if(q1.empty()){
            return -1;
        }
        
        int cpy_n=N;
        while(cpy_n!=1){
            q2.push(q1.front());
            q1.pop();
            cpy_n--;
        }
        int ans=q1.front();
        q2.push(q1.front());
        q1.pop();
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
        return ans;
    }
    
    int size(){
        return N;
    }
};

int main()
{
    stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    return 0;
}
