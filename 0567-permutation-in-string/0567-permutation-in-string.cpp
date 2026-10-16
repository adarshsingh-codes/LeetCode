class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        if(n1>n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
        }
        for(int j=0;j<n1;j++){
            freq2[s2[j]-'a']++;
        }
        if(freq1==freq2){
            return true;
        }
        for(int i=n1;i<n2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;
            if(freq1==freq2){
                return true;
            }
        }
        return false;
    }
};