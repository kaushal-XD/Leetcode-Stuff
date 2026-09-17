class Solution {
public:
    long long pow(long long num, long long p, long long m){
        if (p == 0) return 1;
        long long temp = pow(num,p/2,m)%m;
        if (p%2==0) return (temp*temp)%m;
        else return ((num%m)*(temp)*(temp))%m;
    }
    int countGoodNumbers(long long n) {
        long long m = 1e9+7;
        if (n%2 == 0) return (pow(5,n/2,m)*pow(4,n/2,m))%m;
        else return (pow(5,n/2 +1,m)*pow(4,n/2,m))%m;

    }
};