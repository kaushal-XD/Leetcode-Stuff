class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        temp[0] = nums[0];
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] <= temp[i-1]){
                temp[i] = temp[i-1] - nums[i] + 1;
                ans += temp[i];
                temp[i] += nums[i];
            }
            else temp[i] = nums[i];
        }
        return ans;
    }
};