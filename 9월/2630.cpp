#include <iostream>

using namespace std;
int N;
bool mat[129][129] = {false};
int white = 0;
int blue = 0;

void check(int i, int j, int cur) {
	bool C = mat[i][j];
	if (cur == 1){
		if (C) blue++;
		else white++;
		return;
	}
	for (int ii = i; ii< i+cur; ii++) {
		for (int jj = j; jj < j+cur; jj++) {
			if (mat[ii][jj] != C) {
				int diff = cur/2;
				check(i, j, diff);
				check(i, j+diff, diff);
				check(i+diff, j, diff);
				check(i+diff, j+diff, diff);
				return;
			}
		}
	}
	if (C) blue++;
	else white++;
	
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> mat[i][j];
		}
	}

	check(1, 1, N);
	
	cout << white << '\n' << blue;
	
	return 0;
}
