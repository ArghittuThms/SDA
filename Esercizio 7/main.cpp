#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

ostream &operator << (ostream &out, const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

istream &operator >> (istream &in, vector<int> &vec) {
    // scan line of text 
    string line;
    getline(in, line);

    // convert line of text into a new input stream
    istringstream is(line);
    
    // convert new input stream into array
    int value;
    while (is >> value)
        vec.push_back(value);

    return in;
}

/// Somma per intervalli - Somme parziali
int intervalSum(vector<int> *A, int p, int q){
    vector<int> B = {0};

    for(int i=1; i<=A->size(); i++){
        B.push_back(B.at(i-1) + A->at(i-1));
    }

    return B.at(q)-B.at(p);
}

/// Main
int main(int argc, char const *argv[])
{
    vector<int> A;
    vector<int> range;

    cin >> A;
    cin >> range;

    //auto start = high_resolution_clock::now();
    cout << intervalSum(&A, range.at(0), range.at(1)+1);
    //auto end  = high_resolution_clock::now();
    
    //auto duration = duration_cast<microseconds>(end - start);
    //cout << "\n Tempo Impiegato:\t" << duration.count();
    return 0;
}

// * COMPLESSITA' SOMMA PER INTERVALLO
// - Allocazione del vettore B      -> (H)(1)
// - Calcolo somme parziali A       -> (H)(n)
// - Calcolo somma intervallo A     -> (H)(1)
//
// - Risultato                      -> (H)(n)