class Solution {
public:
    #define noOfChars 256
    bool isAnagram(string s, string t) {
        int count [noOfChars] = {0};
        int i;
        for(i=0;s[i] && t[i];i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        if(s[i] || t[i]){
            return false;
        }
        for(int i=0;i<noOfChars;i++){
            if(count[i]){
                return false;
            }
        }
        return true;
    }
};