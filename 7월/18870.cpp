#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n;
	
	set<int> s1;
	vector<int> vec;
	unordered_map<int, int> unMap;
	
	for (int i = 0; i < n; i++){
		cin >> m;
		vec.push_back(m);
		unMap.insert({m,0});
		s1.insert(m);
	}
	
	int min = 0;
	for (auto key: s1){
		unMap.find(key)->second = min++;
	}
	
	for (auto v: vec){
		cout << unMap.find(v)->second << ' ';
	}
	
	return 0;

}
