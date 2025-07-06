#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	int avg = 0, median, mode, range;
	int max = 1;
	multiset<int> numMset;
	vector<int> modeVect;
	multiset<int>::iterator itMs;
	unordered_map<int, int> numUmap;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> m;
		numMset.insert(m);
		avg += m;
		if(numUmap.find(m) != numUmap.end()){
			numUmap.find(m)->second++;
			if (numUmap.find(m)->second > max) max = numUmap.find(m)->second;
		} else{
			numUmap.insert({m,1});
		}
	}
	
	avg = (avg >= 0) ? (avg + n/2)/n : (avg - n/2)/n;
	itMs = numMset.begin();
	advance(itMs, n/2);
	median = *itMs;
	range = *numMset.rbegin() - *numMset.begin();
	
	for (auto um: numUmap){
		if (um.second == max) modeVect.push_back(um.first);
	}
	sort(modeVect.begin(), modeVect.end());
	if (modeVect.size() == 1) mode = modeVect[0];
	else mode = modeVect[1];

	cout << avg << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range;

	return 0;
}
