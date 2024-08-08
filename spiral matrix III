class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int rl=rStart; int cl=cStart;

        int x=1;
        while(ans.size()< rows*cols){
            if(x%2==1){
                for(int i=0; i<x; i++){
                    int col=cl+1;
                    if(col < cols && col>=0 && rl < rows && rl>=0) {ans.push_back({rl, col}); }
                    cl=col;
                }
                for(int i=0; i<x; i++){
                    int row=rl+1;
                    if(row < rows && row>=0 && cl < cols && cl>=0) {ans.push_back({row, cl}); }
                    rl=row;
                }
            }
            if(x%2==0){
                for(int i=0; i<x; i++){
                    int col=cl-1;
                    if(col < cols && col>=0 && rl < rows && rl>=0) {ans.push_back({rl, col});}
                    cl=col;
                }
                for(int i=0; i<x; i++){
                    int row= rl-1;
                    if(row < rows && row>=0 && cl < cols && cl>=0) {ans.push_back({row, cl});}
                    rl=row;
                }
            
            }
            x++;
        }
        return ans;
    }
};
