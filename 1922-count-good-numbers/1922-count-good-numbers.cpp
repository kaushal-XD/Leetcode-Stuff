class Solution {
public:
    long long pow(long long num, long long p){
        long long m = 1e9+7;
        if (p == 0) return 1;
        long long res = 1;
        num%=m;

        while(p > 0){
            if(p&1) res = (res*num)%m;
            num = (num*num)%m;
            p>>=1;
        }
        return res%m;
        
    }
    int countGoodNumbers(long long n) {
        long long m = 1e9+7;
        if (n%2 == 0) return (pow(5,n/2)*pow(4,n/2))%m;
        else return (pow(5,n/2 +1)*pow(4,n/2))%m;
    }
};