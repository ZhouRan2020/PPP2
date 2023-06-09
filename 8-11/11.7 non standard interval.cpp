#include "std_lib_facilities.h"

class Punct_stream {
public:
    Punct_stream(istream& is) : source{is}, sensitive{true} { }

    void whitespace(const string& s) { white = s; }

    void add_white(char c) { white += c; }

    bool is_whitespace(char c);

    void case_sensitive(bool b) { sensitive = b; }

    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>> (string& s);

    operator bool ();

private:
    istream& source;
    istringstream buffer;
    string white;
    bool sensitive;
};

int main()
{
    Punct_stream ps { cin };

    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");

    ps.case_sensitive(false);

    vector<string>  vs;

    for (string word; ps >> word;)
        vs.push_back(word);

    sort(vs.begin(), vs.end());

    for (int i=0 ; i < vs.size(); ++i)

        if (i == 0 || vs[i] != vs[i - 1])  
            cout << vs[i] << '\n';

    keep_window_open();
    return 0;
}

bool Punct_stream::is_whitespace(char c) {
    for (char w : white) 

        if (c == w)
            return true;

    return false;
    
}

Punct_stream& Punct_stream::operator>> (string& s) {

    while (!(buffer >> s)) {

        if (buffer.bad() || !source.good()) 
            return *this;

        buffer.clear();

        string line;

        getline(source, line);

        for (char& ch : line) 

            if (is_whitespace(ch))
                ch = ' ';
            else if (!sensitive)
                ch = tolower(ch);
        

        buffer.str(line);
    }

    return *this;
}

Punct_stream::operator bool() {
    return !(source.fail()|| source.bad()) && source.good();
}
