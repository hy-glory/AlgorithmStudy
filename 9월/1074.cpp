#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int N, r, c;
int result = 0;

void sol(int i, int j, int cur) {
	if (i == r && j == c) return;
	
	int P = pow(2, cur);
	int PP = pow(4, cur);
	if (cur == 0) {
		if (i == r && j+1 == c) {
			result += 1;
			return;
		}
		if (i+1 == r && j == c) {
			result += 2;
			return;
		}
		if (i+1 == r && j+1 == c) {
			result += 3;
			return;
		}
	}
	if (r < i+P && c < j+P) {
		sol(i, j, cur-1);
		return;
	}
	if (r < i+P && c >= j+P) {
		result += PP;
		sol(i, j+P, cur-1);
		return;
	}
	if (r >= i+P && c < j+P) {
		result += PP*2;
		sol(i+P, j, cur-1);
		return;
	}
	if (r >= i+P && c >= j+P) {
		result += PP*3;
		sol(i+P, j+P, cur-1);
		return;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> r >> c;
	
	sol(0, 0, N-1);
	
	cout << result;
	return 0;
}
