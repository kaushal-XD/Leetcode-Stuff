typedef long long ll;

class Solution {
public:
    ll minCost(int m, int n, vector<vector<int>>& penalty) {
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};

        const ll INF = 1e18;
        vector<vector<vector<ll>>> dist(m,vector<vector<ll>>(n,vector<ll>(2,INF)));
        using State = tuple<ll,int,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0][1] = 1;
        pq.push({1,0,0,1});

        while(!pq.empty()){
            auto [d,r,c,parity] = pq.top();
            pq.pop();

            if (d > dist[r][c][parity]) continue;

            if (r == m-1 && c == n-1){
                return d;
            }

            int nparity = 1-parity;

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0  && nr < m && nc >= 0 && nc < n){
                    ll cost = 1LL * (nr+1)*(nc+1);
                    ll mpenalty = 0;

                    if (parity == 1 && (i == 2 || i == 3))
                        mpenalty = penalty[r][c];
                    else if (parity ==0 && (i ==0 || i == 1))
                        mpenalty = penalty[r][c];

                    ll ncost = d + cost +mpenalty;
                    if (ncost < dist[nr][nc][nparity]){
                        dist[nr][nc][nparity] = ncost;
                        pq.push({ncost,nr,nc,nparity});
                    }  
                }
            }
            ll wcost = d+penalty[r][c];
            if (wcost < dist[r][c][nparity]){
                dist[r][c][nparity] = wcost;
                pq.push({wcost,r,c,nparity});
            }
        }
        return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }
};