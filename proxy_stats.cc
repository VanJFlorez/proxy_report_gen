#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include"utilities.h"
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

int main(int argc, char **argv) {
    string filename = argv[1];
    ifstream input(filename);
    ofstream output(filename + ".out");

    string log_line;
    vector<string> token;
    vector<map<string, long>> stats(NOM_TOKEN); // [1]

    unsigned i_temp = 1;
    while(getline(input, log_line)) {
        token = split(log_line);
        if(token.size() != 10) {
            cout << "many tokens than expected, size: " << token.size() << " \tline " << i_temp << " not processed!" << endl;
            continue;
        }
        for(auto i = 1; i < NOM_TOKEN; i++) // there are NOM_TOKEN maps but only are used REAL_TOKEN maps (first not used)
            ++stats[i][token[i]];
        i_temp++;
    }

    input.close(); //  [2]

    for(auto i = 1; i < NOM_TOKEN; i++) 
        serialize(output, stats[i]);
}

/*
    [1] The data structure map<T, U> in cpp in each addition keeps the collection
        ordered by key. As we need that be sorted by value (this is, the counters),
        we may think in stablish the comparison criterion to associated value, but by the 
        conception of data structure (binary heap ~ oredered binary tree), this will
        corrupt the automatic sorting of elements. For this reason we use an unordered_map.
*/
