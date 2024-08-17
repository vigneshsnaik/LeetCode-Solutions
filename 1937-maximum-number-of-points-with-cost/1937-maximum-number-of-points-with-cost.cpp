class Solution {
public:
    int r, c;
    vector<vector<long long>> dp;
    vector<long long> left, right;
    long long solve(int i, int j, vector<vector<int>>& points) {
        if (i == 0)
            return dp[i][j] = points[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j == 0)
            right_left_max(i, points);
        return dp[i][j] = max(left[j], right[j]) + points[i][j];
    }
    void right_left_max(int i, vector<vector<int>>& points) {
        left[0] = solve(i - 1, 0, points);
        for (int j = 1; j < c; j++)
            left[j] = max(left[j - 1] - 1, solve(i - 1, j, points));
        right[c - 1] = solve(i - 1, c - 1, points);
        for (int j = c - 2; j >= 0; j--)
            right[j] = max(right[j + 1] - 1, solve(i - 1, j, points));
    }

    long long maxPoints(vector<vector<int>>& points) {
        r = points.size(), c = points[0].size();
        dp.assign(r, vector<long long>(c, -1));
        left.assign(c, LLONG_MIN);
        right = left;
        long long ans = 0;
        for (int j = 0; j < c; j++)
            ans = max(ans, solve(r - 1, j, points));
        return ans;
    }
};
