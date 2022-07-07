class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows;
        int loop_num=(numRows-1)*2;
        if(numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            rows.push_back("");
        }
        for(int i=0;s[i]!=0;i++){
            int remainder=i%loop_num;
            if(remainder<(numRows)){
                rows[remainder]+=s[i];
            }
            else{
                rows[loop_num-remainder]+=s[i];
            }

        }
        string result="";
        for(int i=0;i<numRows;i++){
            result+=rows[i];
        }
        return result;
    }
};