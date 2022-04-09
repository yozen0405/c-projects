#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct Node{
  int ans=0; 
};
Node merge(vector<int> &vec,int idx_l,int idx_r,int mid, Node l, Node r){
  Node ret;
  ret.ans=r.ans+l.ans;
  vector<int> a;
  int j=mid+1;
  for(int i=idx_l;i<=mid;i++){
    while(j<=idx_r && vec[i]>vec[j]) a.push_back(vec[j++]);
    a.push_back(vec[i]);
    ret.ans+=j-(mid+1);
  }
  while(j<=idx_r) a.push_back(vec[j++]);
  copy(a.begin(),a.end(),vec.begin()+idx_l);
  return ret;
}
Node dc(vector<int> &vec,int l,int r){
  if(l==r){
    return {0};
  }
  int mid=(l+r)/2;
  Node left=dc(vec,l,mid);
  Node right=dc(vec,mid+1,r);
  return merge(vec, l, r, mid,left, right);
}
signed main(){
    int t=0;
    while(scanf("%d",&n) != EOF){
      if(n==0) break;
      t++;
      vector<int> vec(n);
      for(int i=0;i<n;i++){
        cin>>vec[i];
      }
      Node ans;
      ans=dc(vec,0,n-1);
      vec.clear();
      printf("Case #%d: %d\n",t,ans.ans);
    }
}
