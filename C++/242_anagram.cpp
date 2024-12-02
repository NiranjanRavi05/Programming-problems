/*Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> elements;
        for (auto x : s) {
            ++elements[x];
        }

        for (auto y : t) {
            --elements[y];
        }

        for (auto& z : elements) {
            if (z.second != 0) {
                return false;
            }
        }

        return true;
    }
};