for(int i=2;i<=n;i++){
    if(cnt[i].size()) continue;
    for(int j=i;j<=n;j+=i){
        cnt[j].push_back(i);
    }
}
ans[1]=1;
for(int i=2;i<=n;i++){
    ans[i]=1;
    int x=i;
    for(auto num:cnt[i]){
        int ct=0;
        while(x%num==0){
            x/=num;
            ct++;
        }
        ans[i]*=(ct+1);
    }
}
