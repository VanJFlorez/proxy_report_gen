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
    ofstream outfile("total");
    vector<map<string, long>> total(NOM_TOKEN); // each map holds the total count of each the 9 token types
    for(int i = 0; i < argc; i++) {
        infile.open(argv[i + 1]);
        int map_number = 1;
        string line;
        vector<string> token;
        while(getline(infile, line)) {
            token = split(line);
            if(line == "#")
                map_number++;        
            else {
                token = split(line);
                total[map_number][token[0]] += atoi(token[1].c_str());
            }

        }
        cout << "file" << i + 1 << " parsed..." << endl;
        infile.close();
    }
    
    for(auto i = 1; i < NOM_TOKEN; i++)  {
        cout << "token " << i << " ok " << endl;
        serialize(outfile, total[i]);

    }
}
