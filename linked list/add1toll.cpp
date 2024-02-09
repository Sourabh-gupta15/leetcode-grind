#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(){
        this->next=NULL;

    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};
Node*reverseusingLoop(Node*&head){
        Node*prev=NULL;
        Node*curr=head;
        while(curr!=  NULL){
            Node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;


        }
        return prev;
    }

void addOne(Node*&head){
        //reverse
        head=reverseusingLoop(head);
        //add1 
        int carry=1;
        Node *temp=head;
        while(temp->next!= NULL){//last node pe ruk jao
            int totalSum=temp->data+carry;
            int digit=totalSum % 10;
            carry =totalSum/10;
            temp->data=digit;
            temp=temp->next;
            if(carry==0){
                break;
            }



        }
        //process last node 
        if(carry!=0){                                                     
        int totalSum=temp->data+carry;
        int digit=totalSum%10;
        carry=totalSum/10;
        temp->data=digit;
        if(carry!=0){
            Node*newNode=new Node(carry);
            temp->next=newNode;
        }
}
           //revrse
           head=reverseusingLoop(head);

}
 void insertAtHead(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node*newNode= new Node(data);
        head=newNode;
        tail=newNode;
        return;

    }

    Node *newNode= new Node(data);
    newNode->next=head;
    head=newNode;

    
  }
  void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }}
int main() {
     Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    //insertAtHead(head,tail,80);
   // insertAtTail(head,tail,90);
   print(head);
   cout<<endl;
   addOne(head);
   cout<<endl;
   print(head);
    
    return 0;
 }