class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j=0,len=strs.size(),should_i_break=0;
        char char_in_question;
        string result=strs[i];
        for(i=1;i<len;i++){
            for(j=0;strs[i][j]!=0&&result[j]!=0&&strs[i][j]==result[j];j++);
            result=result.substr(0,j);
        }    
        return result;
    }
};