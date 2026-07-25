class Solution {
public:
    int maxProduct(int n) {
        int d;
        int a = 0;
        int m = 0;
        while(n){
            d = n%10;
            if (d > m ) {
            a = m;
            m = d;
            }
            else if(d > a) a = d;
            n /= 10;
        }
        return a*m;
    }
};