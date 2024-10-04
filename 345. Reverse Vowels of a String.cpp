class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i=0,left=0,right=0,n=s.length();
        while(i<n) {
            while(i<n && s[i]!=' ') {
                s[right++]=s[i++];
            }
            if(left<right) {
                reverse(s.begin()+left, s.begin()+right);
                s[right++]=' ';
                left=right;
            }
            i++;
        }
        s.resize(right-1);
        return s;
    }
};
