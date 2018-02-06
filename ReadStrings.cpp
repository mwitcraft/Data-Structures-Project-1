#include <iostream>
using namespace std;

int main(){
    char** rowNames;
    int numRows;
    int numCols;
    char c;

    //Reads in the number of columns and rows from the input file and stores them
    cin >> numCols >> numRows;

    //Initializes row names with the first array being the size of the number of rows and the second
    //being the size of the names. (I just guessed 10) probably should figure that out.
    rowNames = new char*[numRows];
    for(int i = 0; i < numRows; i++){
        rowNames[i] = new char[10];
    }

    //Reads in the next character (jumps to the second line where column names are stored)
    cin >> c;
    for(int i = 0; i < numRows; i++){
        //Resets 'j' every time 'i' is incremented.
        int j = 0;
        while(c != ',' && c != '\n'){
            rowNames[i][j] = c;
            //Gets the next character to see if it is a ',' or a '\n' character
            cin.get(c);
            //Increments 'j' if next character is not a ',' or a '\n'
            //Also if it is, allows next character to be '\0'
            j++;
        }
        //Sets final character in array as null. Signals end of word.
        rowNames[i][j] = '\0';
        //Selects next character after ','
        cin.get(c);
    }

    //Prints out the names
    for(int i = 0; i < numRows; i++){
        cout << rowNames[i] << endl;
    }
}

