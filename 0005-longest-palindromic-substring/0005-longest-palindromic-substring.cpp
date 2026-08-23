class Solution {
public:
    string expand(int i , int j , string s){
        while (i >= 0 && j <= s.size() && s[i] == s[j] ){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            string odd = expand(i,i,s);
            if (ans.size() < odd.size()) ans = odd;
            string even = expand(i,i+1,s);
            if (ans.size() < even.size()) ans = even;
        }
        return ans;
        
    }
};