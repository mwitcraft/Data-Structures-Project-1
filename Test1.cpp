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

		rowNames = new char*[numRows];
		for (int i = 0; i < numRows; i++) {
			rowNames[i] = (char*)"*";
		}
	}

	void setRowName(int row, char* name) {
		cout << "Setting row " << row << " to " << name << endl;
		for (int i = 0; i <= numRows; i++) {
			if (i == row) {
				rowNames[i-1] = name;
			}
		}
	}

	void setColName(int col, char* name) {

	}

	void display() {
		cout << "Number of rows " << numRows << endl;
		cout << "Number of columns " << numCols << endl;
		cout << "***************************" << endl;

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}

	void displayName() {
		for (int i = 0; i < numRows; i++) {
			cout << rowNames[i] << endl;
		}
	}
};

int main() {
	FrameData* fd = new FrameData(8, 3);

	(*fd).setRowName(2, (char*)"Mason");
	fd->setRowName(1, (char*)"Reece");
	fd->setRowName(8, (char*)"Jessie");
	fd->displayName();

	return 0;
}
