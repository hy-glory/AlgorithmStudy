#include <iostream>
#include <queue>

using namespace std;

int main(){
	long long a, b;
	queue<pair<long long, long long>> q;
	bool isP = false;
	long long result;
	
	cin >> a >> b;
	
	q.push({a,1});

	while(!q.empty()){
		long long cf = q.front().first;
		long long cs = q.front().second;
		q.pop();

		if (cf== b){
			isP = true;
			result = cs;
			break;
		}		
		if (cf*2 <= b) q.push({cf*2, cs+1});
		
		if (cf*10+1 <= b) q.push({cf*10+1, cs+1});
	}
	
	if (isP) cout << result;
	else cout << -1;
	
	return 0;
}
