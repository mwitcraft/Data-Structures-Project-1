#include <iostream>
using namespace std;

class FrameData {

public:

	int** table;
	int numRows;
	int numCols;
	char** colNames;
	char** rowNames;

	FrameData(int rows, int cols) {
		numRows = rows;
		numCols = cols;

		table = new int*[numRows];
		for (int i = 0; i < numRows; i++) {
			table[i] = new int[numCols];
		}

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				table[i][j] = 0;
			}
		}

		//Initializes rowNames to be a char*[] of size numRows, then sets initial name of every row to '*'
		rowNames = new char*[numRows];
		for (int i = 0; i < numRows; i++) {
			rowNames[i] = (char*)"*";
		}

		//Initializes colNames to be a char*[] of size colRows, then sets initial name of every column to '*'
		colNames = new char*[numCols];
		for (int i = 0; i < numCols; i++) {
			colNames[i] = (char*)"*";
		}
	}

	//Sets the row specified to the given name
	void setRowName(int row, char* name) {
		//cout << "Setting row " << row << " to " << name << endl;
		for (int i = 0; i <= numRows; i++) {
			if (i == row) {
				//Must do 'i-1' because of 0 index
				rowNames[i - 1] = name;
			}
		}
	}

	//Sets the column specified to the given name
	void setColName(int col, char* name) {
		//cout << "Setting column " << col << " to " << name << endl;
		for (int i = 0; i <= numCols; i++) {
			if (i == col) {
				//Must do 'i-1' because of 0 index
				colNames[i - 1] = name;
			}
		}
	}

	void display() {
		//cout << "Number of rows " << numRows << endl;
		//cout << "Number of columns " << numCols << endl;
		//cout << "***************************" << endl;

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}

	//Just steps through rowNames and printes out what is stored at each index
	//The two 'endl' are there for formatting
	void displayRowNames() {
		for (int i = 0; i < numRows; i++) {
			cout << rowNames[i] << endl << endl;
		}
	}
	
	//Steps through colNames and prints out what is stored at each index
	//The two tab characters '\t' are there for formatting
	void displayColNames() {
		for (int i = 0; i < numCols; i++) {
			cout << "\t" << colNames[i] << "\t";
		}
		cout << endl;
	}
};

int main() {
	FrameData* fd = new FrameData(8, 6);

	//Test data
	(*fd).setRowName(2, (char*)"Mason");
	fd->setRowName(1, (char*)"Reece");
	fd->setRowName(8, (char*)"Jessie");

	//Test data
	fd->setColName(6, (char*)"Six");
	fd->setColName(1, (char*)"One");
	fd->setColName(2, (char*)"Two");
	fd->setColName(3, (char*)"Three");

	fd->displayColNames();
	fd->displayRowNames();
	return 0;
}
