// July 07, 23 Problem number :- 2024
class Solution {
    int f(string&s, int k ,char ch){
        int o=0, sa=0,maxi=0,j=0;
        char op = ch=='T'? 'F':'T';
        for(int i=0;i<s.size();i++){
           s[i]==op?o++:sa++;
           while(o>k && j<i) s[j++]==op?o--:sa--;
           maxi = max(maxi, i-j+1);
        }
        return maxi;
    }
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(f(s,k,'T'),f(s,k,'F'));
    }
};