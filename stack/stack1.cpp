#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;
    Stack(int size ){
        arr=new int [size];
        this->size=size;
        this->top=-1;

    }
    void push(int data){
        if(top==size-1){
            cout<<"stack overflow"<<endl;
            return ;
        }
        else{
        top++;
        arr[top]=data;
    }}
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        else{
        top--;
    }}
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int getTop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int getSize(){
        return top+1;
    }
    void print(){
        cout<<"top"<<top<<endl;
        cout<<"top element "<<getTop()<<endl;
        cout<<" stack "<<endl;
        for(int i=0;i<getSize();i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main() {
Stack st(8);
st.push(10);
st.print();
st.push(20);
st.print();
st.push(30);
st.pop();
st.pop();
st.pop();
st.print();
cout<<st.getTop()<<endl;
cout<<st.getSize()<<endl;


    return 0;
 }