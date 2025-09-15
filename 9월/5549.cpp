#include <iostream>

using namespace std;
int N, M, K;
int js[1001][1001];
int os[1001][1001];
int is[1001][1001];
char c;
int a1, a2, b1, b2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j++) {
			cin >> c;
			js[i][j] = js[i-1][j] + js[i][j-1] - js[i-1][j-1];
			os[i][j] = os[i-1][j] + os[i][j-1] - os[i-1][j-1];
			is[i][j] = is[i-1][j] + is[i][j-1] - is[i-1][j-1];
			if (c == 'J'){
				js[i][j] += 1;
			}
			else if (c == 'O') {
				os[i][j] += 1;

			}
			else {
				is[i][j] += 1;

			}
		}
	}
	
	for (int k = 0; k < K; k++) {
		cin >> a1 >> b1 >> a2 >> b2;
		int jj, oo, ii;
		jj = js[a2][b2] - js[a2][b1-1] - js[a1-1][b2] + js[a1-1][b1-1];
		oo = os[a2][b2] - os[a2][b1-1] - os[a1-1][b2] + os[a1-1][b1-1];
		ii = is[a2][b2] - is[a2][b1-1] - is[a1-1][b2] + is[a1-1][b1-1];
		cout << jj << ' ' << oo << ' ' << ii << '\n';
	}
	return 0;
}
