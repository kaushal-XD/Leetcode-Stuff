class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0 ;
        int j = 0;
        set<char> st;
        for(int i = 0 ; i < n ; i++){
            while(st.count(s[i])){
                st.erase(s[j]);
                j++;
            }
            if(st.count(s[i])== 0){
                st.insert(s[i]);
                int temp = i-j +1;
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};