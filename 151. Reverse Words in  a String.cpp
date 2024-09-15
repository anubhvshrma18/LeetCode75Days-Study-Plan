class Solution {
public:
    string reverseWords(string s) {
        //1st step
        reverse(s.begin(), s.end());

        // 2nd step
        int i=0, l=0, r=0, n=s.size();
        while(i<n) {

            while(i<n && s[i] != ' ') {
                s[r] = s[i];
                r++, i++;
            }

            if(l < r) {
                reverse(s.begin()+l, s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        // last step
        return s.substr(0, r-1);
    }
};
