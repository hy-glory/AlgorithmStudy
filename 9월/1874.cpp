#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int N;
int arr[100001];
stack<int> s;
vector<char> result; // ��� ��� 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int idx = 0, num = 1; // arr�� �ε���, stack �Է� num  
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
