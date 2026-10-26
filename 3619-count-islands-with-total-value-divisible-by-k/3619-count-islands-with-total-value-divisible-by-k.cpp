class Solution {
public:
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int r,int c,int rows,int cols){
        if(r<0||r>=rows||c<0||c>=cols){
            return 0;
        }
        if(grid[r][c]==0){
            return 0;
        }
        if(visited[r][c]==true){
            return 0;
        }
        visited[r][c]=true;
        long long currentSum=grid[r][c];
        currentSum+=dfs(grid,visited,r+1,c,rows,cols);
        currentSum+=dfs(grid,visited,r-1,c,rows,cols);
        currentSum+=dfs(grid,visited,r,c+1,rows,cols);
        currentSum+=dfs(grid,visited,r,c-1,rows,cols);
        return currentSum;
    }

    int countIslands(vector<vector<int>>& grid,int k){
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int validIslandsCount=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]>0&&visited[i][j]==false){
                    long long totalValue=dfs(grid,visited,i,j,rows,cols);
                    if(totalValue%k==0){
                        validIslandsCount++;
                    }
                }
            }
        }
        return validIslandsCount;
    }
};