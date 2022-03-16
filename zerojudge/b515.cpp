#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
map<string,string> mp={{".-","A"},{"-...","B"},{"-.-.","C"},{"-..","D"},{".","E"},{"..-.","F"},
                        {"--.","G"},{"....","H"},{"..","I"},{".---","J"},{"-.-","K"},{".-..","L"},{"--","M"},
                        {"-.","N"},{"---","O"},{".--.","P"},{"--.-","Q"},{".-.","R"},{"...","S"},{"-","T"},
                        {"..-","U"},{"...-","V"},{".--","W"},{"-..-","X"},{"-.--","Y"},{"--..","Z"}};
signed main(){
    cin>>n;
    string s;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        string sub_s;
        int ind=0,siz=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==' '){
                sub_s=s.substr(ind,siz);
                cout<<mp[sub_s];
                siz=0;
                ind=j+1;   
            }
            else{
                siz++;
                if(j==s.size()-1){
                    sub_s=s.substr(ind,siz);
                    cout<<mp[sub_s];
                    siz=0;
                    ind=j+1;   
                }
            }
        }
        cout<<"\n";
    }    
}
