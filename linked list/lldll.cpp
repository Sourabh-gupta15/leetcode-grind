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

    }
    ~Node(){
        cout<<"Node with values"<<this->data<<"delete"<<endl;
    }
};
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;//temp ke sath aage bade gaya temp bhi aage badgaya and link bhi hogaya

    }
}

int getLength(Node*head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
          len++;
    }
    return len;

}
void insertAtHead(Node*&head,Node*&tail,int data){
    if(head==NULL){
        //ll is empty
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return ;
    }
    //step1
    Node*newNode=new Node(data);
//step2
    newNode->next=head;
    //step3
    head->prev=newNode;
    //step4
    head=newNode;
}
    void insertAtTail(Node*&head,Node*&tail,int data){
        if(head==NULL){
            Node*newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }
        Node*newNode=new Node(data);
        //step2
        tail->next=newNode;
        //step3
        newNode->prev=tail;
        //step4
        tail=newNode;
    }
    void insertAtPosition(int data,Node*&head,Node*&tail,int position){
        if(head==NULL){
            Node*newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }
        if(position<=1){
            insertAtHead(head,tail,data);
            return;


        }
        int len=getLength(head);
        if(position>len){
            insertAtTail(head,tail,data);
            return;

        }
        //insertion in middle
        //step1 :find prev and currr
        int i=1;
        Node*prevNode=head;
        while(i<position-1){
            prevNode=prevNode->next;
            i++;

        }
        Node*curr=prevNode->next;
        //step2
        Node*newNode=new Node(data);
        prevNode->next=newNode;//order not matter in this case.....
        newNode->prev=prevNode;
        curr->prev=newNode;
        newNode->next=curr;


    }
    void deleteNode(int position,Node*&head,Node*&tail){
        if (head==NULL){
            cout<<"null ll"<<endl;
            return ;
        }
        if(position==1){
            //want to delete the first node
            Node*temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
            return;
        }
        if(head==tail){//single elememt case
            Node*temp==head;
            delete temp;
            head =NULL;
            tail=NULL;
          return ;
        }
        int len=getLength(head);
        if(position==len){
            //delete last node
            Node*temp=tail;
            tail=tail->prev;
            temp->prev=NULL;
            tail->next=NULL;
            delete temp;
            return ;
        }
        //delete at middle
        //step1 find l curr and r
         int i=1;
         Node*left=head;
         if(i<position-1){ 
            left=left->next;
            i++;
         }
         Node*curr=left->next;
         Node*right=curr->next;
         //step2 
         left->next=right;
         //step 3
         right->prev=left;
         //step4 
         curr->next=NULL;
         curr->prev=NULL;
         delete curr;
    }


int main() {
    Node*first=new Node(10);
    Node*second=new Node(29);
    Node*third=new Node(12);
    Node*head=first;
    Node*tail=third;
    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    print(first);
    cout<<endl;
    insertAtHead(head,tail,101);
    print(head);
    cout<<endl;
     insertAtTail(head,tail,502);
     print(head);
     cout<<endl;
     insertAtPosition(1200,head,tail,1);
     print(head);
     cout<<endl;
     deleteNode(4,head,tail);
     print(head);
    return 0;
 }