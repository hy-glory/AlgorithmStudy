#include <iostream>
#include <vector>

using namespace std;
int N;
int nums[12];
int op[11];
bool usedop[11];
int minN = 1000000000, maxN = -1000000000;

void sol(int cur, int result) {
	if (cur == N) {
		// break point  
		maxN = max(result, maxN);
		minN = min(result, minN);
		return;
	}
	
	for (int i = 1; i <= N-1; i++) {
	if (!usedop[i]) {
		usedop[i] = true;

		switch(op[i]){
		case 1:
			sol(cur+1, result+nums[cur+1]);
			break;
		case 2:
			sol(cur+1, result-nums[cur+1]);
			break;
		case 3:
			sol(cur+1, result*nums[cur+1]);
			break;
		case 4:
			sol(cur+1, result/nums[cur+1]);
			break;
		}
		usedop[i] = false;
	}
		
	}
	
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int p[5];
	
	cin >> N;
	// 숫자 입력  
	for (int i = 1; i <= N; i++){
		cin >> nums[i];
	} 
	// 연산자 입력 + op 추가   
	int idx = 1;
	for (int i = 1; i <= 4; i++){
		cin >> p[i];
		for (int j = 1; j <=p[i]; j++){
			op[idx++] = i;
		}
	}
	
	sol(1, nums[1]);
	
	cout << maxN << '\n' << minN;
	
	return 0;
}
