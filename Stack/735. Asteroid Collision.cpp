class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> v;
        for(auto a:A) {
            if(a>=0) {
                v.push_back(a);
            } else {
                int x = -1;
                while(v.size()>0) {
                    int t = v.back();
                    v.pop_back();
                    if(t<0) break;
                    if(t+x==0) {
                        break;
                    }
                    else if(t+x > 0) {
                        
                        v.push_back(t);
                        break;
                    }

                }
    
            }
        }
        
        return v;
    }
};