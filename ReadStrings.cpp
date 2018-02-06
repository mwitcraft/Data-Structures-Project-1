#include <iostream>
using namespace std;

int main(){
    char** rowNames;
    int numRows;
    int numCols;
    char c;

    cin >> numCols >> numRows;

    rowNames = new char*[numRows];
    for(int i = 0; i < numRows; i++){
        rowNames[i] = new char[10];
    }

    cin >> c;
    for(int i = 0; i < numRows; i++){
        int j = 0;
        while(c != ',' && c != '\n'){
            rowNames[i][j] = c;
            cin.get(c);
            j++;
        }
        rowNames[i][j] = '\0';
        cin.get(c);
    }

    for(int i = 0; i < numRows; i++){
        cout << rowNames[i] << endl;
    }
}

