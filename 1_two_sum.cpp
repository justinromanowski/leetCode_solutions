class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // time complexity: O(n^2)

        // nested for loop, check the sum of every value @ every position
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                // check if sum adds to target
                if(nums[i]+nums[j]==target && i!=j)
                {
                    return{i,j};
                }
            }
        }
        return {};
        
    }
    
};