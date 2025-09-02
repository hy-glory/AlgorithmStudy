#include <iostream>
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T, P, Q;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> P >> Q;
		ll f[10001];
		f[1] = 1;
		f[2] = 1;
		if (Q == 1) {
			cout << "Case #"<< t<<": " << 0 << '\n';
			continue;
		} 
		for (int i = 3; i <= P; i++){
			f[i] = (f[i-1] + f[i-2]) % Q;
		}	

		cout << "Case #"<< t<<": " << f[P] << '\n';
	}
	return 0;
}
