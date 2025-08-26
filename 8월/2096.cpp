#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	int result[2][3]; // max, min
	int prev[6];
	
	cin >> N;
	int cur = 1;
	while(cur <= N) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		if (cur == 1) {
			result[0][0] = n1;
			result[1][0] = n1;
			result[0][1] = n2;
			result[1][1] = n2;
			result[0][2] = n3;
			result[1][2] = n3;
			cur++;
			continue;
		}
		for (int i = 0; i < 6; i++) {
			if (i < 3) {
				prev[i] = result[0][i];
			}
			else {
				prev[i] = result[1][i-3];
			}
		}
		result[0][0] = max(prev[0], prev[1]) + n1;
		result[0][1] = max({prev[0], prev[1], prev[2]}) + n2;
		result[0][2] = max(prev[1], prev[2]) + n3;
		result[1][0] = min(prev[3], prev[4]) + n1;
		result[1][1] = min({prev[3], prev[4], prev[5]}) + n2;
		result[1][2] = min(prev[4], prev[5]) + n3;
		cur++;
	}
	
	int maxNum = max(max(result[0][0], result[0][1]), result[0][2]);
	int minNum = min(min(result[1][0], result[1][1]), result[1][2]);
	
	cout << maxNum << ' ' << minNum;
	
	return 0;
}