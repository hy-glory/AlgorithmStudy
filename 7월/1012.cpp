#include <iostream>
#include <queue>

using namespace std;


int main(){
	int T, M, N, K, X, Y;
	
	cin >> T;
	
	for (int t = 0; t < T; t++){
		bool arr[51][51] = {false};
		bool visit[51][51] = {false};
		queue<pair<int, int>> q;
		int count = 0;
		
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++){
			cin >> X >> Y;
			arr[X][Y] = true;
		}
	
		
		for (int i=0; i < M; i++){
			for (int j=0; j < N; j++){
				if (arr[i][j] && !visit[i][j]){
					count++;
					q.push({i, j});
					visit[i][j] = true;
					
					while (!q.empty()){
						int xx = q.front().first;
						int yy = q.front().second;
						q.pop();
		
						if (xx-1 >= 0 && arr[xx-1][yy] && !visit[xx-1][yy]) {
							q.push({xx-1, yy});
							visit[xx-1][yy] = true;
						}
						if (xx+1 < M && arr[xx+1][yy] &&!visit[xx+1][yy]) {
							q.push({xx+1, yy});
							visit[xx+1][yy] = true;
						}
						if (yy-1 >= 0 && arr[xx][yy-1] &&!visit[xx][yy-1]) {
							q.push({xx, yy-1});
							visit[xx][yy-1] = true;
						}
						if (yy+1 < N && arr[xx][yy+1] &&!visit[xx][yy+1]) {
							q.push({xx, yy+1});
							visit[xx][yy+1] = true;
						}
					}
				}
			}
		}
		cout << count << '\n';
		
	}
	
	return 0;
}
