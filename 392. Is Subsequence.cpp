class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length(), n2 = t.length();

        int s_pos = 0 , t_pos = 0;

        while(s_pos < n1 && t_pos < n2) {
            if(s[s_pos] == t[t_pos]) {
                s_pos++, t_pos++;
            } else {
                t_pos++;
            }
        }

        // check if s is traversed completely
        return s_pos == s.length() ? true : false;
    }
};
