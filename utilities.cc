#include<vector>
#include<map>
#include<string>
#include<fstream>
#include"utilities.h"

vector<string> split(string line) {
    vector<string> tokens;
    string buf = "";
    for(size_t i = 0; i < line.length(); i++) {
        if(line[i] == ' ') {
            if(buf != "")
                tokens.push_back(buf);
            buf = "";
            continue;
        }
        buf += line[i];
    }
    tokens.push_back(buf);       // last chars are not saved because never occurs a blank character...
    return tokens;
}

ostream& serialize(ostream& os, const map<string, long>& data) {
    auto it = data.begin();
    auto proper_end = --data.end();
    while(it != proper_end) {
        os << it->first << " " << it->second << endl;
        it++;
    }
    os << it->first << " " << it->second << endl;
    os << "#" << endl;
    return os;
}
