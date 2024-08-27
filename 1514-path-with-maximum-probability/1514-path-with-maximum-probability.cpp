class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i = 0; i<succProb.size(); i++){
            succProb[i] = -log(succProb[i]);
        }
        
        vector<double>dist(n, 1e9);
        dist[start_node] = 0;
        for(int i = 0; i<n-1; i++){
            bool updated = false;
            for(int j = 0 ; j<edges.size(); j++){
                if(dist[edges[j][0]]+succProb[j]<dist[edges[j][1]]){
                    dist[edges[j][1]] = dist[edges[j][0]]+succProb[j];
                    updated = true;
                }
                if(dist[edges[j][1]]+succProb[j]<dist[edges[j][0]]){
                    dist[edges[j][0]] = dist[edges[j][1]]+succProb[j];
                    updated = true;
                }
            }
            if(!updated) break;
        }
        return exp(-dist[end_node]);
    }
};

