#include <iostream>
#include <random>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>


using namespace std;

map<string, int> total_point = {{"Ver",0},{"Ham",0},{"Bot",0},{"Per",0},{"Sai",0},{"Nor",0},{"Lec",0},{"Ric",0},{"Gas",0},{"Alo",0},{"Oco",0},{"Vet",0},{"Str",0},{"Tsu",0},{"Rus",0},{"Rai",0},{"Lat",0},{"Gio",0},{"Sch",0},{"Maz",0}};
map<string, int> track_base_arr = {{"賽道1", 9}, {"賽道2", 9},{"賽道3", 10},{"賽道4", 5},{"賽道5", 4},
{"賽道6", 4},{"賽道7", 2},{"賽道8", 8},{"賽道9", 4},{"賽道10", 9},
{"賽道11", 1},{"賽道12", 5},{"賽道13", 3},{"賽道14", 4},{"賽道15", 7},
{"賽道16", 5},{"賽道17", 6},{"賽道18", 3},
{"賽道19", 2},{"賽道20", 6}};

string track_name[20] = {};
int times;
vector<vector<pair<string,int>>> driver={{{"Ver",130},{"Ham",214},{"Bot",126},{"Per",60},{"Sai",36},{"Nor",99},{"Lec",34},{"Ric",71},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Rus",28},{"Rai",15},{"Lat",12},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",143},{"Ham",201},{"Bot",119},{"Per",67},{"Sai",56},{"Nor",87},{"Lec",54},{"Ric",63},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Rus",28},{"Rai",15},{"Lat",12},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",156},{"Ham",189},{"Bot",111},{"Per",74},{"Sai",66},{"Nor",75},{"Lec",64},{"Ric",55},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Rus",28},{"Rai",15},{"Lat",12},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",170},{"Ham",176},{"Bot",104},{"Per",80},{"Sai",69},{"Nor",73},{"Lec",66},{"Ric",52},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",17},{"Str",13},{"Tsu",14},{"Rus",28},{"Rai",15},{"Lat",12},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",177},{"Ham",170},{"Bot",100},{"Per",83},{"Sai",71},{"Nor",70},{"Lec",69},{"Ric",50},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",23},{"Str",17},{"Tsu",14},{"Rus",21},{"Rai",15},{"Lat",9},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",177},{"Ham",170},{"Bot",100},{"Per",83},{"Sai",71},{"Nor",70},{"Lec",69},{"Ric",50},{"Gas",46},{"Alo",36},{"Oco",34},{"Vet",23},{"Str",17},{"Tsu",14},{"Rus",21},{"Rai",15},{"Lat",9},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",183},{"Ham",164},{"Bot",96},{"Per",87},{"Sai",74},{"Nor",67},{"Lec",71},{"Ric",48},{"Gas",54},{"Alo",42},{"Oco",38},{"Vet",23},{"Str",17},{"Tsu",16},{"Rus",21},{"Rai",15},{"Lat",9},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",197},{"Ham",151},{"Bot",89},{"Per",93},{"Sai",76},{"Nor",64},{"Lec",74},{"Ric",46},{"Gas",62},{"Alo",42},{"Oco",38},{"Vet",23},{"Str",17},{"Tsu",18},{"Rus",21},{"Rai",15},{"Lat",9},{"Gio",5},{"Sch",6},{"Maz",4}},
    {{"Ver",210},{"Ham",139},{"Bot",81},{"Per",100},{"Sai",86},{"Nor",52},{"Lec",84},{"Ric",38},{"Gas",62},{"Alo",42},{"Oco",38},{"Vet",23},{"Str",17},{"Tsu",18},{"Rus",14},{"Rai",23},{"Lat",6},{"Gio",7},{"Sch",6},{"Maz",4}},
    {{"Ver",224},{"Ham",126},{"Bot",74},{"Per",106},{"Sai",96},{"Nor",40},{"Lec",94},{"Ric",30},{"Gas",62},{"Alo",42},{"Oco",38},{"Vet",23},{"Str",17},{"Tsu",18},{"Rus",14},{"Rai",23},{"Lat",6},{"Gio",7},{"Sch",6},{"Maz",4}}};
vector<pair<string,int>> fastest_lap_odd(20);
vector<pair<string,int>> position(20);
vector<string> race_position(20);
vector<pair<string,int>> point(20);
vector<pair<string,int>> constructor={{"Mercedes",0},{"Red_bull",0},{"Ferrari",0},{"Mclaren",0},{"Alpine",0},
{"Alpha_tauri",0},{"Aston_Martin",0},{"Williams",0},{"Alfa_romeo",0},{"Haas",0}};
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
        srand( time(NULL) );
        int min = 1;
        int max = sum;
        bool is_repeat;
        do{
            ran = rand() % (max - min + 1) + min;
            //cout<<ran<<"\n";
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
    cout<<"----\n";
    for(int i=0;i<position.size();i++) cout<<position[i].first<<","<<position[i].second<<"\n";
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
    cout<<"hi\n";
    int k=0;
    for(int i=0; i < driver[odd].size(); i++){
        srand( time(NULL) );
        int min = 1;
        int max = sum;
        bool is_repeat;
        do{
            ran = rand() % (max - min + 1) + min;
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

    for(int i=0;i<tmp.size();i++) cout<<tmp[i].first<<","<<tmp[i].second<<"\n";
    cout<<"----\n";
    for(int i=0;i<race_position.size();i++) cout<<race_position[i]<<"\n";
    cout<<"----\n";
    for(int i=0;i<indent.size();i++) cout<<indent[i].first<<","<<indent[i].second<<"\n";

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
    cout<<"----\n";
    for(int i=0;i<point.size();i++) cout<<point[i].first<<","<<point[i].second<<"\n";
}
void fastest_lap(){
    int sum = 0;
    for(int i=0; i<race_position.size();i++){
        fastest_lap_odd[i].first = race_position[i];
    }
    for(int i=0; i<race_position.size();i++){
        if (i<=4){
            fastest_lap_odd[i].second = sum+10;
            sum+=10;
        }
        else if (i>=10){
            fastest_lap_odd[i].second = sum+1;
            sum++;
        }
        else{
            fastest_lap_odd[i].second = 8+sum;
            sum+=8;
        }
    }
    int ran;
        srand( time(NULL) );
        int min = 1;
        int max = 100;
        ran = rand() % (max - min + 1) + min;
        for(int j=0;j<fastest_lap_odd.size();j++){
            if(fastest_lap_odd[j].second >= ran){
                if(j<10){
                    point[j].second += 1;
                }
                break;
            }
        }
    cout<<"----\n";
    for(int i=0;i<fastest_lap_odd.size();i++) cout<<fastest_lap_odd[i].first<<","<<fastest_lap_odd[i].second<<"\n";
    cout<<"----\n";
    for(int i=0;i<point.size();i++) cout<<point[i].first<<","<<point[i].second<<"\n";
}
void clear_all(){
    fastest_lap_odd.clear();
    position.clear();
    race_position.clear();
    position.resize(20);
    fastest_lap_odd.resize(20);
    race_position.resize(20);
    point.clear();
    point.resize(20);
}
void print_quali(){
    for(int i=0; i<position.size();i++){
        cout << i+1 << "." << position[i].first<<"\n";
    }
}
void print_race(){
    for(int i=0; i<race_position.size();i++){
        cout << i+1 << "." << race_position[i]<<"\n";
    }
}
void print_driver_standing(){
    for(int i=0; i<point.size();i++)
        cout << i+1 << "." << point[i].first << "  " << total_point[point[i].first]<<"\n";
}
void count_point(){
    for(int i=0;i<point.size();i++) total_point[point[i].first]+=point[i].second;
}
int main()
{
    int track_num;
    cout << "歡迎來到f12021模擬器\n";
    cout << "輸入賽道個數: ";
    cin >> track_num;
    for(int i=1;i<=track_num;i++){
        cin >> track_name[i-1];
    }
    for(int i=1;i<=track_num;i++){
        quali(track_name[i-1]);
        race();
        point_system();
        fastest_lap();
        count_point();
        print_quali();
        print_race();
        print_driver_standing();
        times += 1;
        clear_all();
        cout<<"--------------------------\n";
        cout<<position.size()<<"\n";
    }
}
