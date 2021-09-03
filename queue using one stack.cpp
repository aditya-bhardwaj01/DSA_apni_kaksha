#include <iostream>
#include <stack> 
using namespace std;

int deq(stack <int> &s1){
    int res=s1.top();
    s1.pop();
    if(s1.empty()){
        return res;
    }
    int item=deq(s1);
    s1.push(res);
    return item;
}

class queue{
    stack <int> s1;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    
    int dequeue(){
        if(s1.empty()){
            cout<<"No elements present"<<endl;
            return -1;
        }
       
        return deq(s1);
    }
    
    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

int main(){
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
    cout<<qu.dequeue();
    return 0;
}