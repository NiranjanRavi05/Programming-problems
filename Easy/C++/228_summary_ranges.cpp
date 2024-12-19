/*You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // support variables
        vector<string> res;
        int len = nums.size(), i = 0, j;
        string tmp;
        while (i < len) {
            // moving j right after the last sequential element after i
            j = i + 1;
            while (j < len && nums[j - 1] + 1 == nums[j]) {
                cout << "j = " << j << endl;
                j++;
            }
            // composing and appending the next element to res, then settin i for the next loop
            tmp = to_string(nums[i]) + (j - i > 1 ? "->" + to_string(nums[j - 1]) : "");
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
};