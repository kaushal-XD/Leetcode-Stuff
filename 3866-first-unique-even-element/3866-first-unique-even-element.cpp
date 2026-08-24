class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mp;
        for(int n : nums){
            if(n%2 == 0) mp[n]++;
        }

        for(int n : nums){
            if (mp[n] == 1) return n;
        }
        return -1;
    }
};