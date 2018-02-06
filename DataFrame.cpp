#include <iostream>
using namespace std;

class DataFrame {
protected:
	int**   table;
	int     numRows;
	int     numCols;
	char**  rowNames;
	char**  colNames;

public:
	//Constructors
	DataFrame();
	DataFrame(int rows, int cols){
        numRows = rows;
        numCols = cols;

        rowNames = new char*[rows];
        colNames = new char*[cols];
	}

	//Output method
	void display();

	//Setters
	void setRowName(int row, char* name){
        rowNames[row] = name;
	}
	void setColName(int col, char* name){
        colNames[col] = name;
	}
	int* operator[](int i); //Get row i

	//Getters
	char** getRowNames(){
        return rowNames;
	}
	char** getColNames(){
        return colNames;
	}
	int getNumberRows(){
        return numRows;
	}
	int getNumberCols(){
        return numCols;
	}
	DataFrame* getColumns(int* columns, int cLen);
	DataFrame* getRows(int* rows, int rLen);
	DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen);

	//Destructor
	~DataFrame();
};

int main() {
	int nCols;
	int nRows;
	int selectC[3];
	int selectR[10];

	//Read dataframe from input
	//First line: 2 numbers seperated by space;
	//			  first number is number of rows (r) and
	//			  second number is number of columns (c)

	cin >> nRows >> nCols;
	DataFrame* firstDF = new DataFrame(nRows, nCols);

	//Second line: strings seperated by a comma (nCols of them); representing column names
    for(int i = 0; i < nCols; i++){
        //Initailizes char* name to have length of 100 because we don't know actual size (yet)
        char* name = new char[100];
        char c;
        //Must use cin >> to select next 'real' character (not '\n')
        cin >> c;
        int j = 0;
        //If c == ',' or '\n' then that is the end of that name
        while(c != ',' && c != '\n'){
            name[j] = c;
            //use cin.get because that actually selects the next character, regardless of what it is (actually selects '\n')
            cin.get(c);
            j++;
        }
            //Signals end of name[]
            name[j] = '\0';
            firstDF->setColName(i, name);
    }
    for(int i = 0; i < nCols; i++){
        cout << firstDF->getColNames()[i] << " ";
    }
    cout << endl;
    cout << "**********************" << endl;
	//Third line: string seperated by a comma (nRows of them); representing row names
	//Exact same as above but this time setting the column names
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

    for(int i = 0; i < nRows; i++){
        cout << firstDF->getRowNames()[i] << endl;
    }
	//Fourth line and more: nCols number of integers in each of the nRows rows seperated by a space
	//						in between integers in the same row

	//TODO: complete code for the above comment block^^^

	//using the display method, print (in the same format as the input):
	// - column names of the dataframe
	// - row names of the dataframe
	// - contents of the table in the dataframe

	//TODO: complete code for the above comment block^^^

	//Execute the following code when i think its complete??

/*
	for (int i = 0; i < 3; i++) {
		cin >> selectC[i];
	}

	DataFrame* tempColumns = (*firstDF).getColumns(selectC, 3);

	(*tempColumns).display();

	//Change the row names of select rows

	(*tempColumns).setRowName(2, "Jack");
	(*tempColumns).setRowName(3, "Peter");

	(*tempColumns).display();

	//Read the row numbers that you want to extract

	for (int i = 0; i < 10; i++) {
		cin >> selectR[i];
	}

	DataFrame* tempRows = (*firstDF).getRows(selectR, 10);

	(*tempRows).display();

	//Change the column names of selected columns

	(*tempRows).setColName(2, "Scores");
	(*tempRows).setColName(3, "Values");

	(*tempRows).display();

	//Extract the rows in selectR and columns in selectC

	DataFrame* tempColsRows = (*firstDF).getRowsCols(selectR, 10, selectC, 3);

	(*tempColsRows).display();

	delete tempRows;
	delete tempCols;
	delete tempColsRows;

	//Sample code - must execute

	DataFrame* myTable = new DataFrame(5, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			(*myTable)[i][j] = i * j;
		}
	}

	(*myTable).display();

	delete myTable;
	*/
}
