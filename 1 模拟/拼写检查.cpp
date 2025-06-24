// http://dsa.openjudge.cn/linearlist/0201/
// enumeration

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> dict;

void check_word(string word){
    int len = dict.size();
    bool correct = false;
    vector<string> similar;
    for(int i = 0; i < len; i++){
        string dict_word = dict[i];
        // cout << word << dict_word << endl;
        int dict_word_len = dict_word.size();
        int word_len = word.size();
        // cout << word_len << dict_word_len << endl;
        if(dict_word_len == word_len){
            if(word.compare(dict_word) == 0){
                correct = true;
            }
            else{
                int diff_count = 0;
                for(int j = 0; j < word_len; j++){
                    if(word[j] != dict_word[j])
                        diff_count++;
                }
                if(diff_count == 1){
                    similar.push_back(dict_word);
                }
            }
        }
        else if(abs(dict_word_len - word_len) == 1){
            if(dict_word_len < word_len){
                for(int j = 0; j < word_len; j++){
                    string tmp = word;
                    tmp.erase(j, 1);
                    if(tmp.compare(dict_word) == 0){
                        similar.push_back(dict_word);
                        break;  // important
                    }
                }
            }
            else{
                for(int j = 0; j < dict_word_len; j++){
                    string tmp = dict_word;
                    tmp.erase(j, 1);
                    if(tmp.compare(word) == 0){
                        similar.push_back(dict_word);
                        break;  // important
                    }
                }
            }
        }
    }
    if(correct){
        cout << word << " is correct";
    }
    else{
        cout << word << ":";
        int similar_counts = similar.size();
        for(int j = 0; j < similar_counts; j++){
            cout << " " << similar[j];
        }
    }
    cout << endl;
}

int main(){
    string word;
    while(cin >> word){
        if(word == "#"){
            break;
        }
        dict.push_back(word);
    }
    while(cin >> word){
        if(word == "#"){
            break;
        }
        check_word(word);
    }
    return 0;
}