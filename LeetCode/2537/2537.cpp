class Solution {
  public:
    long long countGood(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        int tmp = 0, r = -1;
        long long ans = 0;
        for (int l = 0; l < n; l++) {
            while (tmp < k && r + 1 < n) {
                r += 1;
                tmp += cnt[nums[r]];
                cnt[nums[r]] += 1;
            }
            if (tmp >= k)
                ans += n - r;
            cnt[nums[l]] -= 1;
            tmp -= cnt[nums[l]];
        }
        return ans;
    }
};