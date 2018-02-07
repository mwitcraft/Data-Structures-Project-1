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

        table = new int*[numRows];
        for(int i = 0; i < numRows; i++){
            table[i] = new int[numCols];
        }
	}

	//Output method
	void display(){
	    /*
		//Reads each number from the last section of the file and places it in the correct place in the table
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				int num;
				//Must use cin >> so it selects the ints and no whitespaces
				cin >> num;
				if(num != NULL)
                    table[i][j] = num;
                else
                    table[i][j] = NULL;
			}
		}
		*/

		//Prints out the names of the columns. If it is the last name for the columns instead of adding a ',' to the end, it breaks the line

        for(int i = 0; i < numCols; i++){
            if(i == numCols - 1)
                cout << colNames[i] << '\n';
            else
                cout << colNames[i] << ",";
        }



        //Prints out the names of the rows. Works same as above.

        for(int i = 0; i < numRows; i++){
            if(i == numRows - 1)
                cout << rowNames[i] << '\n';
            else
                cout << rowNames[i] << ",";
        }


        //Prints out the contents of the table. Adds a space after each one and break the line after each row.
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
	}

	//Setters
	void setRowName(int row, const char* name){
        rowNames[row] = (char*)name;
	}
	void setColName(int col, const char* name){
        colNames[col] = (char*)name;
	}
	void constructTable(int row, int col, int val){
        table[row][col] = val;
	}


















	int* operator[](int i){
	    int* rowsWithCols = new int[numCols];

	    char* name = new char[100];

        for(int j = 0; j < numCols; j++){
            table[i][j] = i * j;
        }

    /*
        char x;
        cin.get(x);
        if(cin.eof() || x == '\n')
            cout << "x: " << "!" << endl;
        else
            cout << "x: " << x << endl;
    */


        return rowsWithCols;
	}














	//Get row i

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
	DataFrame* getColumns(int* columns, int cLen){
        DataFrame* tempCols = new DataFrame(numRows, cLen);

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < cLen; j++){
                int col = columns[j];
                tempCols->constructTable(i, j, table[i][col]);
                //cout << "++++++++++++++" << colNames[col] << "++++++++++++++" << endl;
                tempCols->setColName(j, colNames[col]);
                //tempCols->table[i][j] = table[i][col];
            }
            //cout << "**********" << rowNames[i] << "***************" << endl;
            tempCols->setRowName(i, rowNames[i]);
        }
    return tempCols;
	}

    DataFrame* getRows(int* rows, int rLen){
        DataFrame* tempRows = new DataFrame(rLen, numCols);

        for(int i = 0; i < numCols; i++){
            for(int j = 0; j < rLen; j++){
                int row = rows[j];
                tempRows->constructTable(j, i, table[row][i]);
                tempRows->setRowName(j, rowNames[row]);
            }
            tempRows->setColName(i, colNames[i]);
        }
        return tempRows;
	}









	DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen){
            DataFrame* tempRowsCols = new DataFrame(rLen, cLen);

            for(int i = 0; i < cLen; i++){
                int col = cols[i];
                for(int j = 0; j < rLen; j++){
                    int row = rows[j];
                    tempRowsCols->constructTable(j, i, table[row][col]);
                    tempRowsCols->setRowName(j, rowNames[row]);
                }
                tempRowsCols->setColName(i, colNames[col]);
            }
            return tempRowsCols;
	}

	int** getTable(){
        return table;
	}

	//Destructor
	~DataFrame(){
        delete [] table;
        delete [] rowNames;
        delete [] colNames;
	}
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
            //Added 1 to 'i' so when user chooses to change the name using column #, the numbering starts at 1 instead of 0
            firstDF->setColName(i, name);
    }
/*
    cout << "firstDF col names: ";
    for(int i = 0; i < nCols; i++){
        cout << firstDF->getColNames()[i];
    }
    cout << endl;
    */

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
    /*
    cout << "firstDF row names: ";
    for(int i = 0; i < nRows; i++){
        cout << firstDF->getRowNames()[i];
    }
    cout << endl;
    */

		for (int i = 0; i < firstDF->getNumberRows(); i++) {
			for (int j = 0; j < firstDF->getNumberCols(); j++) {
				int num;
				//Must use cin >> so it selects the ints and no whitespaces
				cin >> num;
                    firstDF->constructTable(i, j, num);
                    //firstDF->table[i][j] = num;
			}
		}
		/*
		cout << "firstDF table: ";
		for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                cout << firstDF->getTable()[i][j];
            }
		}
		cout << endl;

		cout << "firstDF numCols: " << firstDF->getNumberCols() << endl;
		cout << "firstDF numRows: " << firstDF->getNumberRows() << endl;

		*/




	//Fourth line and more: nCols number of integers in each of the nRows rows seperated by a space
	//						in between integers in the same row

	//TODO: complete code for the above comment block^^^

	//using the display method, print (in the same format as the input):
	// - column names of the dataframe
	// - row names of the dataframe
	// - contents of the table in the dataframe

    firstDF->display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;

	//TODO: complete code for the above comment block^^^

	//Execute the following code when i think its complete??

	for (int i = 0; i < 3; i++) {
		cin >> selectC[i];
	}

	DataFrame* tempColumns = (*firstDF).getColumns(selectC, 3);

	(*tempColumns).display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;
	//Change the row names of select rows

	(*tempColumns).setRowName(2, "Jack");
	(*tempColumns).setRowName(3, "Peter");

	(*tempColumns).display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;
	//Read the row numbers that you want to extract

	for (int i = 0; i < 10; i++) {
		cin >> selectR[i];
	}

	DataFrame* tempRows = (*firstDF).getRows(selectR, 10);

	(*tempRows).display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;

	//Change the column names of selected columns

	(*tempRows).setColName(2, "Scores");
	(*tempRows).setColName(3, "Values");

	(*tempRows).display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;

	//Extract the rows in selectR and columns in selectC

	DataFrame* tempColsRows = (*firstDF).getRowsCols(selectR, 10, selectC, 3);

	(*tempColsRows).display();

    cout << endl;
    cout << "_______________________________________________________" << endl;
    cout << endl;



	delete tempRows;
	delete tempColumns;
	delete tempColsRows;

	//Sample code - must execute

	DataFrame* myTable = new DataFrame(5, 5);



	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
            //myTable->constructTable(i, j, i * j);
			(*myTable)[i][j] = i * j;
			cout << "(" << i << "," << j << ")" << " -> " << myTable->getTable()[i][j] << endl;
        }
	}
/*
	(*myTable).display();
/*
	delete myTable;
	*/

    }
