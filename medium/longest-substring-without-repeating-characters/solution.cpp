class Solution {
public:
    bool is_in(char character,string substring){
        for(int i=0;substring[i]!=0;i++){
            if(character==substring[i])
                return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        string tmp="";
        int longest_substr=0,i,j;
        for(i=0;s[i]!=0;i++,tmp=""){
            for(j=i;s[j]!=0;j++){
                if(is_in(s[j],tmp))
                    tmp+=s[j];
                else
                    break;
            }
            if(tmp.length()>longest_substr)
                longest_substr=tmp.length();
        }
        return longest_substr;
    }
};