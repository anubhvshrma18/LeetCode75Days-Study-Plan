class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a | b != c) {
            int aa = a & 0x1;
            int bb = b & 0x1;
            int cc = c & 0x1;
            if (cc == 0) {
                if (aa == 1) {count++; a--;}
                if (bb == 1) {count++; b--;}
            } else {
                if ((aa == 0) && (bb == 0)) {
                    count++; a += 1;
                }
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return count;
    }
};