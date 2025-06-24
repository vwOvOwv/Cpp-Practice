// http://bailian.openjudge.cn/practice/1006/
// 简单的数学题

# include <iostream>

using namespace std;

int Tp = 23, Te = 28, Ti = 33;

int main(){
    int p, e, i, d;
    int case_cnt = 0;
    while(cin >> p >> e >> i >> d && p != -1){
        bool found = false;
        case_cnt++;
        cout << "Case " << case_cnt << ": the next triple peak occurs in ";
        for(int ki = 0; ; ki++){    // 注意
            int x = i - ki * Ti;
            if(x > d && ((x - e) % Te == 0) && ((x - p) % Tp == 0)){
                found = true;
                cout << x - d << " days." << endl;
                break;
            }
            if(x < 0)
                break;
        }
        if(found) 
            continue;
        for(int ki = 1; ; ki++){
            int x = i + ki * Ti;
            if(x > d && ((x - e) % Te == 0) && ((x - p) % Tp == 0)){
                cout << x - d << " days." << endl;
                break;
            }
        }
    }
    return 0;
}