class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 1e9);
        prob[start_node] = 0;
        vector<vector<pair<int, double>>>adjlist(n);
        for(int i = 0; i<edges.size(); i++){
            adjlist[edges[i][0]].push_back({edges[i][1], -log(succProb[i])});
            adjlist[edges[i][1]].push_back({edges[i][0], -log(succProb[i])});
        }
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>>pq;
        
        pq.push({0, start_node});
        
        while(!pq.empty()){
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == end_node){
                return exp(-dis);
            }
            for(auto it :adjlist[node]){
                if(dis+it.second<prob[it.first]){
                    prob[it.first] = dis+it.second;
                    pq.push({dis+it.second, it.first});
                }
            }
        }
        return 0.0;
    }
};

