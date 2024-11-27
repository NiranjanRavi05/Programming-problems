/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool result = true;
        unordered_map<char, int> magazine_map;

        for (char x : magazine) {
            ++magazine_map[x];
        }

        for (char x : ransomNote) {
            if (magazine_map[x] <= 0) {
                result = false;
                break;
            }
            else {
                --magazine_map[x];
            }
        }

        return result;
    }
};
