#include <iostream>
typedef long long ll;
using namespace std;
int N, n;
ll r[100000], l[100000];
int c[100001]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		c[i] = n;
	}
	for (int i = 1; i < N; i++) {
		cin >> n;
		l[i] = l[i-1] + n;	
	}
	for (int i = 1; i < N; i++) {
		cin >> n;
		r[i] = n;
	}
	for (int i = N-2; i >= 1; i--) {
		r[i] = r[i+1] + r[i];
	}
	
	int mpoint = 1;
	ll mlen = c[1] + r[1];
	for (int i = 2; i <= N; i++) {
		ll temp = l[i-1] + c[i] + r[i];
		if (temp < mlen) {
			mpoint = i;
			mlen = temp;
		}
	}
	
	cout << mpoint << ' ' << mlen;
	
	return 0;
}
