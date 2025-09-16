#include <iostream>

using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	int count = 0;
	int left = 1, right = 1;
	int sum = 0;
	while(left <= right && right <= N+1) {
		if (sum > N) {
			sum -= left;
			left++;
		}
		else if (sum < N) {
			sum += right;
			right++;
		}
		else {
			count++;
			sum += right;
			right++;
		}
	}
	cout << count;
	return 0;
}
