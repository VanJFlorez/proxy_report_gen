#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<cstdlib>
#include"utilities.h"
#define NOM_TOKEN   10

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

int main(int argc, char** argv) {
    ifstream infile;
    vector<map<string, long>> total(NOM_TOKEN);
    for(int i = 0; i < argc; i++) {
        infile.open(argv[i + 1]);
        int map_number = 1;
        string line;
        vector<string> token;
        
        while(getline(infile, line)) {
            cout << token[0] << " " << token[1] << endl;
            if(line == "#")
                map_number++;        
            else {
                token = split(line);
                total[map_number][token[0]] += atoi(token[1]);
            }

        }
        infile.close();
    }
}
