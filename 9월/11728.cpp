#include <iostream>
#include <set>

using namespace std;
int N, M, num;
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M ;
	for (int i = 0; i < N+M; i++) {
		cin >> num;
		s.insert(num);
	}
	for (auto ss : s) {
		cout << ss << ' ';
	}
	
	return 0;
}
