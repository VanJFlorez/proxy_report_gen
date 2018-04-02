#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#define NOM_TOKEN 10
#define REAL_TOKEN 9 


using namespace std;
// token := time elapsed remotehost code/status bytes method URL rfc931 peerstatus/peerhost type
vector<string> split(string);

int main(int argc, char **argv) {
    ifstream input(argv[1]);
    string log_line;
    vector<string> token;
    map<string, size_t> elapsed_count;
    map<string, size_t> remotehost_count;
    map<string, size_t> codestatus_count;
    map<string, size_t> bytes_count;
    map<string, size_t> method_count;
    map<string, size_t> URL_count;
    map<string, size_t> rfc931_count;
    map<string, size_t> peerstatus_host_count;
    map<string, size_t> type_count;

    while(getline(input, log_line)) {
        token = split(log_line);
        for(auto i = 1; i < REAL_TOKEN + 1; i++) {
            switch (i) {
                case 1:
                    ++elapsed_count[token[i]];
                    break;
                case 2:
                    ++remotehost_count[token[i]];
                    break;
                case 3:
                    ++codestatus_count[token[i]];
                    break;
                case 4:
                    ++bytes_count[token[i]];
                    break;
                case 5:
                    ++method_count[token[i]];
                    break;
                case 6:
                    ++URL_count[token[i]];
                    break;
                case 7:
                    ++rfc931_count[token[i]];
                    break;
                case 8:
                    ++peerstatus_host_count[token[i]];
                    break;
                case 9:
                    ++type_count[token[i]];
                    break;
            }
        }
    }

    for(auto i = 1; i < REAL_TOKEN + 1; i++) {
         switch (i) {
             case 1:
                 for(const auto& entry : elapsed_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 2:
                 for(const auto& entry : remotehost_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 3:
                 for(const auto& entry : codestatus_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 4:
                 for(const auto& entry : bytes_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 5:
                 for(const auto& entry : method_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 6:
                 for(const auto& entry : URL_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 7:
                  for(const auto& entry : rfc931_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 8:
                  for(const auto& entry : peerstatus_host_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
             case 9:
                  for(const auto& entry : type_count)
                    cout << entry.first << " " << entry.second << endl;
                 break;
         }
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
