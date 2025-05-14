class Solution {
public:
    static const int MOD = 1e9 + 7;
    using matrix = vector<vector<long long>>;

    matrix multiply(matrix& A, matrix& B) {
        int n = A.size();
        matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
        return result;
    }

    matrix matrixExpo(matrix base, long long power) {
        int n = base.size();
        matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            result[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            power /= 2;
        }

        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        matrix T(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                int idx = (i + j) % 26;
                T[i][idx]++;
            }
        }

        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        matrix T_exp = matrixExpo(T, t);

        vector<long long> final_freq(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                final_freq[i] = (final_freq[i] + T_exp[j][i] * freq[j]) % MOD;

        long long total = 0;
        for (int i = 0; i < 26; ++i)
            total = (total + final_freq[i]) % MOD;

        return (int)total;
    }
};
