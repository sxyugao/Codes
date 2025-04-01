class Solution {
  public:
#define points questions[i][0]
#define brainpower questions[i][1]
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long long> f(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0)
                f[i] = max(f[i], f[i - 1]);
            int skip = brainpower + i + 1;
            if (skip < n)
                f[skip] = max(f[skip], f[i] + points);
            ans = max(ans, f[i] + points);
        }
        return ans;
    }
};