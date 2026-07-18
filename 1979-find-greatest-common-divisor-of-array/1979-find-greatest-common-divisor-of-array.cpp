class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int s = 1111 ,l = 0;
        for(int i = 0; i < n ;i++){
            if (nums[i] < s) s = nums[i];
            if (nums[i]>l) l = nums[i];
        }
        return gcd(s,l);
    }
};