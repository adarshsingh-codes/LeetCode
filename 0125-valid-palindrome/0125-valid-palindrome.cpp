class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        while(i<s.size()){
            if(isalnum(s[i])){
                s[i]=tolower(s[i]);
                i++;
            }else{
                s.erase(i,1);
            }
        }
        i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};