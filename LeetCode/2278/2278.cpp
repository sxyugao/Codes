class Solution {
  public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (auto c : s)
            cnt += c == letter;
        return 100 * cnt / s.length();
    }
};