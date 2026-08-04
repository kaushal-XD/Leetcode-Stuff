class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> myset(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = mini+1 ; i < maxi ; i++){
            if (!myset.contains(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};