class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqmap;
        for (char c : word) {
            freqmap[c]++;
        }

        vector<int> freq;
        for (auto& [ch, f] : freqmap) {
            freq.push_back(f);
        }

        sort(freq.begin(), freq.end());
        int n = freq.size();
        int mindel = INT_MAX;

        for (int i = 0; i < n; i++) {
            int target = freq[i];
            int maxallow = target + k;
            int del = 0;

            // Delete all chars with freq less than current target
            for (int j = 0; j < i; j++) {
                del += freq[j];
            }

            // Delete excess chars from freqs higher than allowed
            for (int j = i + 1; j < n; j++) {
                if (freq[j] > maxallow)
                    del += freq[j] - maxallow;
            }

            mindel = min(mindel, del);
        }

        return mindel;
    }
};
