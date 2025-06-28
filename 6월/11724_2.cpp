#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
  int n ,m;
  cin >> n >> m;
  
  vector<vector<int>> nodes(n+1);
  vector<bool> visited(n+1, false);
  stack<int> vertex;
  
  int a, b, count = 0;
  for (int i = 0; i < m; i ++){
  	cin >> a >> b;
  	nodes[a].push_back(b);
  	nodes[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++){
  	if(!visited[i]) {
  		count++;
  		visited[i] = true;
  		vertex.push(i);
  		
  		while(!vertex.empty()){
  			int current = vertex.top();
  			vertex.pop();
  			
  			for (int j = nodes[current].size() - 1; j >= 0; j--){
  				int next = nodes[current][j];
  				if(!visited[next]) {
  					visited[next] = true;
  					vertex.push(next);
				  }
			}	
		}
	}
  }
  
  cout << count;
  
  return 0;
}
