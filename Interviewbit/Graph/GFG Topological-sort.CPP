//Q-Link https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	void dfs(int node , vector<int> &vis , stack<int> &st , vector<int> adj[] ){
	    vis[node] =1;
	    
	    for(auto x : adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int>st;
	    
	    for(int i=0;i<V;++i){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int> sorted;
	    while(!st.empty()){
	        sorted.push_back(st.top());
	        st.pop();
	    }
	    return sorted;
	}
};
