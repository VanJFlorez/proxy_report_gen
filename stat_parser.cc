#include<iostream>
#include<fstream>
#include<vector>
#define TOKEN_NUMBER 10


using namespace std;
// token := time elapsed remotehost code/status bytes method URL rfc931 peerstatus/peerhost type
vector<string> split(string);

int main(int argc, char **argv) {
    ifstream input(argv[1]);
    string log_line;
    vector<string> tokens;
    
    vector<string> rare_lines;
    bool rare_flags[6] = {};
    
    unsigned i = 0;
    while(getline(input, log_line)) {
        tokens = split(log_line);
        sz = tokens.size();
        switch (sz):
        case 10: 
            if(!rare_flags[0])
                rare_lines.push_back(log_line);
            rare_flags[0] = true;
            break;
        case 11: 
            if(!rare_flags[1])
                rare_lines.push_back(log_line);
            rare_flags[1] = true;
            break;
        case 12: 
            if(!rare_flags[2])
                rare_lines.push_back(log_line);
            rare_flags[2] = true;
            break;
        case 13: 
            if(!rare_flags[3])
                rare_lines.push_back(log_line);
            rare_flags[3] = true;
            break;
        case 14: 
            if(!rare_flags[4])
                rare_lines.push_back(log_line);
            rare_flags[4] = true;
            break;
        case 15: 
            if(!rare_flags[5])
                rare_lines.push_back(log_line);
            rare_flags[5] = true;
            break;
    }

}

vector<string> split(string line) {
    vector<string> tokens;
    string buf = "";
    for(size_t i = 0; i < line.length(); i++) {
        if(line[i] == ' ') {
            tokens.push_back(buf);
            buf = "";
            continue;
        }
        buf += line[i];
    }
    tokens.push_back(buf);       // last chars are not saved because never occurs a blank character...

    for ( int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << "_";
    cout << endl;
    cout << "prev size(): " << tokens.size() << endl;
return tokens;
}
