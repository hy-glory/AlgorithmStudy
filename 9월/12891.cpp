#include <iostream>

using namespace std;

int P, S;
char c;
int arr[1000001];
int type[5];
int cur[5];

bool check() {
	for (int i = 1; i <= 4; i++) {
		if (cur[i] < type[i]) return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> S >> P;
	for (int i = 0; i < S; i++) {
		cin >> c;
		switch(c) {
			case 'A': arr[i] = 1; break;
			case 'C': arr[i] = 2; break;
			case 'G': arr[i] = 3; break;
			case 'T': arr[i] = 4; break;
		} 
	}
	for (int i = 1; i <= 4; i++) {
		cin >> type[i];
	}
	
	int start = 0, end = P;
	for (int i = 0; i < P; i++) {
		cur[arr[i]]++;
	}
	int result = 0;
	if (check()) result++;

	while(end < S) {
		cur[arr[start]]--;
		start++;
		cur[arr[end]]++;
		end++;
		if (check()) result++;
	}
	cout << result;
	
	return 0;
}
