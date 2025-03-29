// https://leetcode.com/problems/count-special-integers/description/
// https://leetcode.cn/problems/count-special-integers/solutions/1746956/shu-wei-dp-mo-ban-by-endlesscheng-xtgx/
class Solution {
   public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.length();
        vector<vector<int>> memo(m, vector<int>(1 << 10, -1));  // -1 表示没有计算过
        auto dfs = [&](auto&& dfs, int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m) {
                return is_num;
            }
            if (!is_limit && is_num && memo[i][mask] != -1) {
                return memo[i][mask];
            }
            int res = 0;
            if (!is_num) {  // 可以跳过当前数位
                res = dfs(dfs, i + 1, mask, false, false);
            }
            int up = is_limit ? s[i] - '0' : 9;
            // 如果前面没有填数字，则必须从 1 开始（因为不能有前导零）
            for (int d = is_num ? 0 : 1; d <= up; d++) {
                if ((mask >> d & 1) == 0) {  // d 不在 mask 中，说明之前没有填过 d
                    res += dfs(dfs, i + 1, mask | (1 << d), is_limit && d == up, true);
                }
            }
            if (!is_limit && is_num) {
                memo[i][mask] = res;  // 记忆化
            }
            return res;
        };
        return dfs(dfs, 0, 0, true, false);
    }
};
