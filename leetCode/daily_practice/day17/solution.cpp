// -------- START --------

vector<int> adj_list;
vector visited;

// v --> The vertex to be visited next 
void dfs(int v) {
    visited[v] = true;

    for(int u : adj_list[v]){
        if(!visited[u])
            dfs(u);
    }
}

vector<int> find_critical_connections(int number_of_servers, vector<int> connections) {
    vector<int> criticalConnections;

    for(int i = 0; i < connections.size(); i++) {
        adj_list.resize(number_of_servers);
        visited.assign(number_of_servers, false);

        // Creating adjacency list representation
        // skipping i'th connection
        for(int j = 0; j < connections.size(); j++) {
            if(i == j) continue;

            int u = connections[j][0];
            int v = connections[j][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        dfs(0);

        // If all the servers were not reachable from node 0,
        // the i'th connection is a critical connection.
        for(int j = 0; j < number_of_servers; j++) {
            if(visited[j] == false) {
                criticalConnections.push_back(vector{connections[i][0], connections[i][1]});
                break;
            }
        }

        adj_list.clear();
    }

    if(criticalConnections.size() == 0) {
        criticalConnections.push_back(vector{-1, -1});
    }

    return criticalConnections;
}


// -------- END --------


// Driver Code
int main()
{
	init_code();
	vector<int> v;
	_getVector(v);


	// _printVector(v);
    return 0;
}
