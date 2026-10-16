class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=p.size();
        int n2=s.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        if(n1>n2){
            return {};
        }
        for(int i=0;i<n1;i++){
            freq1[p[i]-'a']++;
        }
        for(int j=0;j<n1;j++){
            freq2[s[j]-'a']++;
        }
        vector<int> ans;
        if(freq1==freq2){
            ans.push_back(0);
        }
        for(int i=n1;i<n2;i++){
            freq2[s[i]-'a']++;
            freq2[s[i-n1]-'a']--;
            if(freq1==freq2){
                ans.push_back(i-n1+1);
            }
        }
        return ans;
    }
};