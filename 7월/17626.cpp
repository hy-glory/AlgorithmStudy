#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int arr[50001];
	
	cin >> n;
	
	arr[1]=1;
	
	for (int i = 2; i <= n; i++){
		arr[i] = arr[i-1]+1;
		for (int j = 1; j*j <= i; j++){
			arr[i] = min(arr[i], arr[i-j*j]+1);
		}
	}
	
	cout << arr[n];
	return 0;
	
}
