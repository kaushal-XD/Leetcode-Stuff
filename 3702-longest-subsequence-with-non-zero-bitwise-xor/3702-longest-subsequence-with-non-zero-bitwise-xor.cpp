class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int txor = 0;
        bool flag = true;
        for(int j = 0 ; j < n ; j++){
            txor ^= nums[j];
            if (nums[j] > 0 ) flag = false;
        }
        if (txor > 0) return n;
        return flag ? 0:n-1;
    }
};