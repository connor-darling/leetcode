class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(); 
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++map[nums1[i] + nums2[j]];
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                count += map[-1 * (nums3[i] + nums4[j])];
            }
        }
        return count;
    }
};

// -1:1 0:1 0:2 1:1
// (-1 1, 2, 4) => 1 -1 -2 -4

// -2, 0, 1, 3, -1, 1, 2, 4, -1, 1, 2, 4, 0, 
