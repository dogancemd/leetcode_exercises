class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j=0,len=strs.size(),should_i_break=0;
        char char_in_question;
        string result="";
        while(1){ 
            char_in_question=strs[0][j];
            for(i=0;i<len;i++){
                if(strs[i][j]==0){
                    should_i_break=1;
                    break;
                }
                else if(strs[i][j]==char_in_question){
                    if(i==(len-1))
                       result+=char_in_question; 
                    continue;
                }
                else{
                    should_i_break=1;
                    break;
                } 
            }
            j++;
            if(should_i_break)
                break;
        }
        return result;
    }
};