// http://bailian.openjudge.cn/practice/2814/

#include <iostream>
#include <vector>

using namespace std;

int num_clocks = 9;
int max_op = 4;

int main(){
    vector<int> clocks(9);
    vector<vector<int> > ans;
    for(int i = 0; i < 9; i++){
        cin >> clocks[i];
    }
    for(int cnt1 = 0; cnt1 < max_op; cnt1++){
        for(int cnt2 = 0; cnt2 < max_op; cnt2++){
            for(int cnt3 = 0; cnt3 < max_op; cnt3++){
                for(int cnt4 = 0; cnt4 < max_op; cnt4++){
                    for(int cnt5 = 0; cnt5 < max_op; cnt5++){
                        for(int cnt6 = 0; cnt6 < max_op; cnt6++){
                            for(int cnt7 = 0; cnt7 < max_op; cnt7++){
                                for(int cnt8 = 0; cnt8 < max_op; cnt8++){
                                    for(int cnt9 = 0; cnt9 < max_op; cnt9++){
                                        vector<int> tmp_clocks = clocks;
                                        tmp_clocks[0] = (tmp_clocks[0] + cnt1 + cnt2 + cnt4) % 4;
                                        if(!tmp_clocks[0]){
                                            tmp_clocks[1] = (tmp_clocks[1] + cnt1 + cnt2 + cnt3 + cnt5) % 4;
                                            if(!tmp_clocks[1]){
                                                tmp_clocks[2] = (tmp_clocks[2] + cnt2 + cnt3 + cnt6) % 4;
                                                if(!tmp_clocks[2]){
                                                    tmp_clocks[3] = (tmp_clocks[3] + cnt1 + cnt4 + cnt5 + cnt7) % 4;
                                                    if(!tmp_clocks[3]){
                                                        tmp_clocks[4] = (tmp_clocks[4] + cnt1 + cnt3 + cnt5 + cnt7 + cnt9) % 4;
                                                        if(!tmp_clocks[4]){
                                                            tmp_clocks[5] = (tmp_clocks[5] + cnt3 + cnt5 + cnt6 + cnt9) % 4;
                                                            if(!tmp_clocks[5]){
                                                                tmp_clocks[6] = (tmp_clocks[6] + cnt4 + cnt7 + cnt8) % 4;
                                                                if(!tmp_clocks[6]){
                                                                    tmp_clocks[7] = (tmp_clocks[7] + cnt5 + cnt7 + cnt8 + cnt9) % 4;
                                                                    if(!tmp_clocks[7]){
                                                                        tmp_clocks[8] = (tmp_clocks[8] + cnt6 + cnt8 + cnt9) % 4;
                                                                        if(!tmp_clocks[8]){
                                                                            vector<int> res = {cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9, 
                                                                                cnt1 + cnt2 + cnt3 + cnt4 + cnt5 + cnt6 + cnt7 + cnt8 + cnt9};
                                                                            ans.push_back(res);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<int> >::iterator i = ans.begin();
    int min_ops = 0x7fffffff;
    int min_idx = -1;
    int idx = -1;
    for(; i != ans.end(); ++i){
        idx++;
        // for(auto j = i->begin(); j != i->end(); ++j){
        //     cout << *j << ' ';
        // }
        // cout << endl;
        if(i->back() < min_ops){
            min_ops = i->back();
            min_idx = idx;
        }
    }
    for(int k = 0; k < 9; k++){
        for(int j = 0; j < ans[min_idx][k]; j++){
            cout << k + 1 << ' ';
        }
    }
    return 0;
}