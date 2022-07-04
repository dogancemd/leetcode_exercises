class Solution {
public:    
    bool isPalindrome(int x) {
        string tmp=to_string(x);
        int len=tmp.length(),control=len/2;
        for(int i=0;i<control;i++){
            if(tmp[i]!=tmp[len-i-1])
                return false;
        }
        return true;
        
    }
};