// Q-Link - https://www.interviewbit.com/problems/cycle-in-directed-graph/

bool dfs(int node, vector<int>& vis, vector<int>& dfsVis, vector<int> adj[]) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto& it : adj[node]) {
        if (vis[it] == 0) {
            if (dfs(it, vis, dfsVis, adj)) return true;
        }
        else if (dfsVis[it]) return true;
    }
    dfsVis[node] = 0;
    return false;
}

int Solution::solve(int V, vector<vector<int> > &B) {
    vector<int> adj[V + 5];
    for (auto& x : B) {
        adj[x[0]].push_back(x[1]);
    }
    vector<int> vis(V + 5), dfsVis(V + 5);
    for (int i = 1; i <= V; i++) {
        if (vis[i] == 0) {
            int ans = dfs(i, vis, dfsVis, adj);
            if (ans) return true;
        }
    }
    return false;
}




//---------------------------------------------------------------------------
Using bfs kahn algo(topological)

vector<int> adj[A+1];
vector<int> indegree(A+1, 0);
queue<int> q;
for(auto i : B){
     adj[i[0]].push_back(i[1]);
}

for(int i = 1; i<=A; i++){

     for(auto it : adj[i]){
             indegree[it]++;
    }
}

for(int i = 1; i<=A; i++){
     if(indegree[i] == 0){
     q.push(i);
     }
}

int cnt = 0;
while(!q.empty()){
  int node = q.front();
  cnt++;
  q.pop();
 for(auto it : adj[node]){
  indegree[it]–;
   if(indegree[it] == 0){
     q.push(it);
    }
  }
}

if(cnt == A) return 0;
return 1;
}
