class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int k=nums[0];
        for(int i=1;i<nums.size();i++){
            k^=nums[i];
        }
        int bit=0;
        for(int i=0;i<32;i++){
            if(k&(1<<i)){
                bit=i;
                break;
            }
        }
        int first = 0;
	for (int a: nums) {
		if (a & (1<<bit)) {
			first ^= a;
		}
	}
 	int second = first^k;
	return {first, second};
    }
};