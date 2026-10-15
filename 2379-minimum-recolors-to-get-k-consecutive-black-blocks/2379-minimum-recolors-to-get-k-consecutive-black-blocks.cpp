class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(blocks[i]!='B'){
                count++;
            }
        }
        int mini=count;
        for(int i=k;i<blocks.size();i++){
            if(blocks[i]!='B'){
                count++;
            }
            if(blocks[i-k]!='B'){
                count--;
            }
            mini=min(count,mini);
        }
        return mini;
    }
};