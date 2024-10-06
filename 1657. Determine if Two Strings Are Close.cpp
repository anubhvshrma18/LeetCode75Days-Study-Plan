class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0); // storing the freq of characters in word1
        vector<int> freq2(26,0); // storing the freq of characters in word2

        // add the freq of char in store
        for(char ch:word1) {
            freq1[ch-'a']++;
        }
        for(char ch:word2) {
            freq2[ch-'a']++;
        }

        for(int i=0;i<26;i++) {
            if(freq1[i]!=0) {
                if(freq2[i]==0) {
                    return false;
                }
            } else if(freq1[i]==0) {
                if(freq2[i]!=0) {
                    return false;
                }
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1==freq2;


   }
};
