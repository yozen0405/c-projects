#include <iostream>

using namespace std;
int main() {
    int R,C,M,m;
    cin >> R>>C>>M;
    int arr[10][10];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>arr[i][j];
}
}
int R_n=R,C_n=C;
for(int i=0; i<M; i++){
    cin>>m;
    if (m==1){
        int tmp[R_n][C_n];
        for(int i=0; i<R_n; i++){
            for(int j=0; j<C_n; j++){
                tmp[i][j]=arr[i][j] ;  //duplicate arr
        }
        }
        for(int i=0; i<R_n; i++){
        for(int j=0; j<C_n; j++){
            arr[R_n-i-1][j]=tmp[i][j];
        }
        }
    }
    if (m==0){
        int tmp[R_n][C_n];
        for(int i=0; i<R_n; i++){
            for(int j=0; j<C_n; j++){
                tmp[i][j]=arr[i][j] ;  //duplicate arr
        }
        }
        int R_tmp=R_n;
        R_n=C_n;
        C_n=R_tmp;//switch
        for(int i=0; i<R_n; i++){
        for(int j=0; j<C_n; j++){
            arr[i][j]=tmp[C_n-j-1][i];
        }
        }
    }
}
cout<<R_n<<" "<<C_n<<endl;
for(int i=0; i<R_n; i++){
            for(int j=0; j<C_n; j++){
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
}
return 0;
}
