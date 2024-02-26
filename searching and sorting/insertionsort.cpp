#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr{10,1,7,6,14,9};
    int n=arr.size();
    //insertion sort
    for(int i=1;i<n;i++){
        //step 1
        int val=arr[i];//fetching ho rahi he

        //step 2
        int j=i-1;//yaha krna jaruri he varna error show krega 
        for(;j>=0;j--){
        if(arr[j]>val){
            //shift step 3    
             arr[j+1]=arr[j];
        }
        else{
            //rukna hai
            break;
        }
        }
        //step d copy
        arr[j+1]=val;//fetching me show ho ra he arr[j]=val

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
 }