#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	vector<int> v(M);
	string S = "";
	
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		char s;
		cin >> s;
		S += s;
	}
	
	string subS = "I";
	for (int i = 0; i < N; i++){
		subS += "OI";
	}
	
	int count = 0;
	for (int i = 0; i <= M-(2*N+1); i++){
		string ss = S.substr(i,2*N+1);
		if (ss == subS) count++;	
	}
	
	cout << count;
	return 0;
}
