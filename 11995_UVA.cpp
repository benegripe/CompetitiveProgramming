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
	queue<int> q;
	stack<int> s;
	priority_queue<int> p;
	int n,a,b,resp;
	bool stack_out, queue_out, priority_out;
	
	while (scanf("%d\n",&n) > 0){
		stack_out = queue_out = priority_out = true;
		for (int i = 0 ; i < n;i++){
			scanf("%d %d\n",&a,&b);
			if (1 == a){
				s.push(b);
				q.push(b);
				p.push(b);
			} else {
				if (!s.empty()){	
					if (s.top() != b) stack_out = false;
					s.pop();
					if (q.front() != b) queue_out = false;
					q.pop();
					if (p.top() != b) priority_out = false;
					p.pop();
				} else  stack_out = queue_out = priority_out = false;
			}
		}	
		while (!p.empty()) p.pop();
		while (!s.empty()) s.pop();
		while (!q.empty()) q.pop();
		if ((stack_out)&&(!queue_out)&&(!priority_out)) printf("stack\n");
			else if ((!stack_out)&&(priority_out)&&(!queue_out)) printf("priority queue\n");
				else if ((!stack_out)&&(!priority_out)&&(queue_out)) printf("queue\n");
					else if ((!stack_out)&&(!priority_out)&&(!queue_out)) printf("impossible\n");
						else printf("not sure\n");
	}
return 0;
}
