class Solution {
public:
    int m,n;
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int i = 0 ; i < m ; i++) dfs(i,0,heights,pacific);
        for(int i = 0 ; i < n ; i++) dfs(0,i,heights,pacific);

        for(int i = 0 ; i < n ; i++) dfs(m-1,i,heights,atlantic);
        for(int i = 0 ; i < m ; i++) dfs(i,n-1,heights,atlantic);

        vector<vector<int>> ans;

        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }

    void dfs(int x , int y , vector<vector<int>>& heights , vector<vector<bool>>& visited){
        visited[x][y] = true;

        for(int i = 0 ; i < 4 ; i++){
            int nr = x + dr[i];
            int nc = y + dc[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(visited[nr][nc]) continue;
            if(heights[nr][nc] < heights[x][y]) continue;

            dfs(nr,nc,heights,visited);
        }

    }
};