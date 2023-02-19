class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // calculate the sum of all elements in nums
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // iterate through each element and calculate the result
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            // Calculate the sum of absolute differences for the i-th element
            int leftSum = i * nums[i] - prefixSum;
            int rightSum = sum - prefixSum - nums[i];
            int absoluteDiffSum = leftSum + rightSum - (n - i - 1) * nums[i];
            
            // Store the result for the i-th element
            result[i] = absoluteDiffSum;
            
            // Update prefixSum for the next iteration
            prefixSum += nums[i];
        }

        return result;
    }
};
