#include <iostream>
#define int long long
using namespace std;
long long pow(long long a, long long n, long long M) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1){
            ans = ans * a % M;
            cout<<n<<endl;
         }
        a = a * a % M;
        n >>= 1;
        cout<<"n:"<<n<<endl;
    }
    return ans % M;
}
int n,k,ans;
int arr[1000000];
signed main(){
    int a=2^5;
    cout<<a<<endl;
    for(int k=1;k<50;k++)
        for(int j=1;j<50;j++){
            for(int i=1;i<50;i++){
            a=k^j^i;
            if(a==i+j+k)
                cout<<"i:"<<i<<", "<<"j:"<<j<<", "<<"k:"<<k<<","<<a<<endl;
        }
    }
        
}
    
