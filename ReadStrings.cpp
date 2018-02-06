#include <iostream>
using namespace std;

int main(){
    int numRows, numCols;
    char c;
    char** colNames;
    char** rowNames;
    char* curName = new char[10];

    cin >> numRows >> numCols;

    rowNames = new char*[numRows];

    cin >> c;
    int i = 0;
    while(c != '\n'){
        curName[i] = c;
        cin.get(c);
        i++;
        if(c == ',' || c == '\n'){
            curName[i] = '\0';
            cout << curName << endl;
            curName = new char[10];
            cin.get(c);
            i = 0;
        }
    }
    cout << endl;
}
