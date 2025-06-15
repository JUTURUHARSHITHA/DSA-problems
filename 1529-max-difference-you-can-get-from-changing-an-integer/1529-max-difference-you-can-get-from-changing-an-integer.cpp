class Solution {
public:
    int maxDiff(int num) {
         string s=to_string(num);
         string maxstr=s;
         char toReplace=' ';
         for(char c:s){
            if(c!='9'){
                toReplace=c;
                break;
            }
         }
         if(toReplace!=' '){
            for(char &c:maxstr){
                if(c==toReplace)c='9';
            }
         }
         int maxnum=stoi(maxstr);
         string minstr=s;
         if(s[0]!='1'){
            char rep=s[0];
            for(char &c :minstr){
                if(c==rep)
                c='1';
            }
         }else{
            for (int i=1;i<s.size();++i){
                 if (s[i] != '0' && s[i] != '1') {
                    char rep = s[i];
                    for (char &c : minstr) {
                        if (c == rep) c = '0';
                    }
                    break;
                 }
            }
         }
         int minnum=stoi(minstr);
         return maxnum-minnum;
    }
};