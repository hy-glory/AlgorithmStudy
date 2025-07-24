#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, B;
	cin >> N >> M >> B;
	
	vector<int> v(N*M);
	int minH = 257, maxH = 0;
	
	for (int i = 0; i < N*M; i++){
		cin >> v[i];
		if (v[i] > maxH) maxH = v[i];
		if (v[i] < minH) minH = v[i];
	}
	
	if (maxH == minH){
		cout << 0 << ' ' << maxH;
		return 0;
	}
	

	int resultH = 0, resultT = INT_MAX;

	for (int h = 0; h <= 256; h++){
		int blocks = B;
		int time = 0;
		int remove = 0, add = 0;
		for(int a: v){
			if (a < h) add += (h-a);
			else if (a > h) remove += (a-h);
		}
		
		time = add + remove*2;
		if (blocks + remove < add) continue;
		if (time < resultT || (time == resultT && h > resultH)) {
			resultT = time;
			resultH = h;
		}
	}
	cout << resultT << ' ' << resultH;
	
	return 0;
}
