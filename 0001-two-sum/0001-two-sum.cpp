class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> check;
        for(int i = 0 ; i < nums.size() ; i++){
            int a = target - nums[i] ;
            if (check.count(a)){
                return {i,check[a]};
            }
            check[nums[i]] = i;
        }
        return {};
    }
};