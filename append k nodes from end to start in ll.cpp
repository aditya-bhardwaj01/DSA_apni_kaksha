#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* append(node* &head, int k){
    int count=1;
    node* newhead=head;
    node* newtail;
    while(count=k){
        if(count==(k-1)){
            newtail=newhead;
        }
        count++;
        newhead=newhead->next;
    }
    node* tail=newhead;;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head;
    newtail->next=NULL;
    return newhead;
}

int main()
{
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    //display(head);
    node* newhead=append(head, 4);
    display(newhead);
    return 0;
}
