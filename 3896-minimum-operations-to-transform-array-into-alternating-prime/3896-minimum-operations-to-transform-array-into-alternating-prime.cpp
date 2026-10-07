class Solution {
public:
    vector<bool> isprime;
    vector<int> sp;
    
    void precompute(){
        int maxn = 100015;
        isprime.assign(maxn, true);
        sp.assign(maxn, 0);
        isprime[0] = isprime[1] = false;
        for(int i = 2 ; i*i <maxn ; i++){
            if(isprime[i]){
                for(int j = i*i ; j <maxn ; j += i){
                    isprime[j] = false;
                }
            }
        }
        int p = maxn-1;
        while(!isprime[p])p--;

        for(int i = maxn-1; i >= 0 ; i--){
            if(isprime[i]){
                p = i;
            }
            sp[i] = p;
        }
    }

    int minOperations(vector<int>& nums) {
        precompute();
        int ct = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i%2 == 0){
                if(!isprime[nums[i]]){
                    ct += (sp[nums[i]] - nums[i]);
                }
            }
            else {
                if (nums[i] == 2) ct += 2;
                else if(isprime[nums[i]]){
                    ct += 1;
                }
            }
        }
        return ct;
    }
};