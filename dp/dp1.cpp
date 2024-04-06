#include<bits/stdc++.h>//knapsack problem// 2d dp question

using namespace std;
void printDp(vector<vector<int>>&dp){
    for (int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
    }
}
int solveUsingRecursion(int capacity,int wt[],int profit[],int index,int n){
    //base case// single element kaise solve kreoge uske hisab se he solve hoga base case
    // if(index==n-1 ){
        // if(wt[index]<=capacity){
        //     return profit[index];
        // }
        // else{
        //     return 0;
        // }}
        if(index>=n){
            return 0;
        }
    
    //inc //excl
    int include=0;
    if(wt[index]<=capacity){
        include=profit[index]+solveUsingRecursion(capacity-wt[index],wt,profit,index+1,n);
    }
    int exclude=0+solveUsingRecursion(capacity,wt,profit,index+1,n);
     int ans=max(include,exclude);
     return ans ;
}
int solveUsingMem(int capacity,int wt[],int profit[],int index,int n,vector<vector<int>>&dp){
    //base case// single element kaise solve kreoge uske hisab se he solve hoga base case
    // if(index==n-1 ){
        // if(wt[index]<=capacity){
        //     return profit[index];
        // }
        // else{
        //     return 0;
        // }}
        if(index>=n){
            return 0;
        }
        //already exists
        if(dp[capacity][index]!=-1){
            return dp[capacity][index];
        }
    
    //inc //excl
    int include=0;
    if(wt[index]<=capacity){
        include=profit[index]+solveUsingMem(capacity-wt[index],wt,profit,index+1,n,dp);
    }
    int exclude=0+solveUsingMem(capacity,wt,profit,index+1,n,dp);
     int ans=max(include,exclude);
     dp[capacity][index]=ans;
     cout<<" for capacity "<<capacity<<" index "<<index<<endl;
     cout<<endl<<"printing dp array"<<endl;
     printDp(dp);
     cout<<endl<<endl;
     return dp[capacity][index] ;
     }
     int solveUsingTab(int capacity,int wt[],int profit[],int n){
         vector<vector<int>>dp(capacity+1,vector<int>(n+1,0));
         //index or n indicate column 
        // for(int row=0;row<=capacity;row++){
          //  dp[row][n]=0;

        // }
         for(int i=0;i<=capacity;i++){//do variable use so 2 for loop  //i represent capacity mem me capcity se 0 horaha tha toh tab me 0 se capacity tak jayenge 
            for(int j=n-1;j>=0;j--){//index j represent //ans 0 pe banega isliye loop ulta chal rahe he 
                 int include=0;
    if(wt[j]<=i){
        include=profit[j]+dp[i-wt[j]][j+1];
    }
    int exclude=0+dp[i][j+1];
     int ans=max(include,exclude);
     dp[i][j]=ans;
            }
         }
         return dp[capacity][0];//recursion me jo intial phase pe pass he wo return krte he tabulation method me 


     }
      int solveUsingTabSp(int capacity,int wt[],int profit[],int n){
         //vector<vector<int>>dp(capacity+1,vector<int>(n+1,0));
         //index or n indicate column 
         vector<int>next(capacity+1,0);//vertical size row wala
         vector<int>curr(capacity+1,-1);

        // for(int row=0;row<=capacity;row++){
          //  next[row]=0;//represent column

         //}
         for(int j=n-1;j>=0;j--){//do variable use so 2 for loop  //i represent capacity mem me capcity se 0 horaha tha toh tab me 0 se capacity tak jayenge 
            for(int i=0;i<=capacity;i++){////index j represent //ans 0 pe banega isliye loop ulta chal rahe he 
                 int include=0;
               if(wt[j]<=i){
                include=profit[j]+next[i-wt[j]];//j+1 means next //j means curr;
            }
               int exclude=0+next[i];
               int ans=max(include,exclude);
               curr[i]=ans;
            }
            //shifting 
            next=curr;//right se left aare he 
            }
         return curr[capacity];//recursion me jo intial phase pe pass he wo return krte he tabulation method me 


     }
     //more optimse ka optimise
     int solveUsingTabSO2(int capacity,int wt[],int profit[],int n){
         //vector<vector<int>>dp(capacity+1,vector<int>(n+1,0));
         //index or n indicate column 
         vector<int>next(capacity+1,0);//vertical size row wala
         //vector<int>curr(capacity+1,-1);

        // for(int row=0;row<=capacity;row++){
          //  next[row]=0;//represent column

         //}
         for(int j=n-1;j>=0;j--){//do variable use so 2 for loop  //i represent capacity mem me capcity se 0 horaha tha toh tab me 0 se capacity tak jayenge 
            for(int i=capacity;i>=0;i--){////index j represent //ans 0 pe banega isliye loop ulta chal rahe he 
                 int include=0;
               if(wt[j]<=i){
                include=profit[j]+next[i-wt[j]];//j+1 means next //j means curr;
            }
               int exclude=0+next[i];
               int ans=max(include,exclude);
               next[i]=ans;
            }
            //shifting 
           // next=curr;//right se left aare he 
            }
         return next[capacity];//recursion me jo intial phase pe pass he wo return krte he tabulation method me 
     }
int main() {
    int capacity=50;
    int wt[]={10,20,30};
    int profit[]={60,100,120};
    int index=0;
    int n=3;
    //intialise 2d dp
    vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
   // int ans=solveUsingRecursion(capacity,wt,profit,index,n );
   //int ans=solveUsingMem(capacity,wt,profit,index,n ,dp);
   //int ans=solveUsingTab(capacity,wt,profit,n);
  // int ans =solveUsingTabSp(capacity,wt,profit,n);
    int ans =solveUsingTabSO2(capacity,wt,profit,n);
    cout<<"max profit:"<<ans<<endl;
    return 0;
 }
