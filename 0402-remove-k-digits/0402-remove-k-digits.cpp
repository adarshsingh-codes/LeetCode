class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            char digit=num[i];
            while(!st.empty()&&k>0&&st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0'&&ans.size()>1){
            if(ans[0]=='0'){
                ans.erase(0,1);
            }
        }
        
        if(ans==""){
            return "0";
        }
        
        return ans;
    }
};