#include "../std_lib_facilities.h"
int main()
{
    vector<string>  dictionary;
    vector<string> const disliked{"cat","monkey"};
    for (string temp; cin >> temp;) {
        dictionary.push_back(temp);
    }
    sort(dictionary);
    string pervious;
    string current;
    for (const string& x : dictionary) {     
        current = x;
        if (current != pervious) {
            bool dislike = false;
            for (const string& y : disliked) {
                if (current == y)
                    dislike = true;
            }
            if (!dislike) {
                cout << current << "\n";
            }
            else {
                cout << "NO!\n";
            }           
        }    
        pervious = current;
    }
    keep_window_open();
    return 0;
}
