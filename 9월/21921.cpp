#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
int arr[250001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int s = 0, e = X; //[s,e)
	int sum = 0;
	for (int i = s; i < e; i++) {
		sum += arr[i];
	}
	int result = sum;
	int count = 1;
	while (e <= N) {
		sum -= arr[s];
		s++;
		sum += arr[e];
		e++;
		if (sum == result) {
			count++;
		}
		if (sum > result) {
			count = 1;
			result = sum;
		}
	}
	if (result == 0) {
		cout << "SAD";
	}
	else {
		cout << result << '\n' << count;

	}
	
	return 0;
}
