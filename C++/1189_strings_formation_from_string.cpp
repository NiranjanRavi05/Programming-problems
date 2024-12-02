/*Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0
 
Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.*/

#include <limits.h>

class Solution {
public:
    int findMaxNumberofPattern(string text, string pattern) {
        int n = text.length(), m = pattern.length(), answer = INT_MAX;
        int freqInText[26] = { 0 }, freqInPattern[26] = { 0 };

        // Frequency of characters in text.
        for (int i = 0; i < n; i++) {
            freqInText[text[i] - 'a']++;
        }
        // Frequency of characters in pattern.
        for (int i = 0; i < m; i++) {
            freqInPattern[pattern[i] - 'a']++;
        }

        // Compare the maximum string that can be produced
        // considering one character at a time.
        for (int i = 0; i < 26; i++) {
            // Do not divide by zero.
            if (freqInPattern[i]) {
                answer = min(answer, freqInText[i] / freqInPattern[i]);
            }
        }

        return answer;
    }

    int maxNumberOfBalloons(string text) {
        string pattern = "balloon";
        return findMaxNumberofPattern(text, pattern);
    }
};

/*class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string compare = "balloon";
        int result = INT_MAX;
        unordered_map<char, int> number_of_elements;
        for(char &x:text){
            if(x=='b' || x=='a' || x=='l' || x=='o' || x=='n'){
                ++number_of_elements[x];
            }
        }

        number_of_elements['o'] = number_of_elements['o']/2;
        number_of_elements['l'] = number_of_elements['l']/2;

        for(auto &y:compare){
            cout << number_of_elements[y] << endl;
            result = min(result, number_of_elements[y]);
        }
        return result;
    }
};*/