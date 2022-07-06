class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,len=nums.size();
        vector<int> result;
        for(i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};