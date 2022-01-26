    #include <bits/stdc++.h>
    #include <vector>
    #define int long long
    using namespace std;
    int n,k;
    int m=1;
    vector<int> index;
    vector<int> border;
    signed main()
    {
        cin>>n>>k;
        int t=1;
        if(n==1){
            cout<<k+1<<"\n";
            return 0;
        }
        border.push_back(1);
        index.push_back(1);
        while(border.back()<n){ //重複直到border>=n
            m*=10;//我現在在跑幾位數
            index.push_back(index.back()+(m/10)*9*t);//現在我跑到的最初的index
            border.push_back(border.back()*10+m);//我目前跑到的位數裡面最大k的數量
            t++;
        }
        int t3=t;
        int repeat=0;
        int ind=index.back()+1,prev_ind,bor=border[border.size()-2],prev_bor,units=m,num=m,t2=1;//改變的是幾位數
        while(units!=0){
            if(units==m) t2=1;
            else t2=0;
            while(bor<n){
                if(t2==k){
                    bor+=units;
                }
                prev_bor=bor;
                prev_ind=ind;
                bor+=repeat*units+border[t-2];
                ind+=units*t3;
                t2++;
            }
            if(t2-1==k) repeat++; 
            t--;
            bor=prev_bor;
            ind=prev_ind;
            units/=10;
        }

    }
