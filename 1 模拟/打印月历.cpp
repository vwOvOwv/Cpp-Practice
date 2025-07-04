// http://noi.openjudge.cn/ch0113/24/

#include <bits/stdc++.h>

using namespace std;

bool is_big_month(int month){
    return month == 1 || month == 3 || month == 5 || month == 7 || month == 8
    || month == 10 || month == 12;
}

bool is_leap_year(int year){
    return (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
}

int get_days(int year, int month){
    int ans = 0;
    for(int i = 1900; i < year; i++){
        ans += 365;
        if(is_leap_year(i))
            ans++;
    }
    for(int i = 1; i < month; i++){
        if(is_big_month(i))
            ans += 31;
        else if(i == 2){
            ans += 28;
            if(is_leap_year(year))
                ans++;
        }
        else{
            ans += 30;
        }
    }
    return ans;
}

int main(){
    int year, month;
    cin >> year >> month;
    int cur_day = get_days(year, month) % 7 + 1;
    if(cur_day == 7)
        cur_day = 0;

    int num_days;
    if(is_big_month(month))
        num_days = 31;
    else if(month == 2){
        num_days = 28;
        if(is_leap_year(year))
            num_days++;
    }
    else{
        num_days = 30;
    }
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
    for(int i = 1; i <= num_days; i++){
        if(i == 1){
            for(int j = 0; j < cur_day; j++)
                cout << "    ";
            cout << "  1";
        }
        else{
            if(i > 1 && i <= 9)
                cout << "  " << i;
            else
                cout << " " << i;
        }

        if(cur_day != 6 && i != num_days)
            cout << " ";
        else
            cout << endl;
        cur_day = (cur_day + 1) % 7;
    }
    return 0;
}