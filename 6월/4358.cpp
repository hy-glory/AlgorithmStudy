#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

int main(){
	string str;
	unordered_map<string, int> treeUM;
	map<string, float> treeM;
	int count = 0;
	
	while(getline(cin,str)){
		if (treeUM.find(str) != treeUM.end()){
			treeUM.find(str)->second++;
		}
		else{
			treeUM.insert({str,1});
		}
		count++;
	}
	
	for (auto t : treeUM){
		float n = (float)t.second/count*100.0f;
		treeM.insert({t.first, n});
	}
	
	cout << fixed;
	cout.precision(4);
	for (auto t: treeM){
		cout << t.first << " "<< t.second << endl;
	}
	return 0;
}
