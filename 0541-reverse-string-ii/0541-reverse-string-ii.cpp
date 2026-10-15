class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int z=0;z<s.size();z+=2*k){
            int i=z;
            int j=min(z+k-1,n-1);
            while(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
        }
        return s;
    }
};