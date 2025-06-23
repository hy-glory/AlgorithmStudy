#include <iostream>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	string name;
	unordered_set<string> n1, n2, ur;
	set<string> result;
	
	for(int i =0; i <n; i++) {
		cin >> name;
		n1.insert(name);
	}
	for (int i =0; i < m; i++) {
		cin >> name;
		n2.insert(name);
	}
	
	for(auto n : n1){
		if(n2.find(n) != n2.end())
		ur.insert(n);
	}
	
	for (auto r : ur) {
		result.insert(r);
	}
	
	cout << result.size() << endl;
	for (auto r: result) {
		cout << r << endl;
	}
	
	return 0;
}
