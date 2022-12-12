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

struct node
{
    int key;
    node* left, * right;
};

node* newNode(int key){
    return &node{key, NULL, NULL};
}


int main(int argc, char const *argv[])
{
    node root = {1, &node{}, &node{}}

    return 0;
}
