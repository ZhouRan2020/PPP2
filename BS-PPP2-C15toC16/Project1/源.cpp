#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<numeric>
using namespace std;
class Solution {
    bool is_e(const string& a, const string& b) {
        vector<int> alphabet_a = obtain_alphabet(a);
        vector<int> alphabet_b = obtain_alphabet(b);
        return alphabet_a == alphabet_b;
    }
    vector<int> obtain_alphabet(const string& a) {
        vector<int> alphabet_a(26, 0);
        for (char t : a) {
            alphabet_a[t - 'a']++;
        }
        return alphabet_a;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int it = 0; it < words.size(); ++it) {
            vector<int> e_list;
            for (int i = it + 1; i < words.size(); ++i) {
                if (is_e(words[it], words[i])) {
                    e_list.push_back(i);
                }
            }
            for (int i = 0; i < e_list.size(); ++i) {
                words.erase(words.begin() + e_list[i]);
            }

        }
        return words;
    }
};
int main() {
    vector<int> k;
    
    for (int sum = 0,  i = 5,  y = 9; i < 100; ++i) {
        sum += i+y;
    }
}
