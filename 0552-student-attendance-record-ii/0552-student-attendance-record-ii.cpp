class Solution {
public:

    int checkRecord(int n) {
        const int mod = 1e9 + 7 ;
        vector<vector<int>> dp(2, vector<int>(3,0));
        dp[0][0] = 1;

        for(int i = 1 ; i <= n ; i++){
            vector<vector<int>> tempdp(2, vector<int>(3,0));
            for(int a = 0 ; a < 2 ; a++){
                for(int l = 0 ; l < 3 ; l++){
                    if(dp[a][l] == 0) continue;

                    tempdp[a][0] = (tempdp[a][0] + dp[a][l])%mod;

                    if (a +1 < 2 ){
                        tempdp[a+1][0] = (tempdp[a+1][0] + dp[a][l])%mod;
                    }

                    if (l + 1 < 3){
                        tempdp[a][l+1] = (tempdp[a][l+1] + dp[a][l])%mod;
                    }
                }
            }
            dp = move(tempdp);
        }
        int ans = 0;
        for(int a = 0 ; a < 2 ; a++){
            for(int l = 0 ; l < 3 ; l++){
                ans = (ans + dp[a][l])%mod;
            }
        }
        return ans;
    }
};