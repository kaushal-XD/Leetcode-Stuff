class Solution {
public:
    int gcd(int a , int b){
        if (b == 0) return a;
        else return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int o = n*(2+(n-1)*2)/2;
        int e = n*(2*2 + (n-1)*2)/2;
        return gcd(o,e);
    }
};