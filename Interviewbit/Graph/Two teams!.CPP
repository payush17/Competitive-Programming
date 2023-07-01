//Q_link : https://www.interviewbit.com/problems/two-teams/

//--------------------------BFS------------------------------------
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>adj[A+1];

    for(auto it:B) {

        adj[it[0]].push_back(it[1]);

        adj[it[1]].push_back(it[0]);

    }


    int color[A+1];

    
    for(int i=0; i<A; i++) color[i]=-1;



    queue<int>q;



    for(int i=1; i<A+1; i++) {

        // push new node into queue with color 0
        // if it is not visited yet
        if(color[i]==-1) {

            color[i]=0;

            q.push(i);
            break;

        }


        while(!q.empty()) {

            int node = q.front();

            q.pop();


            for(auto it: adj[node]) {

                // if its adjacent node is already visited 
                // and has same color then return false 

                if(color[node]==color[it]) return 0;



                // if the neighbour is unvisited give it 

                // color opposite to that of current node 

                //(using 0 and 1 to denote two colors)

                if(color[it]==-1) {

                    color[it]=1-color[node];

                    q.push(it);

                }

            }

        }

    }

    return 1; 



}


//-----------------------------DFS---------------------------
bool dfs(int node, vector <vector <int>> &adj, vector <int> &color){
    if(color[node] == -1){
        color[node] = 1;
    }
   
    for(auto child: adj[node]){
        if(color[child] == -1){
            color[child] = 1 - color[node];
            if(!dfs(child, adj, color)){
                return false;
            }
        } else if(color[child] == color[node]){
            return false;
        }
    }
   
    return true;
}

int Solution::solve(int n, vector<vector<int> > &b) {
    int m = b.size();
    vector <vector <int>> adj(n);
    vector <int> color(n, -1);
   
    for(int i = 0; i < m; i++){
        int u = b[i][0] - 1;
        int v = b[i][1] - 1;
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!dfs(i, adj, color)){
                return false;
            }
        }
    }
   
    return true;
}
