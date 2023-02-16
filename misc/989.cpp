class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size() - 1;
        while (k > 0 && i >= 0) {
            int r = k % 10;
            k /= 10;

            nums[i] += r;
            if (nums[i] > 9) {
                nums[i] %= 10;
                ++k;
            }
            --i;
        }

        while (k > 0) {
            nums.insert(nums.begin(), k % 10);
            k /= 10;
        }

        return nums;
    }
};
