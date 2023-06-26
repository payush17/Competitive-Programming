// Q-Link - https://www.interviewbit.com/problems/commutable-islands/

//find min spanning tree prims

int Solution::solve(int n, vector<vector<int> > &B) {
    vector<pair<int,int>>adj[n+5];
    
    for(auto x:B){
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }
    
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
    vector<int>mst(n+5) , key(n+5,INT_MAX);
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        mst[node] = 1;
        pq.pop();
        
        for(auto it:adj[node]){
            int nxt_node = it.first;
            int dist = it.second;
            
            if(mst[nxt_node] == 0 && key[nxt_node] > dist){
                pq.push({dist,nxt_node});
                key[nxt_node]=dist;
            }
        }
        while (!pq.empty() && mst[pq.top().second]) pq.pop();
        
    }
    
    int ans = 0;
    
    for(int i=0 ;i <=n ;i++){
        if(key[i] != INT_MAX)
        ans += key[i];
    }
    
    return ans;
        
        
    
}





//---------------------------------------------------------------------------------------------------

vector<pair<int,int>> adj[A+1];

    for(auto it:B){

        adj[it[0]].push_back({it[1],it[2]});

        adj[it[1]].push_back({it[0],it[2]});

        

    }

     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

     pq.push({0,1});

     int visited[A+1] = {0};

     int sum=0;

     while(!pq.empty()){

         auto it = pq.top();

         int node = it.second;

         int weight = it.first;

         pq.pop();

         if(!visited[node]){

             sum+=weight;

             visited[node] = 1;

             for(auto it:adj[node]){

                 if(!visited[it.first]){

                     pq.push({it.second,it.first});

                 }

             }

         }

     }

     return sum;


