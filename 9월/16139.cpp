#include <iostream>
#include <vector>

using namespace std;

int N, idx;
string s;
char c, cc;
int l, r;
vector<int> v[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		c = s[i];
		int ci = (int)(c - 'a');
		v[ci].push_back(i);
	}
		
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cc >> l >> r;
		int cci = (int)(cc-'a');
		int count = 0;
		for (auto vv : v[cci]) {
			if (vv >= l && vv <= r)
				count++;
		}
		cout << count << '\n';
	}
	
	return 0;
}
