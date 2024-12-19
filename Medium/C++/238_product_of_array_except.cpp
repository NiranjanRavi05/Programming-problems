/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), val_r = 1;
        vector<int> output(n, 1);
        output[0] = 1;
        for (int i = 1; i < n; ++i) {
            output[i] = nums[i - 1] * output[i - 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            output[j] = output[j] * val_r;
            val_r = val_r * nums[j];
        }
        return output;
    }
};