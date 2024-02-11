#include<bits/stdc++.h>
using namespace std;
vector<int>nextSmallerElement(int *arr,int size,vector<int>&ans ){
    stack<int>st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
vector<int>prevSmallerElement(int *arr,int size,vector<int>&ans ){
    stack<int>st;
    st.push(-1);
    for(int i=0;i<size;i++){
        int curr=arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
int main() {
    int arr[5]={8,4,6,2,3};
    int size=5;//tc o(n);;;;;
    vector<int>ans(size);
    ans=nextSmallerElement(arr,size,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>prev(size);
    prev=prevSmallerElement(arr,size,ans);
    for(auto i:prev){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
 }