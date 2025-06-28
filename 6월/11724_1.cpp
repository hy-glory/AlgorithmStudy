#include <iostream>
#include <vector>

#define MAX 1000

using namespace std;

vector<vector<int>> nodes(MAX+1);
vector<bool> visited(MAX+1);

void DFS(int root){
	visited[root] = true;
	
	for(int i = 0 ; i < nodes[root].size(); i++){
		int next = nodes[root][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
	
}

int main() {
  int n ,m;
  cin >> n >> m;
  
  int a, b, count =0;
  for (int i = 0; i < m; i ++){
  	cin >> a >> b;
  	nodes[a].push_back(b);
  	nodes[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++){
  	if(!visited[i]) {
  		count++;
  		DFS(i);
	  }
  }
  
  cout << count;
  
  return 0;
  
}
