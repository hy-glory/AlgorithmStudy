#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[1001][3];
int result[1001][3];
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	result[0][0] = arr[0][0];
	result[0][1] = arr[0][1];
	result[0][2] = arr[0][2];
	
	for (int i = 1; i < N; i++) {
		result[i][0] = arr[i][0] + min(result[i-1][1], result[i-1][2]);
		result[i][1] = arr[i][1] + min(result[i-1][0], result[i-1][2]);
		result[i][2] = arr[i][2] + min(result[i-1][0], result[i-1][1]);
	}
	answer = min(result[N-1][0], (min(result[N-1][1], result[N-1][2])));
	cout << answer;
	
	return 0;
}
