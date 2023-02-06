class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0;
        int start = -1;
        int end = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                start = i;
                end = i;
                continue;
            }

            if (nums[i] >= left) {
                end = i;
            }
            count += end - start;
        }
        return count;
    }
};

