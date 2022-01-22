#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
int n,m,k,c,ans=0; 
pair<int, int> p1;
pair<int, int> p2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>c;
    cin>>p1.x>>p1.y;
    int y_min=p1.y-c;
    if(k==2){ 
        cin>>p2.x>>p2.y;
        if(p2.y>p1.y)
            swap(p2,p1); 
        y_min=p2.y-c;
    }
    int n1=0,n2=0,n1_var=1,n2_var=1,y=p1.y+c;
    if(p1.y+c>m)
        n1=c-(m-p1.y);
    if(k==2&&p2.y+c>m)
        n2=c-(m-p2.y);
    if(y>m) y=m;
    if(y_min<1) y_min=1;
    bool p1_exist,p2_exist;
    while(y>=y_min){
        if(k==1){
            ans+=2*n1+1;
            if(p1.x+n1>n) ans-=p1.x+n1-n;
            if(p1.x-n1<1) ans-=1-(p1.x-n1);
            if(n1==c) n1_var=-1;
            n1+=n1_var;
            y--;
        }
        else{
            p1_exist=p1.y-c<=y&&p1.y+c>=y,p2_exist=p2.y-c<=y&&p2.y+c>=y;
            int max_x,min_x;
            if(p1_exist&&p2_exist){
                if((p1.x+n1>=p2.x-n2&&p2.x>=p1.x)||(p2.x+n2>=p1.x-n1&&p1.x>=p2.x)){
                    if(p1_exist&&p2_exist){
                        max_x=max(p1.x+n1,p2.x+n2);
                        min_x=min(p1.x-n1,p2.x-n2);
                    }
                    if(max_x>n) max_x=n;
                    if(min_x<1) min_x=1;
                    ans+=max_x-min_x+1;
                }
                else{
                    ans+=2*n1+1+2*n2+1;
                    if(p1.x+n1>n) ans-=p1.x+n1-n;
                    if(p2.x+n2>n) ans-=p2.x+n2-n;
                    if(p1.x-n1<1) ans-=1-(p1.x-n1);
                    if(p2.x-n2<1) ans-=1-(p2.x-n2);
                }
            }
            else if(p1_exist){
                max_x=p1.x+n1;
                min_x=p1.x-n1;
                if(max_x>n) max_x=n;
                if(min_x<1) min_x=1;
                ans+=max_x-min_x+1;
            }
            else if(p2_exist){
                max_x=p2.x+n2;
                min_x=p2.x-n2;
                if(max_x>n) max_x=n;
                if(min_x<1) min_x=1;
                ans+=max_x-min_x+1;
            }
            if(y==p1.y) n1_var=-1;
            if(y==p2.y) n2_var=-1;
            if(y>p1.y-c) n1+=n1_var;
            if(y<=p2.y+c) n2+=n2_var;
            if(y==p1.y-c&&y>p2.y+c) y=p2.y+c;
            else y--;
        }
    }
    cout<<ans<<"\n";
}
