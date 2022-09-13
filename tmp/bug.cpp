#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
const int maxn = 5005;
 
int n, m, a, b, ans, p[maxn], cnt[maxn], in[maxn];
vector <int> G[maxn], v[maxn];
queue <int> q;
 
int pa(int x){
    if (p[x] < 0) return x;
    else return p[x] = pa(p[x]);
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
	// topo 排序
    for (int i = 1; i <= n; i++){
		// in_deg == i 的
        for (int j = 1; j <= n; j++){
            if (cnt[j] == i){
                q.push(j);
                in[j] = 1; // 紀錄是否已經在 vector 裡面
            }
        }
        while (!q.empty()){
            int now = q.front();
            q.pop();
            v[i].push_back(now);
			// 拔點 (now)
            for (auto v:G[now]){
                cnt[v]--;
                if (in[v]) continue;
                if (cnt[v] <= i){
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
    }
    for (int i = n; i >= 1; i--){
		cout << "in: " << i << "\n";
        for (auto v:v[i]){
			// 至少有 i 個邊連到比自己 in_deg 大於等於的 node
			cout << v << " ";
            p[v] = -1;
            for (auto k : G[v]){
                if (!p[k]) continue; 
				// 如果 in_deg 比自己低的就不跑
                int x = pa(v), y = pa(k);
                if (x != y){
                    if (x > y) swap(x, y);
                    p[x] += p[y];        
                    p[y] = x;        
                }  
            }
        }
		if(v[i].size()) cout << "\n";
        for (int j = 1; j <= n; j++){
            if (p[j] < 0) ans = max(ans, -p[j]*i);
			// p[i] 看他的區塊有多少個點
			// p[j] -> Di, i -> |S|
        }
    }
    cout << ans << "\n";
}
