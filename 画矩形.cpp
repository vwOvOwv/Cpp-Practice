// http://noi.openjudge.cn/ch0105/42/

#include <iostream>

using namespace std;

int main(){
    int h, w, mode;
    char c;
    cin >> h >> w >> c >> mode;
    if(mode == 0){
        for(int i = 0; i < h; i++){
            if(i == 0 || i == h - 1){
                for(int j = 0; j < w; j++){
                    cout << c;
                }
            }
            else {
                for(int j = 0; j < w; j++){
                    if(j == 0 || j == w - 1)
                        cout << c;
                    else{
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }
    else{
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}