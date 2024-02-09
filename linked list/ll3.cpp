#include<bits/stdc++.h>//find middle node of linked list
using namespace std;
        class Node{
     public:
     int data;
     Node*next;
     Node(int data){
        this->data=data;
         this->next=NULL;
     }
        };  
        void print(Node*&head){
            Node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp= temp->next;
            }
        } 
      /*  Node* getMiddle(Node *&head){
            if(head==NULL){
                cout<<"ll is empty"<<endl;
                return head;

            }
            if(head->next==NULL){
                //only 1 node
                return head;
            }
            //ll has  greater than 1 node.....
            Node*slow=head;
            Node*fast=head->next;//ya 30 ans dega //or agar 40 ans chhiye toh Node*fast=head; ya hoga//
            while(slow!=NULL && fast!=NULL){
                fast=fast->next;
                if(fast!=NULL){//condition check krna padega 
                    fast=fast->next;
                    slow=slow->next; }
            }
            return slow;
        }  */
        int getLength(Node*&head){
            int len=0;
            Node*temp=head;
            while(temp!=NULL){
                temp=temp->next;
                len++;
            }
            return len;
        }
        Node*reverseKNodes(Node*&head,int k){
            if(head==NULL){
                cout<<"ll is empty"<<endl;
                return NULL;
            }
            int len= getLength(head);
            if(k>len){
                cout<<"enter valid value of k"<<endl;
                return head;//ll print head se ending tak 
            }
            //it means number of Nodes in ll >=k;
            //step1 :reverse k nodes of ll.
            Node*prev=NULL;
            Node*curr=head;
            Node*forward=curr->next;
           
            int count=0;
            while(count<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;
                count++;



            }
            //step 2;RECURSIVE CALL
            if(forward!=NULL){
                //we still have nodes left to reverse
               
                head->next=reverseKNodes(forward,k);
            }
            //step 3 print full ll after k nodes reverse
            return prev;
    
        }

int main() {
    Node*head=new Node(10);
    Node*first=new Node(20);
    Node*second=new Node(30);
    Node*third=new Node(40);
    Node*fourth=new Node(50);                                                 
    Node*fifth=new Node(60);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;
    print(head);
    cout<<endl;
//cout<<" middle node is "<<getMiddle(head)->data <<endl;
  head=reverseKNodes(head,3);
  print (head);



    return 0;
 }