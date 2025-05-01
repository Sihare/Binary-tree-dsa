class Solution {
public:
bool solve(vector<int>& t, vector<int>& w, int pills, int strength,int mid){
    int p=0;
    multiset<int>s(begin(w),begin(w)+mid);
    for(int i=mid-1;i>=0;i--){
        int req=t[i];
        auto it=prev(s.end());
        if(*it>=req){
            s.erase(it);
        }
        else if(p>=pills){
            return false;
        }else{
            auto it1=s.lower_bound(req-strength);
            if(it1==s.end()){
                return false;
            }
            s.erase(it1);
            p++;
        }
    }
    return true;

}
    int maxTaskAssign(vector<int>& t, vector<int>& w, int pills, int strength) {
        int n=t.size();
        int m=w.size();
        sort(t.begin(),t.end());
        sort(w.begin(),w.end(),greater<int>());
        int ans=0;
        int l=0,r=min(n,m);
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(t,w,pills,strength,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};