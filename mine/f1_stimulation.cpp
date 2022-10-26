#include <iostream>
#include <random>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>


using namespace std;

//隨機樹使用參數為時間(毫秒)
//梅克森旋轉演算法
unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
//平均分布
uniform_int_distribution<int> dis(1,1000000);

map<string, int> total_point = {{"Ver",0},{"Ham",0},{"Bot",0},{"Vip",0},{"Sai",0},{"Nor",0},{"Lec",0},{"Ric",0},{"Gas",0},{"Alo",0},{"Oco",0},{"Vet",0},{"Str",0},{"Tsu",0},{"Rus",0},{"Rai",0},{"Lat",0},{"Gio",0},{"Sch",0},{"Maz",0}};
map<string, int> track_base_arr = {{"巴林", 3},{"吉達", 4},{"澳洲", 7}, {"伊莫拉", 7},{"邁阿密", 5},{"巴薩隆納", 7},{"摩納哥",10},
{"巴庫", 3},{"加拿大", 3},{"銀石賽道", 7},{"奧地利", 8},{"法國", 5},{"匈牙利",9},{"比利時", 4},{"荷蘭", 8},{"蒙札", 1},{"新加玻", 9},
{"日本", 6},{"美國", 6},{"墨西哥", 10},{"巴西", 8},{"阿布札比", 5}};

string track_name[23] = {};
int times;
string fastest_lap_string;
vector<vector<pair<string,int>>> driver={{{"Lec",130},{"Ver",214},{"Vip",126},{"Sai",60},{"Rus",36},{"Nor",99},{"Ham",34},{"Ric",71},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",28},{"Bot",15},{"Lat",12},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",143},{"Ver",201},{"Vip",119},{"Sai",67},{"Rus",56},{"Nor",87},{"Ham",54},{"Ric",63},{"Gas",46},{"Alo",31},{"Oco",29},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",21},{"Bot",15},{"Lat",9},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",156},{"Ver",189},{"Vip",111},{"Sai",74},{"Rus",66},{"Nor",75},{"Ham",64},{"Ric",55},{"Gas",46},{"Alo",31},{"Oco",29},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",21},{"Bot",15},{"Lat",9},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",170},{"Ver",176},{"Vip",104},{"Sai",80},{"Rus",69},{"Nor",73},{"Ham",66},{"Ric",52},{"Gas",46},{"Alo",31},{"Oco",29},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",21},{"Bot",15},{"Lat",9},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",177},{"Ver",170},{"Vip",100},{"Sai",83},{"Rus",71},{"Nor",70},{"Ham",69},{"Ric",50},{"Gas",46},{"Alo",31},{"Oco",29},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",21},{"Bot",15},{"Lat",9},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",177},{"Ver",170},{"Vip",100},{"Sai",83},{"Rus",71},{"Nor",70},{"Ham",69},{"Ric",50},{"Gas",46},{"Alo",31},{"Oco",29},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",21},{"Bot",15},{"Lat",9},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",183},{"Ver",164},{"Vip",96},{"Sai",87},{"Rus",74},{"Nor",67},{"Ham",71},{"Ric",48},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",23},{"Str",17},{"Tsu",14},{"Alb",14},{"Bot",6},{"Lat",6},{"Zho",4},{"Sch",6},{"Mag",4}},
    {{"Lec",197},{"Ver",151},{"Vip",89},{"Sai",93},{"Rus",76},{"Nor",64},{"Ham",74},{"Ric",46},{"Gas",56},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",14},{"Bot",6},{"Lat",6},{"Zho",4},{"Sch",6},{"Mag",4}},
    {{"Lec",210},{"Ver",139},{"Vip",81},{"Sai",100},{"Rus",86},{"Nor",52},{"Ham",84},{"Ric",38},{"Gas",56},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",6},{"Bot",15},{"Lat",4},{"Zho",5},{"Sch",6},{"Mag",4}},
    {{"Lec",224},{"Ver",126},{"Vip",74},{"Sai",106},{"Rus",96},{"Nor",40},{"Ham",94},{"Ric",30},{"Gas",56},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Alb",6},{"Bot",15},{"Lat",4},{"Zho",5},{"Sch",6},{"Mag",4}}};

vector<pair<string,int>> fastest_lap_odd(20);
vector<pair<string,int>> position(20);
vector<string> race_position(20);
vector<pair<string,int>> point(20);
vector<pair<string,int>> round_point(20);
vector<int> fastest_lap_odd_calc;
vector<pair<string,int>> sort_pair(20);
vector<pair<string,int>> constructor={{"Ferrari",0},{"Red_bull",0},{"Mercedes",0},{"Mclaren",0},{"Alpine",0},
{"Alpha_tauri",0},{"Aston_Martin",0},{"Williams",0},{"Alfa_romeo",0},{"Haas",0}};
vector<vector<string>> team = {{"Lec" ,"Sai"},{"Ver" ,"Vip"},{"Rus","Ham"},{"Nor","Ric"},{"Oco","Alo"},
{"Gas","Tsu"},{"Vet","Str"},{"Alb","Lat"},{"Bot","Zho"},{"Mag","Sch"}};
int cmp(pair<string,int> a,pair<string,int> b){
  return a.second > b.second;
}

long long RandomNumber(){
    return dis(rng);
}

void quali(string str){
     int odd = track_base_arr[track_name[times]]-1;
    vector<pair<string,int>> tmp(20);
    vector<pair<int,int>> indent;
    int ran;
    int sum = 0;
    for(int i=0; i < driver[odd].size(); i++){
        tmp[i].first=driver[odd][i].first;
        tmp[i].second = driver[odd][i].second + sum;
        sum += driver[odd][i].second;
    }
    int k=0;
    for(int i=0; i < driver[odd].size(); i++){

        int min = 1;
        int max = sum;
        bool is_repeat;
        do{
            ran = RandomNumber() % (max - min + 1) + min;
            is_repeat = false;
            for(int j=0;j<indent.size();j++){
                if(ran <= indent[j].second && ran>= indent[j].first)
                    is_repeat = true;
            }
        }while(is_repeat == true);
        for(int j=0;j<tmp.size();j++){
            if(tmp[j].second >= ran){
                position[k].first=tmp[j].first;
                position[k].second=driver[odd][j].second;
                indent.push_back({tmp[j].second-driver[odd][j].second+1,tmp[j].second});
                k++;
                break;
            }
        }
    }
}
void race(){
    for(int i=0; i<position.size();i++){
        if(i<3){
            position[i].second += 10;
        }
        else if (i>=10){
            position[i].second -= 3;
        }
    }
    int odd = track_base_arr[track_name[times]]-1;
    vector<pair<string,int>> tmp(20);
    vector<pair<int,int>> indent;
    int ran;
    int sum = 0;
    for(int i=0; i<position.size();i++){
        tmp[i].first=position[i].first;
        tmp[i].second = position[i].second+sum;
        sum += position[i].second;
    }
    int k=0;
    for(int i=0; i < driver[odd].size(); i++){

        int min = 1;
        int max = sum;
        bool is_repeat;
        do{
            ran = RandomNumber() % (max - min + 1) + min;
            is_repeat = false;
            for(int j=0;j<indent.size();j++){
                if(ran <= indent[j].second && ran>= indent[j].first)
                    is_repeat = true;
            }
        }while(is_repeat == true);
        for(int j=0;j<tmp.size();j++){
            if(tmp[j].second >= ran){
                race_position[k]=tmp[j].first;
                indent.push_back({tmp[j].second-position[j].second+1,tmp[j].second});
                k++;
                break;
            }
        }
    }

}

void match () {
    vector<pair<string,int>> ve(10);
    for (int i = 0; i < constructor.size(); i++) {
        int sum = 0;
        ve[i].first = constructor[i].first;
        for (int j = 0; j < team[i].size(); j++) {
            ve[i].second += total_point[team[i][j]];
        }
    }
    sort (ve.begin(), ve.end(), [](pair<string,int> a, pair<string, int> b) {return a.second > b.second; });
    cout << "Round" << times+1 << "之後的車隊積分榜" << "\n";
    for (int i = 0; i < ve.size(); i++) {
        cout << i+1 << ":" << ve[i].first << ":" << ve[i].second << "\n";
    }
}



void point_system(){
    for(int i=0; i< race_position.size();i++){
        if (i==0){
            point[i].first = race_position[i];
            point[i].second += 25;
        }
        else if (i==1){
            point[i].first = race_position[i];
            point[i].second += 18;
        }
        else if (i==2){
            point[i].first = race_position[i];
            point[i].second += 15;
        }
        else if (i==3){
            point[i].first = race_position[i];
            point[i].second += 12;
        }
        else if (i==4){
            point[i].first = race_position[i];
            point[i].second += 10;
        }
        else if (i==5){
            point[i].first = race_position[i];
            point[i].second += 8;
        }
        else if (i==6){
            point[i].first = race_position[i];
            point[i].second += 6;
        }
        else if (i==7){
            point[i].first = race_position[i];
            point[i].second += 4;
        }
        else if (i==8){
            point[i].first = race_position[i];
            point[i].second += 2;
        }
        else if (i==9){
            point[i].first = race_position[i];
            point[i].second += 1;
        }
        else{
            point[i].second += 0;
        }

    }
    for(int j=10; j<race_position.size();j++){
        point[j].first = race_position[j];
    }
}

void round_point_system(){
    for(int i=0; i< race_position.size();i++){
        if (i==0){
            round_point[i].first = race_position[i];
            round_point[i].second = 25;
        }
        else if (i==1){
            round_point[i].first = race_position[i];
            round_point[i].second = 18;
        }
        else if (i==2){
            round_point[i].first = race_position[i];
            round_point[i].second = 15;
        }
        else if (i==3){
            round_point[i].first = race_position[i];
            round_point[i].second = 12;
        }
        else if (i==4){
            round_point[i].first = race_position[i];
            round_point[i].second = 10;
        }
        else if (i==5){
            round_point[i].first = race_position[i];
            round_point[i].second = 8;
        }
        else if (i==6){
            round_point[i].first = race_position[i];
            round_point[i].second = 6;
        }
        else if (i==7){
            round_point[i].first = race_position[i];
            round_point[i].second = 4;
        }
        else if (i==8){
            round_point[i].first = race_position[i];
            round_point[i].second = 2;
        }
        else if (i==9){
            round_point[i].first = race_position[i];
            round_point[i].second = 1;
        }
        else{
            round_point[i].second = 0;
        }

    }
    for(int j=10; j<race_position.size();j++){
        round_point[j].first = race_position[j];
    }

}
void fastest_lap(){
    int sum = 0;
    for(int i=0; i<race_position.size();i++){
        fastest_lap_odd[i].first = race_position[i];
    }
    for(int i=0; i<race_position.size();i++){
        fastest_lap_odd[i].second = sum+5;
        sum+=5;
        }

    int ran;
        int min = 1;
        int max = 100;
        ran = RandomNumber() % (max - min + 1) + min;
        for(int j=0;j<fastest_lap_odd.size();j++){
            if(fastest_lap_odd[j].second >= ran){
                if(j<10){
                    point[j].second += 1;
                }
            fastest_lap_string = point[j].first;
            break;
            }
        }
}
void clear_all(){
    fastest_lap_odd.clear();
    position.clear();
    race_position.clear();
    position.resize(20);
    fastest_lap_odd.resize(20);
    fastest_lap_string=' ';
    race_position.resize(20);
    point.clear();
    point.resize(20);
    round_point.clear();
    round_point.resize(20);
    //for (auto i = total_point.begin(); i != total_point.end(); i++) {
        //i->second = 0;
    //}
}
void print_quali(){
    cout << "----------------------------------\n";
    cout << "Round:" << times+1 << "   " << "賽道: " << track_name[times] <<"    " << "排位賽" << "\n";
    for(int i=0; i<position.size();i++){
        cout << i+1 << "." << position[i].first<<"\n";
    }
    cout << "\n";
}
void print_race(){
    cout << "Round:" << times+1 << "   " << "賽道: " << track_name[times] << "    " << "正賽" << "\n";
    for(int i=0; i<race_position.size();i++){
        cout << i+1 << "." << race_position[i]<<"    "<< point[i].second <<"\n";
    }
    cout << "最速單圈:" << fastest_lap_string << "\n";
    cout << "\n";
}

void print_driver_standing(){
    cout << "Round" << times+1 << "之後的車手積分榜" << "\n";
    for(int i=0; i<point.size();i++)
        cout << i+1 << "." << point[i].first << "  " << point[i].second<<"\n";
        cout << "\n";
}
void count_point(){
    for(int i=0;i<point.size();i++) {
        total_point[point[i].first]+=point[i].second;
        point[i].second = total_point[point[i].first];
}
    sort(point.begin(),point.end(),cmp);
}
int main()
{
    int track_num;
    cout << "                                               " << "歡迎來到f12022模擬器\n";
    cout << "輸入賽道個數: ";
    cin >> track_num;
    cout << "輸入各賽道名稱: ";
    for(int i=1;i<=track_num;i++){
        cin >> track_name[i-1];
    }
    for(int i=1;i<=track_num;i++){
        quali(track_name[i-1]);
        race();
        point_system();
        fastest_lap();
        print_quali();
        print_race();
        count_point();
        round_point_system();
        print_driver_standing();
        match();
        times += 1;
        clear_all();
        cout<<"----------------------------------\n";
    }

}

/*
巴林 吉達 澳洲 伊莫拉 邁阿密 巴薩隆納 摩納哥 巴庫
加拿大 銀石賽道 奧地利 法國 匈牙利 比利時 荷蘭 蒙札
新加玻 日本 美國 墨西哥 巴西 阿布札比
*/
