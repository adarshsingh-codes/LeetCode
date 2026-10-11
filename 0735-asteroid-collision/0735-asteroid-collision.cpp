class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            bool alive=true;
            while(!st.empty()&&st.top()>0&&asteroids[i]<0){
                int z=abs(st.top());            
                if(z>abs(asteroids[i])){
                    alive=false;
                    break;
                }
                else if(z<abs(asteroids[i])){
                    st.pop();
                }else{
                    st.pop();
                    alive=false;
                    break;
                }
            }
            if(alive){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};