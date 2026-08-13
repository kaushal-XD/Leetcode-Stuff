class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dr = {1,0,-1,0};
        vector<int> dc = {0,1,0,-1};
        stack<pair<int,int>> st;


        int count = 0 ;

        for(int r = 0 ; r < rows; r++){
            for(int c = 0 ; c < cols; c++){
                if (grid[r][c] == 1){
                    int temp = 1;
                    grid[r][c] = 0;
                    st.push({r,c});
                    while(!st.empty()){
                        int tr = st.top().first;
                        int tc = st.top().second;
                        st.pop();
                        for(int k = 0 ; k < 4 ; k++){
                            int nr = tr + dr[k];
                            int nc = tc + dc[k];
                            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                                grid[nr][nc] = 0;
                                temp++;
                                st.push({nr,nc});
                            }
                        }
                    }
                    count = max(temp,count);
                }
            }
        }
        return count;


    }
};