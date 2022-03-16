#include <bits/stdc++.h>
#define ppl 35
using namespace std;
string tmp_str,str,n,m,str_num,bug,ne,day[5]={"星期一","星期二","星期三","星期四","星期五"},food[11]={"宜珍55","東東香55","東東香70","菩提55（素食）","美味55","美味70","悟饕70","順發55","驛饌55","驛饌60","驛饌70"};
int arr[ppl+1],form[5][ppl+1],a,b,num,prices[11]={55,55,70,55,55,70,70,55,55,60,70};
bool is_day[5];
signed main(){
    while(cin>>ne){
        if(ne=="0") break;
        //cout<<ne.size()<<"\n";
        if(ne.size()>=17){
                str=ne.substr(4,ne.size()-1);
        }
        else cin>>str;
        tmp_str=str.substr(1,2);
        if(tmp_str=="星"){
            str_num=str[0];
            n=str.substr(1,6);
            m=str.substr(7,str.size()-1);
        }
        else{
            str_num=str.substr(0,3);
            n=str.substr(2,6);
            m=str.substr(6,str.size()-1);
            m=m.substr(2,m.size()-1);
        }
        //cout<<"ans:"<<m<<" "<<n<<" "<<num<<"\n";
        num=stoi(str_num);
        for(int i=0;i<5;i++){
            if(n==day[i]){
                a=i;
                break;
            }
        }
        for(int i=0;i<11;i++){
            if(m==food[i]){
                b=i;
                break;
            }
        }
        is_day[a]=1;
        if(form[a][num]) bug+=str_num+",";
        else{ form[a][num]=b+1;
        arr[num]+=prices[b];
        }
    }
    // form ,day/person/meal
    cout<<"===========\n";
    for(int i=0;i<5;i++){
        if(is_day[i]){
        cout<<"__________\n";
        cout<<">>"<<day[i]<<"\n";
        cout<<"__________\n";
                for(int k=1;k<=ppl;k++){
                    if(form[i][k])
                        cout<<k<<"號: "<<food[form[i][k]-1];
                    else
                        cout<<k<<"號: none";
                    cout<<"\n";
                }
        }
        else{
            cout<<"__________\n";
        cout<<">>"<<day[i]<<": 沒人填"<<"\n";
        cout<<"__________\n";
        }
    }
    cout<<"===========\n";
    cout<<"_________[價錢]_________\n";
    for(int k=1;k<=ppl;k++){
        cout<<k<<"號: "<<arr[k]<<"元";
        cout<<"\n";
    }
    cout<<"===========\n";
    cout<<"#提醒: \n";
    for(int i=0;i<5;i++){
        if(is_day[i]){
        cout<<">>"<<day[i]<<"\n";
            for(int k=1;k<=ppl;k++){
                    if(!form[i][k]){
                        cout<<k<<",";
                    }
            }
            cout<<"尚未填寫表單\n";
        }
    }
    cout<<"===========\n";
    if(bug.size()){
            cout<<"____[BUG]____: \n";
            cout<<bug<<"重複填了表單";
    }
}
