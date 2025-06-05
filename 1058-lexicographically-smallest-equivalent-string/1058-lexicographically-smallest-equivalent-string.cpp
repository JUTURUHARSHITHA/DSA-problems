class Solution {
public:
    string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
        int n = s1.size();
        unordered_map<char,int> m;
        vector<char> arr(n);

        for(int i=0;i<n;++i){
            if(m.find(s1[i]) == m.end()){
                m.insert({s1[i], i});
                arr[i] = s1[i];
            }
        }

        for(int i=0;i<n;++i){
            int idx = m[s1[i]], idx2 = -1;
            char temp = arr[idx];
            char curr = s2[i];

            if(m.find(curr) != m.end()){
                idx2 = m[s2[i]];
                char temp2 = arr[idx2];
                curr = temp2;
            }

            if(curr < temp){
                arr[idx] = curr;
            }

            if(idx2 != -1){
                updateGroup(idx2, idx, m);
            }

            m[s2[i]] = idx;
        }

        for(int i=0;i<baseStr.size();++i){
            if(m.find(baseStr[i]) != m.end()){
                int idx = m[baseStr[i]];
                char temp = arr[idx];
                baseStr[i] = temp;
            }
        }

        return baseStr;
    }
private:
    void updateGroup(int currValue, int update, unordered_map<char,int>& m){
        for(auto& [key, value]: m){
            if(value == currValue){
                value = update;
            }
        }
    }
};