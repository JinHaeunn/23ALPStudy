#include <bits/stdc++.h>
using namespace std;

vector<int> coco[1005];
bool vis[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		coco[u].push_back(v);
		coco[v].push_back(u);
	}
	
	//bfs
	int num = 0;
	for(int i = 1; i<n; i++) {
		if(vis[i]) continue;
		num++;
		queue<int> q;
		q.push(i);
		vis[i] = true;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(auto nxt : coco[cur]) {
				if(vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}
	cout << num;
}