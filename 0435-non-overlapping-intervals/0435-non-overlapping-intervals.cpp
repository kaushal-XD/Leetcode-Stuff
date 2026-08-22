class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b){
        return a[1]< b[1];
    }



    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),cmp);
        int n = in.size();
        int count = 1 ;
        int prev = 0;
        for(int i = 1 ; i < n ; i++){
            if (in[i][0]>=in[prev][1]) {
                count++;
                prev = i;
            }
        }
        return n - count;
    }
};