#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int N;
int arr[100001];
stack<int> s;
vector<char> result; // 결과 출력 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int idx = 0, num = 1; // arr의 인덱스, stack 입력 num  
	while (idx < N) {
		int n = arr[idx];
		
		if (!s.empty()) {
			if (s.top() == n) {
				s.pop();
				result.push_back('-');
				idx++;
				continue;
			}
			else if (s.top() > n) {
				cout << "NO";
				return 0;
			}
			else {
				while(num <= n) {
					s.push(num++);
					result.push_back('+');
				}
				s.pop();
				result.push_back('-');
				idx++;	
			}
		}
		else {
			while(num <= n) {
				s.push(num++);
				result.push_back('+');
			}
			s.pop();
			result.push_back('-');
			idx++;
		}	
	}
	
	for (auto r : result) {
		cout << r << '\n';
	}
	return 0;
}
