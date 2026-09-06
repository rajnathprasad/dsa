class Solution {
public:
    int solve(vector<vector<int>> &t,vector<vector<int>> &grid, int i, int j, int &m, int &n){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(t[i][j]!=0) return t[i][j];
        if(i==m-1){
            return t[i][j]= grid[i][j] + solve(t, grid, i, j+1,m, n);;
        }
        else if(j==n-1){
            return t[i][j]=grid[i][j] + solve(t, grid, i+1, j, m, n);
        }
        int down=solve(t, grid, i+1, j, m, n);
        int right=solve(t, grid, i, j+1,m, n);
        return t[i][j]=grid[i][j]+min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> t(m,vector<int> (n,0));
        return solve(t, grid, 0, 0, m ,n);
    }
};