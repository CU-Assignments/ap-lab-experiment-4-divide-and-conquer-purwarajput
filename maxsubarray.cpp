class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
    
            // NAME: PURWA UID:22BCS13241
            
            int maxSum = nums[0];    
            int currentSum = nums[0]; 
            
            for (int i = 1; i < nums.size(); ++i) {
                currentSum = max(nums[i], currentSum + nums[i]); 
                maxSum = max(maxSum, currentSum); 
            }
            
            return maxSum;
        }
    };
