class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int rem = k, c = 0, n = nums.size();
        stack <int> st;
        
        for(int i = 0; i<n; i++){
            if(st.empty()) {
              
              st.push(nums[i]);
            }
            else{
                c = n-i;
                while(!st.empty() && st.top()>nums[i] && c>=rem and rem<=k){
                  st.pop();
                   rem++;
                }
                  st.push(nums[i]);
                rem--;
            }
        }
        vector <int> res;
        while(st.size()>k) st.pop();
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};