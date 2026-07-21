class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        unordered_set<char> check;
        int maxi = 0;
        while(j < n){
            while(check.count(s[j])){
                check.erase(s[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
            check.insert(s[j]);
            j++;
        }
        return maxi;
    }
};