class Solution {
public:
    int are_edges_same(char front,char end){
        return front!='\n'&&end!=0&&front==end;
    }
    string longestPalindrome(string s) {
        s='\n'+s;
        int len=s.length(),longest_sbstr=0,counter,tmp_len=0;
        string tmp,result;
        for(int i=1;i<len;i++,counter=0){
            while(are_edges_same(s[i-counter],s[i+counter]))
                counter++;
            tmp=s.substr(i-counter+1,2*(counter-1)+1);
            tmp_len=tmp.length();
            if(tmp_len>longest_sbstr){
                result=tmp;
                longest_sbstr=tmp_len;
            }
        }
        for(int i=1;i<len;i++,counter=0){
            while(are_edges_same(s[i-counter],s[i+1+counter]))
                counter++;
            tmp=s.substr(i-counter+1,2*(counter-1)+2);
            tmp_len=tmp.length();
            if(tmp_len>longest_sbstr){
                result=tmp;
                longest_sbstr=tmp_len;
            }
        }
        return result;
    }
};