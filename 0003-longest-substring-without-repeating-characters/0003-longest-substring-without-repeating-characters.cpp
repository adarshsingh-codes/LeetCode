class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        int maxcount=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            while(left<right&&freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            maxcount=max(maxcount,right-left+1);
        }
        return maxcount;
    }
};