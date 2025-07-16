class Solution {
  public:
    int maximumLength(vector<int> &nums) {
        int n = nums.size(), odd = 0, even = 0, cnt = 0;
        for (auto x : nums) {
            if (x & 1) {
                cnt += 1;
                odd = max(odd, even + 1);
            } else {
                even = max(even, odd + 1);
            }
        }
        return max({odd, even, cnt, n - cnt});
    }
};