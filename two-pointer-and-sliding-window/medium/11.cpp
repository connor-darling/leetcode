class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxv = INT_MIN;
        for (int i = 0; i < height.size(); ++i) {
            if (height[left] < height[right]) {
                maxv = max(maxv, ((right - left) * height[left]));
                ++left;
            } else {
                maxv = max(maxv, ((right - left) * height[right]));
                --right;
            }
        }

        return maxv;
    }
};
