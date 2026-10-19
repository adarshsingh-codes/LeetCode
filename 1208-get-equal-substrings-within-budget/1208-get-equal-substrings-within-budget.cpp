class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int cost=0;
        int maxi=0;
        for(int right=0;right<s.size();right++){
            cost+=abs((s[right]-'a')-(t[right]-'a'));
            while(cost>maxCost){
                cost-=abs((s[left]-'a')-(t[left]-'a'));
                left++;
            }
            maxi=max(maxi,right-left+1);
        }   
        return maxi;
    }
};