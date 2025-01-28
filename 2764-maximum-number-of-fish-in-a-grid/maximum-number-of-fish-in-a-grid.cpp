class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible moves
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) { // Start at a water cell
                queue<pair<int, int>> q;
                q.push({i, j});
                int fishCaught = 0;
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if (grid[r][c] > 0) { // Catch fish at current cell
                        fishCaught += grid[r][c];
                        grid[r][c] = 0; // Mark cell as caught
                    }
                    for (auto& move : moves) { // Iterate over possible moves
                        int newR = r + move[0];
                        int newC = c + move[1];
                        if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] > 0) {
                            q.push({newR, newC}); // Add new water cell to queue
                        }
                    }
                }
                maxFish = max(maxFish, fishCaught);
            }
        }
    }
    
    return maxFish;
    }
};