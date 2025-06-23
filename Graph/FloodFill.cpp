#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isSafe(int i, int j, int oldcolor, vector<vector<int>>& image,
                vector<vector<int>>& ans, map<pair<int, int>, bool>& visited) {
        int n = image.size();
        int m = image[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m &&
                ans[i][j] == oldcolor && !visited[{i, j}]);
    }

    void dfs(int oldcolor, int newcolor, map<pair<int, int>, bool>& visited,
             vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc) {
        visited[{sr, sc}] = true;
        ans[sr][sc] = newcolor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if (isSafe(newX, newY, oldcolor, image, ans, visited)) {
                dfs(oldcolor, newcolor, visited, ans, image, newX, newY);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int oldcolor = image[sr][sc];
        if (oldcolor == color) return ans; // No need to fill if color is same
        map<pair<int, int>, bool> visited;
        dfs(oldcolor, color, visited, ans, image, sr, sc);
        return ans;
    }
};

// Optional: Test case
int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    // Print the result
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
