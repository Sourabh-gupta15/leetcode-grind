#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr{5,4,6,3,1};
    int n=arr.size();
    //selection sort
    for(int i=0;i<n-1;i++){
        //n-1 ko nhi lenge kyuki last wale ko compare nhi kre re 
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            //n-1 considered because it is compared
            if(arr[j]<arr[minIndex]){
                //new minimum ,then store
                minIndex=j;
            }
        }
        //swap
        swap(arr[i],arr[minIndex]);
    }
    //printing
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
}
    return 0;
 }