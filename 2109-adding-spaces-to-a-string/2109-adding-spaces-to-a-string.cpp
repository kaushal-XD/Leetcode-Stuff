class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j = 0 ;

        for(int i = 0 ; i < s.size(); i++){
            if (j != spaces.size() && i == spaces[j]){
                j++;
                ans.push_back(' ');
            }
            ans.push_back(s[i]);
        }
        if (j != spaces.size()){
            ans.push_back(' ');
        }
        return ans;
    }
};