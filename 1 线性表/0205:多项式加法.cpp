// http://dsa.openjudge.cn/linearlist/0205/
// hash table, vector causes MLE

#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int n;
map<int, int> exp_1, exp_2;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num, power;
        while(cin >> num >> power){
            if(power < 0)
                break;
            if(exp_1.find(power) == exp_1.end())
                exp_1[power] = num;
            else
                exp_1[power] += num;
        }
        while(cin >> num >> power){
            if(power < 0)
                break;
            if(exp_2.find(power) == exp_2.end())
                exp_2[power] = num;
            else
                exp_2[power] += num;
        }
        map<int, int>::iterator iter1;
        for(iter1 = exp_1.begin(); iter1 != exp_1.end(); iter1++){
            if(exp_2.find(iter1->first) == exp_2.end())
                exp_2[iter1->first] = iter1->second;
            else
                exp_2[iter1->first] += iter1->second;
        }
        map<int, int>::reverse_iterator iter2;
        for(iter2 = exp_2.rbegin(); iter2 != exp_2.rend(); iter2++){
            if(iter2->second == 0)
                continue;
            // if(iter2 != exp_2.rbegin())
            //     printf(" ");
            printf("[ %d %d ] ", iter2->second, iter2->first);
        }
        printf("\n");

        exp_1.clear();
        exp_2.clear();
    }
    return 0;
}