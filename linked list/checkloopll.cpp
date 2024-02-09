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
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
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
  bool checkLoop(Node*&head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
          
        }
        //check for loop 
        if(fast==slow){
            return true;
        }

    }
    return false;

  }
     void insertAtTail( Node*&head,Node*&tail,int data){
         if(head==NULL){
            //ll empty 1 node abh add hogi
            Node*newNode=new Node(data);///dynamic allocation.....
            tail=newNode;
            head=newNode;//jruri he
            return ;

        }
        Node*newNode=new Node(data);
        //connect node
       
        //ll non empty ho
        tail->next=newNode;
        //update tail;
       
        tail=newNode; 
        
      }
  Node*getStartingPoint(Node*&head){
    //check for loop
    Node*slow=head;
    Node*fast=head;
     while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
          
        }
        //check for loop 
        if(fast==slow){
            break;
        }

    }
         slow=head;
         while(slow!=fast){

         
         slow=slow->next;
         fast=fast->next;

  }
  return slow;}
  void removeLoop(Node*&head){
    Node*slow=head;
    Node*fast=head;
     while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
          
        }
        //check for loop 
        if(fast==slow){
            break;
        }

    }
         slow=head;
         while(slow!=fast){

         
         slow=slow->next;
         fast=fast->next;

  }

  Node*startPoint=slow;
  Node*temp=fast;
  while(temp->next!=startPoint){
    temp=temp->next;
  }
  temp->next=NULL;
  


  }
int main() {
    Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,80);
    insertAtTail(head,tail,90);
    
    tail->next=head->next->next;
 // print(head);
  bool ans=checkLoop(head);
  cout<<endl;
  cout<< ans <<endl;
  cout<<endl;
 head=getStartingPoint(head);
  cout<< head->data<<endl;
      removeLoop(head);
      print (head);

    return 0;
 }//o{n}..complexity