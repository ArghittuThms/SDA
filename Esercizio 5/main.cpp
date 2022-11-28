#include <iostream>

using namespace std;

int main()
{
    string str = "", result = "";

    getline(cin >> ws, str);

    for (int i=1; i<=str.size(); i++){
        result += str.at(str.size()-i);
    }

    cout << result;

    return 0;
}
