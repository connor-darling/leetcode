class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int length = INT_MAX;

        for (int right = 0; right < nums.size(); ++right) {
            // Sum until the sum is greater than or eq the target then we have our window
            sum += nums[right];
            while (sum >= target) {
                length = min(length, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return (length == INT_MAX) ? 0 : length;
    }
};
