class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,1000));
        for(int i = 0 ; i < n+1 ; i ++) dp[i][0] = i ;
        for(int i = 0 ; i < m+1 ; i ++) dp[0][i] = i ;

        for(int i = 1 ; i < n+1 ; i++){
            for (int j = 1 ; j < m+1 ; j++){
                char a = word1[i-1];
                char b = word2[j-1];
                if (a == b){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }
        }
        return dp[n][m];
    }
};