#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	string s;
	int num = 1;
	unordered_map<string, int> umS;
	unordered_map<int, string> umI;
	for (int i = 0; i < N; i++) {
		cin >> s;
		umS.insert({s, num});
		umI.insert({num, s});
		num++;
	}
	
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			int key = stoi(s);
			auto item = umI.find(key);
			cout << item->second << '\n';
			continue;
		}
		auto item = umS.find(s);
		cout << item->second << '\n';
		
	}
	return 0;
}
