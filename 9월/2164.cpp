#include <iostream>
#include <queue>

using namespace std;
int N;
queue<int> q;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   
   cin >> N;
   for (int i = 1; i <= N; i++) {
      q.push(i);
   }
   
   if (N == 1) {
      cout << 1;
      return 0;
   }
   int front;
   while (!q.empty()) {
      q.pop();
      front = q.front();
      if (q.size() == 1) break;
      q.pop();
      q.push(front);
   }
   
   cout << front;
   
   return 0;
}