#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
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

void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=head->next;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=even->next;
        
        even->next=odd->next;
        even=odd->next;
    }
    odd->next=evenStart;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    evenAfterOdd(head);
    display(head);
    
    return 0;
}