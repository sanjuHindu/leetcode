class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]!=0){
            return false;

        }
        vector<pair<int,int>>pos(n*n);
        for(int row=0;row<n; row++){
            for(int col=0;col<n;col++){
                int move=grid[row][col];
                pos [move]={row,col};

            }
        }
        for(int move=1;move<n*n;move++){
            int r1=pos[move-1].first;
            int c1=pos[move-1].second;
            int r2=pos[move].first;
            int c2=pos[move].second;
            int dr=abs(r2-r1);
            int dc=abs(c2-c1);
            if(!((dr==1&&dc==2)||
            (dr==2&&dc==1))){
                return false;
            }

        }
        return true;
        
    }
};