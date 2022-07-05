class Solution {
public:
    int myAtoi(string s) {
        string num_s="",over="2147483647";
        int is_prev=1,len=s.length(),negativity=0,should_i_break=0,i=0,is_num_found=0,should_it_be_num=0,is_starting_zero=1;
        for(;i<len;i++){
            if(47<s[i]&&s[i]<58){
                if(is_starting_zero&&s[i]==48){
                    should_it_be_num=1;
                    is_prev=0;
                    continue;
                }
                num_s+=s[i];
                is_prev=0;
                is_num_found=1;
                should_it_be_num=1;
                is_starting_zero=0;
                continue;
            }
            else if(s[i]==' '){
                if(is_prev)
                    continue;
                else
                    break;
            }
            else if(s[i]=='-'&&!should_it_be_num){
                negativity=1;
                should_it_be_num=1;
                is_prev=0;
                continue;
            }
            else if(s[i]=='+'&&!should_it_be_num){
                should_it_be_num=1;
                is_prev=0;
                continue; 
            }
            if(is_num_found)
                break;
            return 0;
        }
        int num_len=num_s.length(),num=0;
        if(num_len>10){
            if(negativity)
                return -2147483648;
            else
                return 2147483647;
        }
        else if(num_len==10){
            for(i=0;i<9;i++){
                if(num_s[i]>over[i]){
                    if(negativity)
                        return -2147483648;
                    return 2147483647;
                }
                else if(num_s[i]<over[i]){
                    should_i_break=1;
                    break;
                }
            }
            if(!should_i_break){
                if(negativity&&num_s[i]>55)
                    return -2147483648;
                else if(!negativity&&num_s[i]>55)
                    return 2147483647;
            }
        }
        for(i=0;i<num_len;i++){
            num+=(num_s[i]-48)*pow(10,num_len-i-1);
        }
        if(negativity)
            return num*(-1);
        else
            return num;
    }
};