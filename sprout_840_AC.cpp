#include <bits/stdc++.h>
#include <vector>
#define int long long
using namespace std;
int n,k;
int i;
vector<int> border;
vector<int> border2;
vector<int> number;
signed main()
{
    cin>>n>>k;
    int t=1;
    int m=1;
    if(n==1){
        cout<<k+1<<"\n";
        return 0;
    }
    if(k==0&&n<=10){
        cout<<12+20*(n-2)<<"\n";
        return 0;
    }
    border.push_back(0);
    border.push_back(1);
    i=1;
    if(k==0){
        border2.push_back(0);
        border2.push_back(1);
        while(border.back()<n){ //重複直到border>=n
            m*=10;//我現在在跑幾位數
            i+=(m/10)*9*t;//現在我跑到的最初的index
            border.push_back(border.back()+9*t*(m/10));//我目前跑到的位數裡面最大k的數量
            border2.push_back((t+1)*m);
            t++;
        }
        int t3=t;
        int repeat=0;
        int ind=i+1,prev_ind,bor=border[border.size()-2],prev_bor,units=m,t2=1;//改變的是幾位數
        while(units!=0){
            if(units==m) t2=1;
            else t2=0;
            while(bor<n){
                prev_bor=bor;//border會退到我上個section能負荷(包含)的最大數量，要+1
                prev_ind=ind; //ind會退到我現在所要找的數字的首位數的index
                if(t2==k){
                    bor+=units;
                }  
                bor+=repeat*units+border2[t-1];
                ind+=units*t3;
                t2++;
            }
            if(t2-1==k) repeat++; 
            number.push_back(t2-1);
            t--;
            bor=prev_bor;
            ind=prev_ind;
            units/=10;
        }
        ind--;
        for(auto u:number){
            if(u==k) bor++;
            ind++;
            if(bor==n) break; 
        }
        cout<<ind<<'\n';
    }
    else{
        while(border.back()<n){ //重複直到border>=n
            m*=10;//我現在在跑幾位數
            i+=(m/10)*9*t;//現在我跑到的最初的index
            border.push_back(border.back()*10+m);//我目前跑到的位數裡面最大k的數量
            t++;
        }
        int t3=t;
        int repeat=0;
        int ind=i+1,prev_ind,bor=border[border.size()-2],prev_bor,units=m,t2=1;//改變的是幾位數
        while(units!=0){
            if(units==m) t2=1;
            else t2=0;
            while(bor<n){
                prev_bor=bor;//border會退到我上個section能負荷(包含)的最大數量，要+1
                prev_ind=ind; //ind會退到我現在所要找的數字的首位數的index
                if(t2==k){
                    bor+=units;
                }
                bor+=repeat*units+border[t-1];
                ind+=units*t3;
                t2++;
            }
            if(t2-1==k) repeat++; 
            number.push_back(t2-1);
            t--;
            bor=prev_bor;
            ind=prev_ind;
            units/=10;
        }
        ind--;
        for(auto u:number){
            if(u==k) bor++;
            ind++;
            if(bor==n) break; 
        }
        cout<<ind<<'\n';
    }
}

    
