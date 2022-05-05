for(int i=2;i<=n;i++){
    if(cnt[i].size()) continue;
    for(int j=i;j<=n;j+=i){
        cnt[j].push_back(i);
    }
}
for(int i=2;i<=n;i++){
    ans[i]=1;
    for(auto num:cnt[i]){
        int x=i,ct=0;
        while(x%num==0){
            x/=num;
            ct++;
        }
        ans[i]*=(ct+1);
    }
}
