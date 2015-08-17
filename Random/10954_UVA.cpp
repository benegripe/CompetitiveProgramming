#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
using namespace std;
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
	int a,n,sum;	
	priority_queue<int> queue;
	cin >> n;
	while (0 != n){
		for (int i = 0 ;i < n; i++){
			cin >> a;
			queue.push(-a);
		}
		sum = 0;
		while (1 < queue.size()){
			int x = queue.top(); queue.pop();
			int y = queue.top(); queue.pop();
			queue.push(x+y);
			sum += -1*(x+y);
		}
		cout << sum << '\n';
		while (!queue.empty()) queue.pop();
		cin >> n;
	}	
	
return 0;
}
