#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool set[21] = {false, };
	int M;
	int n, sint, result;
	string s;

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s == "all") {
			for (int j = 1; j <=20; j++) {
				set[j] = true;
			}
			continue;
		}
		else if (s == "empty") {
			for (int j = 1; j <=20; j++) {
				set[j] = false;
			}
			continue;
		}
		cin >> n;
		if (s == "add") {
			set[n] = true;
		}
		else if (s == "remove") {
			set[n] = false;
		}
		else if (s == "check") {
			int result = set[n] ? 1 : 0;
			cout << result << '\n';
		}
		else if (s == "toggle") {
			set[n] = !set[n];
		}
	}
	return 0;
}