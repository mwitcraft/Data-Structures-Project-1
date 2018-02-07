#include <iostream>
using namespace std;

class DataFrame{
protected:
    int**   table;
    int     numRows;
    int     numCols;
    char**  rowNames;
    char**  colNames;

public:
    //Constructors
    DataFrame();
    DataFrame(int rows, int cols);

    //Output method
    void display();

    //Setters
    void setRowName(int row, const char* name);
    void setColName(int col, const char* name);

    void setTableVal(int row, int col, int val);

    int* operator[](int i);

    //Getters
    char** getRowNames();
    char** getColNames();

    int getNumberRows();
    int getNumberCols();

    DataFrame* getColumns(int* columns, int cLen);
    DataFrame* getRows(int* rows, int rLen);
    DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen);

    int** getTable();

    //Destructor
    ~DataFrame();
};

//Default constructor
DataFrame::DataFrame(){}

//Constructor
DataFrame::DataFrame(int rows, int cols){
    numRows = rows;
    numCols = cols;

    //Initializes rowName and colNames to arrays of arrays of the correct size
    rowNames = new char*[rows];
    colNames = new char*[cols];

    //Initializes table as an array of arrays of the correct size
    table = new int*[numRows];
    for(int i = 0; i < numRows; i++){
        table[i] = new int[numCols];
    }
}

//Displays information to console
void DataFrame::display(){

    //Steps through colNames and prints out each array of characters seperated by a comma.
    for(int i = 0; i < numCols; i++){
        //If it is the last name in the array, it breaks the line
        if(i == numCols - 1)
            cout << colNames[i] << '\n';
        //Adds comma in between names
        else
            cout << colNames[i] << ",";
    }

    //Exact same as printing out the colNames above
    for(int i = 0; i < numRows; i++){
        if(i == numRows - 1)
            cout << rowNames[i] << '\n';
        else
            cout << rowNames[i] << ",";
    }

    //Prints out the contents of the table by stepping through each value in the array of arrays
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            //Adds space in between values
            cout << table[i][j] << " ";
        }
        //Breaks line at the end of a row
        cout << endl;
    }
}

//Sets a row name at a given row
void DataFrame::setRowName(int row, const char* name){
    rowNames[row] = (char*)name;
}

//Sets a column name at a given column
void DataFrame::setColName(int col, const char* name){
    colNames[col] = (char*)name;
}

//Sets the table value at a given table location
void DataFrame::setTableVal(int row, int col, int val){
    table[row][col] = val;
}

//Not really that sure how this one works
//Made it to where it works with the last example.
int* DataFrame::operator[](int i){
    int* vals = new int[100];

    //Sets table values
    //Steps through numCols and assigns an empty name for each column
    for(int j = 0; j < numCols; j++){
        table[i][j] = i * j;
        colNames[j] = "";
    }

    //Steps through numRows and assigns an empty name for each row
    for(int j = 0; j < numRows; j++){
        rowNames[j] = "";
    }

    //Don't know  how to use this
    return vals;
}

//Returns rowNames
char** DataFrame::getRowNames(){
    return rowNames;
}

//Returns colNames
char** DataFrame::getColNames(){
    return colNames;
}

//Returns numRows
int DataFrame::getNumberRows(){
    return numRows;
}

//Returns numCols
int DataFrame::getNumberCols(){
    return numCols;
}

//Returns a DataFrame object that only has the columns specified from the original object
DataFrame* DataFrame::getColumns(int* columns, int cLen){
    //Creates new DataFrame object with the same number of rows as the original object because that is not changed
    //However the number of columns has changed
    DataFrame* tempCols = new DataFrame(numRows, cLen);

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < cLen; j++){
            //selects the first column from the given columns array
            int col = columns[j];
            //Sets the table value at the given location from the value of the original object
            //at the same row, but from the given column
            tempCols->setTableVal(i, j, table[i][col]);
            //Sets the column name from the original object
            tempCols->setColName(j, colNames[col]);
        }
        //Sets the row name after all of the values from the columns at that one row are set
        tempCols->setRowName(i, rowNames[i]);
    }
    return tempCols;
}

//Same as getColumns, but reordered to manipulate rows instead
DataFrame* DataFrame::getRows(int* rows, int rLen){
    DataFrame* tempRows = new DataFrame(rLen, numCols);

    for(int i = 0; i < numCols; i++){
        for(int j = 0; j < rLen; j++){
            int row = rows[j];
            tempRows->setTableVal(j, i, table[row][i]);
            tempRows->setRowName(j, rowNames[row]);
        }
        tempRows->setColName(i, colNames[i]);
    }
    return tempRows;
}

//Combines getColumns and getRows by not stepping through every value in rows or cols,
//but only those specified
DataFrame* DataFrame::getRowsCols(int* rows, int rLen, int* cols, int cLen){
    DataFrame* tempRowsCols = new DataFrame(rLen, cLen);

    for(int i = 0; i < cLen; i++){
        int col = cols[i];
        for(int j = 0; j < rLen; j++){
            int row = rows[j];
            tempRowsCols->setTableVal(j, i, table[row][col]);
            tempRowsCols->setRowName(j, rowNames[row]);
        }
        tempRowsCols->setColName(i, colNames[col]);
    }
    return tempRowsCols;
}

//Returns table
int** DataFrame::getTable(){
    return table;
}

//Deletes the object pointer objects
DataFrame::~DataFrame(){
    delete[] table;
    delete[] rowNames;
    delete[] colNames;
}


int main(){
    int nCols;
    int nRows;
    int selectC[3];
    int selectR[10];

    //Reads in the first 2 values from the text file
    cin >> nRows >> nCols;
    //Creates DataFrame object using those values ^^
    DataFrame* firstDF = new DataFrame(nRows, nCols);

    //Next line contains the information for the column names
    for(int i = 0; i < nCols; i++){
        //Length of names is unknown, so initialized to a unreasonably large number
        char* name = new char[100];
        char c;
        //Reads the next value(no whitespace or new line characters)
        cin >> c;
        int j = 0;
        //If c == ',' or c == '\n', then it signifies the end of that particular name
        while(c != ',' && c != '\n'){
            name[j] = c;
            //Selects the next character, even spaces and new lines
            cin.get(c);
            j++;
        }
        //'\0' == null which tells the compiler it is the end of an array
        name[j] = '\0';

        //After entire name is read, it sets the column name
        firstDF->setColName(i, name);
    }

    //Next line contains the information for the row names
    //The procedure is exactly the same as for the column names
    for(int i = 0; i < nRows; i++){
        char* name = new char[100];
        char c;
        cin >> c;
        int j = 0;
        while(c != ',' && c != '\n'){
            name[j] = c;
            cin.get(c);
            j++;
        }
        name[j] = '\0';
        firstDF->setRowName(i, name);
    }

    //The next nRows number of lines contain the values of the table
    //Step through each value and set the table value at that position
    for(int i = 0; i < firstDF->getNumberRows(); i++){
        for(int j = 0; j < firstDF->getNumberCols(); j++){
            int num;
            cin >> num;
            firstDF->setTableVal(i, j, num);
        }
    }

    //Displays DataFrame
    firstDF->display();

    //Populates selectC with [0,1,2]
    for(int i = 0; i < 3; i++){
        cin >> selectC[i];
    }

    //Creates a new DataFrame object using the 3 columns in selectC from firstDF
    DataFrame* tempCols = firstDF->getColumns(selectC, 3);

    //Displays DataFrame
    tempCols->display();

    //Changes row names at posistion specified
    tempCols->setRowName(2, "Jack");
    tempCols->setRowName(3, "Peter");

    //Display DataFrame
    tempCols->display();

    //Populates selectR with 0-9
    for(int i = 0; i < 10; i++){
        cin >> selectR[i];
    }

    //Creates new DataFrame object using the 10 rows in selectR from firstDF
    DataFrame* tempRows = firstDF->getRows(selectR, 10);

    //Displays DataFrame
    tempRows->display();

    //Changes column names at position specified
    tempRows->setColName(2, "Scores");
    tempRows->setColName(3, "Values");

    //Displays DataFrame
    tempRows->display();

    //Creates new DataFrame object using the 10 rows in selectR and the 3 columns in selectC
    DataFrame* tempColsRows = firstDF->getRowsCols(selectR, 10, selectC, 3);

    //Displays DataFrame
    tempColsRows->display();

    //Deletes the DataFrame pointer objects
    delete tempRows;
    delete tempCols;
    delete tempColsRows;

    //New DataFrame object with size 5 by 5
    DataFrame* myTable = new DataFrame(5, 5);

    //Not really sure exactly what is going on here...
    //Works, but I need to learn this one
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            (*myTable)[i][j] = i * j;
        }
    }

    //Displays DataFrame
    myTable->display();

    //Deletes the DataFrame pointer object
    delete myTable;
}
