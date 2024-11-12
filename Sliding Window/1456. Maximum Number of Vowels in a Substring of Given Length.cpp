class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();

        int currentVowelCount = 0;
        int maxVowelCount = 0;

        int pointer = 0;

        while(pointer < n) {

            if(isVowel(s[pointer])) {
                currentVowelCount++;
            }

            if(pointer >= k && isVowel(s[pointer - k])) {
                currentVowelCount--;
            }

            pointer++;

            maxVowelCount = max(maxVowelCount, currentVowelCount);

            if(maxVowelCount == k) return maxVowelCount;
        }

        return maxVowelCount;
    }
};
