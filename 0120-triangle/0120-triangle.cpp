/*

class Solution {
    int solve(vector<vector<int>>& triangle, int i, int j, int n, int m){        
        // if(i >= n || j >= m) return 1e9/2;
        if(i == n - 1 ) return triangle[i][j];
        int down = 1e9;
        int right = 1e9;
        int left = 1e9;
        if(j + 1 >= 0 && i + 1 < n)
        left = triangle[i][j] + solve(triangle, i + 1, j + 1, n, m);
        if(i + 1 < n)
        down = triangle[i][j] + solve(triangle, i + 1, j, n, m);
        if(j + 1 < m)
        right = triangle[i][j] + solve(triangle, i, j + 1, n, m);
        return min(down,min(left, right));

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        // if(n == 1 && m == 1)return triangle[0][0];
        return solve(triangle, 0, 0, n, m);

    }
};
*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
