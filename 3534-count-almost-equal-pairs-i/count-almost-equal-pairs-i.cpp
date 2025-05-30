class Solution {
    bool isAlmostEqual(int a,int b)
    {
        string p=to_string(a),q=to_string(b);
        for(int i=0;i<p.size();i++)
        {
            for(int j=0;j<p.size();j++)
            {
                swap(p[i],p[j]);
                if(stoi(p)==stoi(q))
                {
                    return true;
                }
                swap(p[i],p[j]);
            }
        }
        return false;
    }
public:
    int countPairs(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(isAlmostEqual(nums[i],nums[j])||isAlmostEqual(nums[j],nums[i]))
                {
                    ans++;
                }
            }
        }    
        return ans;
    }
};
