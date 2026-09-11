class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        while(i<s.size()){
            if(isupper(s[i])){
                s[i]=tolower(s[i]);
                i++;
            }else if(isalnum(s[i])){
                i++;
            }else{
                s.erase(s.begin()+i);
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