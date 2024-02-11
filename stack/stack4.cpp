//remove reductant brackets tc o(n);
#include<bits/stdc++.h>
using namespace std;
bool checkReductants(string &str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
char ch=str[i];
if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
    st.push(ch);
}
else if(ch==')'){
    int operatorCount=0;
    while(!st.empty()&&st.top()!='('){
    char temp=st.top();
    if(temp=='+'||ch=='-'||ch=='*'||ch=='/'){
        operatorCount++;
    }
    st.pop();
    }
    st.pop();//((a)+(a-b));
    if(operatorCount==0){
        return true;
    }

}

    }

    return false;
}
int main() {
    string str="((a+b)*(c+d))";
    bool ans =checkReductants(str);
    if(ans==true){
        cout<<"reductant brackets present "<<endl;

    }
    else{
        cout<<"not reductants brackets "<<endl;
    }
    return 0;
 }