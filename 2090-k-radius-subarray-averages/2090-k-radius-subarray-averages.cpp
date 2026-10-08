class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if (k == 0) return nums;
        int r = 2*k +1 ;
        int w =r;
        if(n < r) return ans;
        long long sum = 0;
        for(int i = 0 ; i < r ; i++){
            sum += nums[i];
        }
        int l = 0;
        ans[k++] = sum/w;
        while(r < n){
            sum += nums[r];
            sum -= nums[l];
            l++;r++;
            ans[k++] = sum/w;
        }
        return ans;
    }
};