//binarysearch divide by 2 numbers imp
#include<bits/stdc++.h>
using namespace std;
int solve(int dividend,int divisor){
    int s=0;
    int ans=1;
    int e=dividend;///imp//series is going from s=0 to e=dividend
    int mid=s+(e-s)/2;
    while(s<=e){  
        //perfect solution
        if(mid*divisor==dividend){
            return mid;
        }
        //not perfect sol
        if(mid*divisor>dividend){
            //left
            e=mid-1;

        }
        else{
            //ans store
            ans = mid;
            //right search
            s=mid+1;
        
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main() {
    int dividend=22;
    int divisor=7;
    int ans =solve(dividend,divisor);
    cout<<"ans is "<<ans <<endl;
    return 0;
 }