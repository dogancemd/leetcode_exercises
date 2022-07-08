class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.length(),tmp_len;
        for(int i=0;i<len;i++){
            s[i]=tolower(s[i]);
        }
        for(int i=0;s[i]!=0;){
            if(iswalnum(s[i])){
                i++;
            }
            else{
                s.erase(i,1);
            }
        }
        len=s.length(),tmp_len=len/2;
        for(int i=0;i<tmp_len;i++){
            if(s[i]!=s[len-i-1])
                return false;
        }
        return true;
    }
};