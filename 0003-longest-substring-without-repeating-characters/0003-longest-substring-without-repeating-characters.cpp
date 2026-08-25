class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(300,-1);
        int l = 0;
        int ans = 0;
        for(int r = 0 ; r < n ; r++){
            if(dp[s[r]] >= l){
                l = dp[s[r]]+1;
            }
        dp[s[r]] = r;
        ans = max(ans,r-l+1);
        }
        return ans;
    }
};