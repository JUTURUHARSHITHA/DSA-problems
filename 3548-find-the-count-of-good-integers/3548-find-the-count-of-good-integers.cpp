class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> sset;
        int power = pow(10, (n - 1) / 2);
        int skip = n % 2;
        for (int i = power; i < power * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            s += rev.substr(skip);
            long long pal = stoll(s);
            if (pal % k == 0) {
                sort(s.begin(), s.end());
                sset.insert(s);
            }
        }
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        long long res = 0;
        for (string s : sset) {
            vector<int> cnt(10, 0);
            for (char c : s) cnt[c - '0']++;
            long long total = (n - cnt[0]) * fact[n - 1];
            for (int c : cnt) {
                if (c > 1) total /= fact[c];
            }
            res += total;
        }
        return res;
    }
};