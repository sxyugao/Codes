class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int ans = 0;
        vector<int> l(n);
        l[0] = height[0];
        for (int i = 1; i < n; i++) {
            l[i] = max(l[i - 1], height[i]);
        }
        int r = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r = max(r, height[i]);
            ans += min(l[i], r) - height[i];
        }
        return ans;
    }
};