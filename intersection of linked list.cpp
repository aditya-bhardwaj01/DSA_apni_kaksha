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

void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    node* temp2=head2;
    int count=1;
    while(count!=pos){
        temp1=temp1->next;
        count++;
    }
    
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head2, 6);
    insertAtTail(head2, 7);
    intersect(head1, head2, 3);
    display(head1);
    display(head2);
    
    
    return 0;
}
