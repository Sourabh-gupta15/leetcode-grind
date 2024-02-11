#include<bits/stdc++.h>
using namespace std;
  void inserSorted(stack<int>&st,int element){//(n)
    if(st.empty()||element>st.top()){
        st.push(element);
        return ;

    }
    int temp=st.top();
    st.pop();
    //recursive call
    inserSorted(st,element);
    //backtrack
    st.push(temp);
  }
  void sortStacked(stack<int>&st){
    if(st.empty()){
        return ;            

    }
    int temp=st.top();
    st.pop();
    sortStacked(st);//(n*n)
    //backtrack
    inserSorted(st,temp);
  }
int main() {
    stack<int>st;
    int element=25;
    
    st.push(10);
    st.push(3);
    st.push(50);
    st.push(40);
    inserSorted(st,element);
    sortStacked(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();

    }
    return 0;
 }