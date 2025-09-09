#include <iostream>

using namespace std;
int N, M;
int mat[1025][1025];
int sumXF[1025][1025];
int x1, y1, x2, y2;

long long sol(int a1, int b1, int a2, int b2) {
	long long result = 0;
	for (int a = a1; a <= a2; a++) {
		result += (sumXF[a][b2] - sumXF[a][b1-1]);
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j =1; j <= N; j++) {
			cin >> mat[i][j];
			if (j == 1) {
				sumXF[i][j] = mat[i][j];
			}
			else {
				sumXF[i][j] = mat[i][j] + sumXF[i][j-1];	
			}
		}
	}
	
//	for (int i = 1; i <= N; i++) {
//		for (int j =1; j <= N; j++) {
//		cout << sumXF[i][j] << ' ';	
//		}
//		cout << '\n';}

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sol(x1, y1, x2, y2) << '\n';
	}
	
	return 0;
}
