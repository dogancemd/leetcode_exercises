class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string tmp="";
        int len=s.length(),longest_substr=0,index;
        for(int i=0;i<len;i++){
            if((index=tmp.find(s[i]))==-1){
                tmp+=s[i];
            }
            else{
                if(longest_substr<tmp.length())
                    longest_substr=tmp.length();
                tmp=tmp.substr(index+1,-1);
                tmp+=s[i];
            }
        }
        if(longest_substr<tmp.length())
            longest_substr=tmp.length();
        return longest_substr;
    }
};