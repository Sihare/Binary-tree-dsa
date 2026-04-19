class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int j=0,i=0,maxi=0;
        while(j<nums2.size()&&i<nums1.size()){
            if(nums2[j]>=nums1[i]){
                maxi=max(maxi,j-i);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return maxi;
    }
};