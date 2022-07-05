class Solution {
public:
    int reverse(int x) {
        int negativity;
        if(x==-2147483648)
            return 0;
        if(x<0){
            negativity=1;
            x=x*(-1);
        }
        else
            negativity=0;
        string tmp=to_string(x);
        int len=tmp.length(),result=0,nums[len],i=0,tmp_pow,over[10]={2,1,4,7,4,8,3,6,4,7};
        for(;i<len;i++){
            tmp_pow=pow(10,(len-i-1));
            nums[len-i-1]=x/tmp_pow;
            x%=tmp_pow;
        }
        if(len==10){
            for(i=0;i<10;i++){
                if(nums[i]>over[i])
                    return 0;
                else if(nums[i]<over[i])
                    break;}
        }
        for(i=0;i<len;i++){
            result+=nums[i]*pow(10,(len-i-1));
        }
        if(negativity)            
            return result*-1;
        else
            return result;
    }
};