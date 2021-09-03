#include <iostream>
#include <stack> 
using namespace std;

class queue{
    stack <int> s1;
    stack <int> s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    
    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"No elements to dequeue"<<endl;
            return -1;
        }
        
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }
    
    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    cout<<qu.dequeue()<<endl;
    cout<<qu.empty()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.empty()<<endl;
    return 0;
}