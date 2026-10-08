class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        
        int m = nums[n/2];
        for(int i = 0 ; i < n ; i++){
            ans += abs(m-nums[i]);
        }

        return ans;
    }
};