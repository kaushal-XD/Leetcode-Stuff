class DataStream {
public:
    int v;
    int k_mx;
    int count = 0;
    DataStream(int value, int k) {
        v = value;
        k_mx = k;
    }
    
    bool consec(int num) {
        if (v == num){
            count++;
        }
        else {
            count = 0;
        }
        return count >= k_mx;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */