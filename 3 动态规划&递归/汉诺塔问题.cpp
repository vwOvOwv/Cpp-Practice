// http://noi.openjudge.cn/ch0202/6261/

#include <iostream>

using namespace std;

void hanoi(int start_plate_idx, int n_plates, char start, char target, char medium){
    if(n_plates == 1){
        cout << start << "->" <<start_plate_idx << "->" << target << endl;
        return;
    }
    hanoi(start_plate_idx, n_plates - 1, start, medium, target);
    hanoi(n_plates, 1, start, target, medium);
    hanoi(start_plate_idx, n_plates - 1, medium, target, start);
}

int main(){
    int n;
    char c1, c2, c3;
    cin >> n >> c1 >> c2 >> c3;
    hanoi(1, n, c1, c2, c3);
    return 0;
}