#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,s;
struct st{
    string name;
    int hp;
    int damage;
    string gear[10];
    int next;
    bool vis=false;
}arr[10001];
signed main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>arr[i].name>>arr[i].hp>>arr[i].damage;
        for(int j=0;j<arr[i].hp;j++){
            cin>>arr[i].gear[j];
        }
        cin>>arr[i].next;
    }
    int cur=s;
    while(arr[cur].vis==false){
        arr[cur].hp-=arr[cur].damage;
        if(arr[cur].hp<=0) cout<<arr[cur].name<<" dead.";
        else{
            cout<<arr[cur].name<<" "<<arr[cur].hp<<" ";
            for(int i=0;i<arr[cur].hp;i++){
                cout<<arr[cur].gear[i]<<" ";
            }
        }
        cout<<"\n";
        arr[cur].vis=true;
        cur=arr[cur].next;
    }
}
