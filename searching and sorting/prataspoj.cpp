#include<bits/stdc++.h>
using namespace std;
bool isPossibleSolution(vector<int>cooksRanks,int nP,int mid){
    int currP=0;//intial cooked prata count
for(int i=0;i<cooksRanks.size();i++){
    int R=cooksRanks[i],j=1;
    int timeTaked=0;
    while(true){
        if(timeTaked+j*r<=mid){
            ++currP;
            timeTaked+=j*R;
            ++j;
        }
        else{
            break;
        }
    }
    if(currP>=nP){
        return true;
    }
}
        return false;
    

}
int minTimeToCompleteOrder(vector<int>cooksRanks,int np){
    int start=0;
    int highestRank=*max_element(cooksRanks.begin(),cooksRanks.end());
    int end=highestRank*(nP*(nP+1)/2);//for finding max time taken by cook
    int ans=-1;
    while(start<=end){
        int mid= (start+end)>>1;//>>1 means divide by 2;
        if(isPossibleSolution(cooksRanks,nP,mid)){
            ans =mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }

    }
    return ans;
}

int main() {
    int T;cin>>T;
    while(T--){
        int nP,nC;
        cin>nP>>nC;
        vector<int>cooksRanks;
        while(nC--){
            int R;cin>>R;
            cooksRanks.push_back(R);

        }
        cout<<minTimeToCompleteOrder(cooksRanks,nP)<<endl;
    }
    return 0;
 }