class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<bool>& visit){
        visit[node] = true;
        int neighbor = edges[node];
        if(neighbor != -1 && !visit[neighbor]){
            dist[neighbor] = 1+dist[node];
            dfs(neighbor, edges, dist, visit);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());
        vector<bool> visit1(n), visit2(n);
    dist1[node1] = 0, dist2[node2] = 0;
    dfs(node1, edges, dist1, visit1);
        dfs(node2, edges, dist2, visit2);
        int mindistnode = -1, mindisttillnow = numeric_limits<int>::max();
        for(int currnode = 0; currnode<n; currnode++){
            if(mindisttillnow>max(dist1[currnode], dist2[currnode])){
                mindistnode = currnode;
                mindisttillnow = max(dist1[currnode], dist2[currnode]);
            }
          }
        return mindistnode;
    }
};