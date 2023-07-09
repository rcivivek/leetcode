// problem number -2272
class Solution {
public:
    int largestVariance(string s) {
        vector<int> counter(26,0);
        for(char ch: s){
            counter[ch-'a']++;
        }
        int maxi =0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j || counter[i]==0 || counter[j]==0)continue;
                char major = 'a'+i;
                char minor = 'a'+j;
                int majorCount = 0;
                int minorCount = 0;

                int rMinor = counter[j];

                for(char &ch: s){
                    if(ch == major){
                        majorCount++;
                    }
                    if(ch == minor){
                        minorCount++;
                        rMinor--;
                    }

                    if(minorCount>0){
                        maxi = max(maxi, majorCount -minorCount);
                    }
                    if(majorCount<minorCount && rMinor >0){
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }
        return maxi;
    }
};