#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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

/// Ricerca in tempo lineare
int linearSearch(vector<int> *A, int num){
    for (int i=0; i<A->size(); i++){
        if (num == A->at(i))    return i + 1;
    }
    return -1;
}

/// Ricerca in tempo logaritmico
int logarithmSearchRec(vector<int> *A, int num, int p, int q){    
    if (q<p) return -1;
    else{
        int r = (p + q)  / 2;
    
        if(A->at(r) == num) return r;
        
        else if(A->at(r) > num) return logarithmSearchRec(A, num, p, r-1);
        
        else return logarithmSearchRec(A, num, r+1, q);
    }
}

int logarithmSearch(vector<int> *A, int num){
    return logarithmSearchRec(A, num, 0, A->size()-1);
}

/// Main
int main(int argc, char const *argv[])
{
    vector<int> A;
    int num;

    cin >> A;
    cin >> num;

    cout << logarithmSearch(&A, num);

    return 0;
}
