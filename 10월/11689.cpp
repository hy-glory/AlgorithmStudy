#include <iostream>
typedef long long ll;

using namespace std;

ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	ll num = n;
	ll result = n;
	for (ll i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			result -= (result/i);
			while(num%i == 0) {
				num /= i;
			}
		}
	}
	if (num > 1) {
		result -=(result/num);
	}
	
	cout << result;
	
	return 0;
}