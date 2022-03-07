# 海牛作業_1
## 觀念
### 第1題
- $N$ 每次遞迴時都會遞減 $1$ ，$N\div1=N$，時間複雜度為$O(N)$
- 又根據 `big-O notation` 可以高估的性質，故答案選**C,D**
### 第2題
- $N=2^k\Rightarrow k=\log_2N$，時間複雜度為 $O(\log N)$
- 又根據 `big-O notation` 可以高估的性質，故答案選**B,C,D**
### 第3題
$T(N)$
$=T(N−1)+N$
$=T(N-2)+N+N-1$
$=T(1)+N+N-1+\cdots +2$
$=1+2+3+\cdots+N$
$=\frac{N\times (N+1)}{2}=\frac{1}{2}(N^2+N)$
$\Rightarrow$ 時間複雜度為 $O(N^2)$
- 又根據 `big-O notation` 可以高估的性質，故答案選**A,C**
## 實作
### [ZeroJudge b557: 直角三角形](https://zerojudge.tw/ShowProblem?problemid=b557/ "Title")
```cpp=
#include <bits/stdc++.h> 
#define int long long
using namespace std;
int n,ans=0;
int arr[101];
signed main(){
    cin>>n;
    while(n--){
        int t;
        ans=0;
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>arr[i];
        }
        sort(arr,arr+t);
        for(int i=0;i<t-2;i++){
            if(i==t-2) break;
            for(int j=i+1;j<t-1;j++){
                for(int k=j+1;k<t;k++){
                    if(arr[k]*arr[k]==(arr[j]*arr[j]+arr[i]*arr[i])){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
```
### [ZeroJudge a005: Eva 的回家作業](https://zerojudge.tw/ShowProblem?problemid=a005/ "Title")
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int arr[5];
signed main(){
    cin>>n;
    while(n--){
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
        if(arr[1]-arr[0]==arr[2]-arr[1]){
            arr[4]=arr[3]+arr[1]-arr[0];
        }
        else if(arr[1]/arr[0]==arr[2]/arr[1]){
            arr[4]=arr[3]*(arr[1]/arr[0]);
        }
        for(int i=0;i<5;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
```
### [ZeroJudge a524 - 手機之謎](https://zerojudge.tw/ShowProblem?problemid=a524/ "Title")
```cpp=
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
map<int,int> mp;
int arr[10];
void rec(int ind){
    if(ind==n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<"\n";
    }
    for(int i=n;i>=1;i--){
        if(mp[i]==1) continue;
        mp[i]=1;
        arr[ind]=i;
        rec(ind+1);
        mp[i]=0;
    }
}
signed main(){
    while(cin>>n){
        rec(0);
    }
}
```
### [ZeroJudge a981: 求和問題](https://zerojudge.tw/ShowProblem?problemid=a981/ "Title")
```cpp=
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int arr[30];
int ans[30];
bool is_ans=0;
void rec(int sum,int ind,int len,bool get){ 
    if(get){
        sum+=arr[ind];
        ans[len]=arr[ind];
        len++;
        ind++;
    }
    else ind++;
    if(sum==m){
        is_ans=true;
        for(int i=0;i<len;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(ind==n||sum>m){ 
        return;
    }
    rec(sum, ind, len, 1);
    rec(sum, ind, len, 0);
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    rec(0,0,0,1);
    rec(0,0,0,0);
    if(!is_ans) cout<<"-1";
}
```
### [ZeroJudge a229: 括號匹配問題](https://zerojudge.tw/ShowProblem?problemid=a229/ "Title")
```cpp=
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
string s;
deque <char> dq;
void rec(int a,int b,int times){
    if(times==2*n){
        for(int i=0;i<2*n;i++) cout<<dq[i];
        cout<<"\n";
        return;
    }
    if(a<n){
        dq.push_back('(');
        rec(a+1, b,times+1);
        dq.pop_back();
    }
    if(a>b){//可以加)
        dq.push_back(')');
        rec(a, b+1,times+1);
        dq.pop_back();
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n){
        rec(0,0,0);
    }
}
```
