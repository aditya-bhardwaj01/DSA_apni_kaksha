#include <iostream>
using namespace std;

#define n 100

class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    
    void enqueue(int x){
        if(x==(n-1)){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        if(front==-1){
            front++;
            back++;
            arr[back]=x;
        }
        else{
            back++;
            arr[back]=x;
        }
    }
    
    void dequeue(){
        if(front>back || front==-1){
            cout<<"No element exists"<<endl;
        }
        front++;
    }
    
    int peek(){
        if(front>back || front==-1){
            cout<<"No element exists"<<endl;
            return -1;
        }
        return arr[front];
    }
    
    bool empty(){
        if(front>back || front==-1){
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;
    return 0;
}
