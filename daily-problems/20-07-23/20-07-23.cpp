class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
       vector<int> res;
       for(auto &a: ast){
           bool flag = true;
           while(!res.empty()&& res.back()>0&&a<0){
               if(res.back()+a<0)res.pop_back();
               else if(res.back()+a>0) {flag = false; break;}
               else {res.pop_back(); flag = false; break;}
           }
           if(flag) res.push_back(a);
       }
       return res;
    }
};