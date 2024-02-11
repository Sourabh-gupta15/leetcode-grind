#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> & stri,int &element){//(n tc)
    //base case
    if(stri.empty()){
        stri.push(element);
        return;
    }
    int temp=stri.top();
    stri.pop();
    insertAtBottom(stri,element);
    //backtrack
      stri.push(temp);
}
void solve (stack<int>&st,int & pos,int &ans){
if(pos==1){
    ans= st.top();//print middle 
  //  st.pop();//for delete of middle element 
    return ;
}
//1 case hum solve krenge 
pos--;
int temp=st.top();
st.pop();
//recursion
solve(st,pos,ans);
//backtrack
st.push(temp);

}
int getMiddleElement(stack<int>st){
    int size=st.size();
    if(st.empty()){
        return -1;
    }else{int pos=0;
if(size&1){
     pos=size/2 +1;
}
else{
    pos=size/2;

}
int ans=-1;
solve(st,pos,ans);
return ans;
    }}
    void reverseStack(stack<int>&stri){
        //base case 
        if(stri.empty()){
            return ;


        }
        int temp=stri.top();
        stri.pop(); 
          reverseStack(stri);
          //backtrack
     insertAtBottom(stri,temp);
    }

int main() {
    string str="hellojee";
    stack<char>sti;
    for(int i=0;i<str.length();i++){
        char ch= str[i];
        sti.push(ch);
    }
    while(!sti.empty()){
        cout<<sti.top()<<" ";
        sti.pop();
    }
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    int mid=getMiddleElement(st);//(n tc)
    cout<<"middle element "<<mid<<endl;
    //insertion at bottom
    stack<int>stri;
    stri.push(10);
    stri.push(20);
    stri.push(110);
    int element=400;
    insertAtBottom(stri,element);
   reverseStack(stri);// t.c will be n*n;
    while(!stri.empty()){
        cout<<stri.top()<<" ";
        stri.pop();
    }
    //reverse a stack


    return 0;
 }