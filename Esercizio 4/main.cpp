#include <iostream>

using namespace std;

int main()
{
    string str;

    std::getline(cin >> ws, str);

    while(str.size() > 0){
        cout << str << endl;
        str = str.substr(0, str.size()-1);
    }

    return 0;
}
