class Solution {
public:
    const int mod = 1e9 + 7 ;
    vector<vector<vector<int>>> memo;

    int func(int n, int a , int l){
        if(a >= 2 || l >= 3) return 0;
        if (n == 0) return 1;

        if (memo[n][a][l] != -1) return memo[n][a][l];


        int ans = func(n-1,a,0)%mod;
        ans = (ans+func(n-1,a+1,0))%mod;
        ans = (ans + func(n-1,a,l+1))%mod;
        memo[n][a][l] = ans;
        return ans;
    }
    int checkRecord(int n) {
        memo.assign(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(n,0,0);
        
    }
};