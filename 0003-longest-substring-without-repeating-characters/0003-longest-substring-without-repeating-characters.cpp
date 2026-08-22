class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        set<char> st;
        int count = 0;
        for(int j = 0 ; j < n ; j++){
            while(st.count(s[j]) != 0){
                st.erase(s[i]);
                count--;
                i++;
            }
            if (st.count(s[j]) == 0){
                st.insert(s[j]);
                count++;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};