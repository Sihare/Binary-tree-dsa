bool computed = false;
vector<int> v;

class Solution {
public:
    void compute() {
        map<int, int> m;
        for (int i = 1; i <= 1000; i++) {
            for (int j = i + 1; j <= 1000; j++) {
                m[i * i * i + j * j *j]++;
            }
        }

        for (auto &[num, freq]: m) {
            if (freq > 1) v.push_back(num);
        }

        computed = true;
    }
    
    vector<int> findGoodIntegers(int n) {
        if (!computed) compute();
        vector<int> ans;
        
        for (int &num: v) {
            if (num <= n) ans.push_back(num);
            else break;
        }
        
        return ans;
    }
};