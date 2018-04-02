#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#define NOM_TOKEN 10
#define REAL_TOKEN 9 


using namespace std;
/*
token := time elapsed remotehost code/status bytes method URL rfc931 peerstatus/peerhost type
maps code:
map[ 0 ] := time
map[ 1 ] := elapsed
map[ 2 ] := remotehost
map[ 3 ] := code/status
map[ 4 ] := bytes
map[ 5 ] := method
map[ 6 ] := URL
map[ 7 ] := rfc931
map[ 8 ] := peerstatus/peerhost
map[ 9 ] := type

*/
vector<string> split(string);
ostream& serialize(ostream& , const map<string, size_t>&);

int main(int argc, char **argv) {
    string filename = argv[1];

    ifstream input(filename);
    ofstream output(filename + ".out");

    string log_line;
    vector<string> token;
    vector<map<string, size_t>> stats(NOM_TOKEN);

    while(getline(input, log_line)) {
        token = split(log_line);
        for(auto i = 1; i < NOM_TOKEN; i++) {
            ++stats[i][token[i]];
        }
    }

    input.close();

    for(auto i = 1; i < NOM_TOKEN; i++) 
        serialize(output, stats[i]);
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

ostream& serialize(ostream& os, const map<string, size_t>& data) {
    auto it = data.begin();
    auto proper_end = --data.end();
    os << "{";
    while(it != proper_end) {
        os << "{" << it->first << ", " << it->second << "}, ";
        it++;
    }
    os << "{" << it->first << ", " << it->second << "}";
    os << "}" << endl;
    return os;
}
