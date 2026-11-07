class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        for(int i=0;i<k+1;i++){
            vector<int>temp=dist;
            for(auto e:flights){
                int u=e[0];
                int v=e[1];
                int c=e[2];
                if(dist[u]!=INT_MAX&&dist[u]+c<temp[v]){
                    temp[v]=c+dist[u];
                }
            }
            dist=temp;
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};