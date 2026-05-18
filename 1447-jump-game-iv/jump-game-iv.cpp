class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int ind = q.front();
                q.pop();
                if (ind == n - 1) return steps;
                if (ind + 1 < n && !visited[ind + 1]) 
                {
                    visited[ind + 1] = true;
                    q.push(ind + 1);
                }
                if (ind - 1 >= 0 && !visited[ind - 1]) 
                {
                    visited[ind - 1] = true;
                    q.push(ind - 1);
                }
                for (int newInd : mp[arr[ind]])  
                {                                
                    if (!visited[newInd]) 
                    {
                        visited[newInd] = true;
                        q.push(newInd);
                    }
                }
                
                mp[arr[ind]].clear();    
            }
            steps++;
        }
        return -1;
    }
};