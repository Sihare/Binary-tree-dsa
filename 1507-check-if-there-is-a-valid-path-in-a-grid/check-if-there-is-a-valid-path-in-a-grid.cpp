class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, -1, 1};
        char dir[] = {'D', 'U', 'L', 'R'};

        auto can = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()){
            pair<int,int> cur = q.front();
            int x = cur.first, y = cur.second;
            vis[x][y] = 1;
            q.pop();

            for(int d=0; d<4; d++){
                int nx = x + dr[d];
                int ny = y + dc[d];

                if(can(nx, ny) && !vis[nx][ny]){
                    if(dir[d] == 'R'){
                        if(grid[x][y] == 1){
                            if(grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5)
                                q.push({nx, ny});
                        }
                        if(grid[x][y] == 4 || grid[x][y] == 6){
                            if(grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5)
                                q.push({nx, ny});
                        }
                    }
                    else if(dir[d] == 'L'){
                        if(grid[x][y] == 1){
                            if(grid[nx][ny] == 1 || grid[nx][ny] == 4 || grid[nx][ny] == 6)
                                q.push({nx, ny});
                        }
                        if(grid[x][y] == 3 || grid[x][y] == 5){
                            if(grid[nx][ny] == 1 || grid[nx][ny] == 4 || grid[nx][ny] == 6)
                                q.push({nx, ny});
                        }
                    }
                    else if(dir[d] == 'U'){
                        if(grid[x][y] == 2){
                            if(grid[nx][ny] == 2 || grid[nx][ny] == 3 || grid[nx][ny] == 4)
                                q.push({nx, ny});
                        }
                        if(grid[x][y] == 5 || grid[x][y] == 6){
                            if(grid[nx][ny] == 2 || grid[nx][ny] == 3 || grid[nx][ny] == 4)
                                q.push({nx, ny});
                        }
                    }
                    else if(dir[d] == 'D'){
                        if(grid[x][y] == 2){
                            if(grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6)
                                q.push({nx, ny});
                        }
                        if(grid[x][y] == 3 || grid[x][y] == 4){
                            if(grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6)
                                q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return vis[n - 1][m - 1];
    }
};