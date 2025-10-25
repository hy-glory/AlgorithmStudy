#include <iostream>
#include <vector>

using namespace std;
int N, M;
bool arr[1000001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> M >> N;
	
	for (int i = 2; i <= 1000000; i++) {
		if (!arr[i]) {
			v.push_back(i);
			int j = 1;
			while(i*j <= 1000000) {
				arr[i*j] = true;
				j++;
			}
		}
	}
	
	for (auto vv : v) {
		if (vv >= M && vv <= N) {
			cout << vv << '\n';
		}
	}
	
	return 0;
} 
