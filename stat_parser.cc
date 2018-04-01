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
    
    unsigned i = 1;
    while(getline(input, log_line)) {
        tokens = split(log_line);
        if(tokens.size() != 10) {
            cout << i << endl;
            cout << tokens.size() << endl;
            cout << "exit" << endl;
            break;
        }
        i++;
    }
}

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
