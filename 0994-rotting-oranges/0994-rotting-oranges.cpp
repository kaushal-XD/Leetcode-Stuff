class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dr = {1,0,-1,0};
        vector<int> dc = {0,1,0,-1};

        int good_oranges = 0;

        queue<pair<int,int>> q;
        for(int r = 0 ; r < row ; r++){
            for(int c = 0 ; c < col ; c++){
                if (grid[r][c] == 2){
                    q.push({r,c});
                }
                if (grid[r][c] == 1) good_oranges++;
            }
        }
        int ans = 0 ; 
        while(!q.empty()){
            int lvl_size = q.size();
            if (good_oranges == 0) break;
            ans++;
            for(int i = 0 ; i < lvl_size ; i++){
                pair<int,int> cords = q.front();
                q.pop();
                int r = cords.first;
                int c = cords.second;
                for(int j = 0 ; j < 4 ; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        good_oranges--;
                        q.push({nr,nc});
                    }
                } 
            }
            
        }
        if (good_oranges > 0) return -1;
        return ans;
    }
};