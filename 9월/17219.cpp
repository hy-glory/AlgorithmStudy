#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	string s, p;
	unordered_map<string, string>um;

	for (int i = 0; i < N; i++) {
		cin >> s >> p;
		um.insert({s, p});
	}
	
	for (int i = 0; i < M; i++) {
		cin >> s;
		auto item = um.find(s);
		cout << item->second << '\n';
	}
	
	return 0;
}
