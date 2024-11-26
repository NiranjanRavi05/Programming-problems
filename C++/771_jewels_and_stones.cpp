/*
Given an integer array nums, return true if any value appears at least twice in the array, and 
return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewels_size = jewels.size();
        int stones_size = stones.size();
        int i = 0, j = 0, result = 0;

        std::multiset<char> mymultiset;
        std::multiset<char>::iterator it;
        while (i < stones_size) {
            mymultiset.insert(stones[i++]);
        }

        while (j < jewels_size) {
            cout << jewels[j] << endl;
            result += mymultiset.count(jewels[j++]);
        }

        return result;
    }
};