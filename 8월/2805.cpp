#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	ll N,M;
	cin >> N >> M;
	vector<ll> trees;
	ll h, result;
	for (int i = 0; i < N; i++){
		cin >> h;
		trees.push_back(h);
	}
	
	ll left = 0, right = *max_element(trees.begin(), trees.end());
	while(left <= right){
		ll mid = (left + right)/2;
		ll sum = 0;
		for (int i = 0; i < N; i++){
			if (trees[i] > mid){
				sum += (trees[i]-mid);
			}
		}
		if (sum >= M){
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid -1;
		}
	}
	
	
	cout << result;
	return 0;
}
