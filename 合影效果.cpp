// http://noi.openjudge.cn/ch0110/07/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<string, vector<double>> dict;
    string sex;
    double height;
    while(n--){
        cin >> sex >> height;
        dict[sex].push_back(height);
    }
    sort(dict["male"].begin(), dict["male"].end());
    sort(dict["female"].begin(), dict["female"].end(), greater<double>());
    int n_male = dict["male"].size();
    int n_female = dict["female"].size();
    for(int i = 0; i < n_male; i++){
        cout << fixed << setprecision(2) << dict["male"][i] << ' ';
    }
    for(int i = 0; i < n_female; i++){
        cout << fixed << setprecision(2) << dict["female"][i];
        if(i < n_female - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}