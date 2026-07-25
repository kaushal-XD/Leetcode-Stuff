class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n){
            pq.push(n%10);
            n /= 10;
        }
        int ans = 1;
        ans *= pq.top();
        pq.pop();
        ans *= pq.top();
        return ans;
    }
};