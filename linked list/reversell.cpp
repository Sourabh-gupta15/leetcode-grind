#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    //parameterised constructor
    Node(int data){
      this->data=data;
      this->prev=NULL;
      this->next=NULL;

    }};
    void print(Node*&head){
        Node*temp=head;
        while(temp!=NULL){
            cout<< temp->data<<" ";
            temp=temp->next;

        }
    }
    void insertAtHead(Node*&head, Node*& tail,int data){//pass by refrence jruri he because real ll me changes ho rehe he
      //firstNOde
      
        //step1
         if(head==NULL){
            Node*newNode=new Node(data);
            //ll empty 1 node abh add hogi
            tail=newNode;
            head=newNode;//jruri he
            return; 
        }
        Node*newNode=new Node(data);
        //step2
        newNode->next=head;
       
        //step3
        head=newNode;
      }
      //done by recursion
    Node*reverse(Node*&prev,Node*&curr){
        //base case
        if(curr==NULL){
            //ll reverse ho chuki he
            return prev;//last me sirf prev he bachega
        }
        //1 case solve krna he then recursion will set it down
        Node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
       return reverse(prev,curr);
    }
    //done by loops
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
int main() {
    Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,20);
     insertAtHead(head,tail,2);
      insertAtHead(head,tail,30);
       insertAtHead(head,tail,210);
       insertAtHead(head,tail,12);
       print(head);
       cout<< endl;
    Node*prev=NULL;
    Node*curr=head;
    head=reverse(prev,curr);
     print(head);cout<<endl;
    head=reverseusingLoop(head);

    print(head);                    

     
    return 0;
 }