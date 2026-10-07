class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int min = INT_MIN;
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            if (min < arr[i]){
                min = arr[i];
                idx = i;
            }
        }
        if(idx == 0 || idx == n-1) return false;
        int j = 0;
        while(j < idx){
            if(arr[j] >= arr[j+1]) return false;
            j++;
        }
        j++;
        while(j < n){
            if(arr[j-1] <= arr[j]) return false;
            j++;
        }
        return true;
    }
};