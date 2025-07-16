class Solution {
  public:
    long long countBadPairs(vector<int> &nums) {
        unordered_map<int, int> cnt;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += i - cnt[nums[i] - i];
            cnt[nums[i] - i] += 1;
        }
        return res;
    }
};