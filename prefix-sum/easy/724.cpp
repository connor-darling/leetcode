class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
           total += nums[i];
        }

        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left += nums[i];
            if (left == total) return i;
            total -= nums[i];
        }
        return -1;
    }
}
