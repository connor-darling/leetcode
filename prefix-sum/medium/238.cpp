class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       std::vector<int> preProduct(nums.size(), 1);
       int product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            preProduct[i] *= product;
            product *= nums[i];
        }

        product = 1;
        for (int j = nums.size()-1; j >= 0; --j) {
            preProduct[j] *= product;
            product *= nums[j];
        }

        return preProduct;
    }
};
