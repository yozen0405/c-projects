#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int arr[1000000];
signed main(){
    while(cin>>n){
        if(n==0) break;
        while(true){
            stack<int> stk;
            int order=1; 
            bool bk=false;
            for(int i=0;i<n;i++){
                cin>>arr[i];
                if(i==0&&arr[i]==0){
                    bk=true;
                    break;
                }              
            }
            if(bk) break;
            bool success=true;
            for(int i=0;i<n;i++){
                if(!stk.empty()&&stk.top()==arr[i])
                    stk.pop();
                else if(order<=n&&order==arr[i])
                    order++;
                else if(arr[i]<order){
                    cout<<"No"<<"\n";
                    success = false;
                    break;
                }
                else{
                    while(true){
                        if(order>n){
                            cout<<"No"<<"\n";
                            success = false;
                            break;
                        }
                        stk.push(order);
                        order++;
                        if(!stk.empty()&&stk.top()==arr[i])
                        {
                            stk.pop();
                            break;
                        }
                        else if(order<=n&&order==arr[i]){
                            order++;
                            break;
                        }
                        
                    }
                }
                if(!success) break;
            }
            if(success) cout<<"Yes\n";
        }
        cout<<"\n";
    }

}
