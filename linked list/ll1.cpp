#include<bits/stdc++.h>//insertion and deletion 
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){//constructor
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){//write code here
     cout<<"node with value"<<this->data<<"deleted"<<endl;                                
    }
};
   /* void print(Node*&head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }*/
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
      //inserrt  a node right at end of ll;

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
       void print(Node*&head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }}
          int findLength(Node*&head){
            int len=0;
            Node*temp=head;
            while(temp!=NULL){
                temp=temp->next;
                len++;
            }
            return len;
          }
       
        void insertAtPosition(int data,int position,Node*&head,Node*&tail){
          if(head==NULL){
            Node*newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return ;
          }
          //find position prev & curr;
          if(position==0){
            insertAtHead(head,tail,data);
            return ;
          }
          int len=findLength(head);
          if(position>=len){
            insertAtTail(head,tail,data);
            return;
          }
          int i=1;
          Node*prev=head;
          while(i<position){
            prev=prev->next;
            i++;
          }
          Node*curr=prev->next;                                                    
          //step2;
          Node* newNode=new Node(data);     
          //step 3;
          newNode->next=curr;
          //step4
          prev->next=newNode;                                                                                     

        }
        void deleteNode(int position,Node*&head,Node*&tail){
            if(head==NULL){
                cout<<"cannot delete,ll empty";
                return ;
            }
            //single element case
            if(head==tail){
              Node*temp=head;
              delete temp;
              head=NULL;
              tail=NULL;
              return ;
            }

            if(position==1){
                Node*temp=head;
                head=head->next;
                temp->next=NULL;
                delete temp;
                return;
            }
        
            int len=findLength(head);
            //deleting last node .....
            if(position==len){
                
                Node*prev=head;
                while(prev->next!=tail){
                    prev=prev->next;
                    
                }

                prev->next= NULL;
                Node*temp=tail;
                tail=prev;
                delete temp; 
                return ;          }
        
        //delting middle node
        int i=1;
        Node*prev=head;
        while(i< position-1){
            prev=prev->next;
            i++;
        }
        Node*curr=prev->next;
        //step2 
        prev->next=curr->next;
        //step3
        curr->next=NULL;
  //step 4

         delete curr;
    
        }



int main() {
    
   // new node
   /* Node*first=new Node(10);
    Node*second =new Node(20);
    Node *third=new Node(30);
    Node *fourth= new Node(40);
    Node* fifth=new Node(50);
//node links
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    cout<<"printing the ll"<<endl;
    print(first);*/
    Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,20);
     insertAtHead(head,tail,2);
      insertAtHead(head,tail,30);
       insertAtHead(head,tail,210);
       insertAtHead(head,tail,12);
       print(head);
       cout<<"head:"<<head->data<<endl;//shows head kaha he .....
       cout<<"tail;"<<tail->data<<endl;//shows tail kaha he..... 
       insertAtPosition(100,3,head,tail);
       cout<<"print after insert at "<<endl;
       
       print(head);
       cout<<endl;
       deleteNode(3,head,tail);
       print(head);

    return 0;



 }