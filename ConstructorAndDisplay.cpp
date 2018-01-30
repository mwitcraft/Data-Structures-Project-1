/*
#include <iostream>
using namespace std;

class FrameData {

public:

	int** table;
	int numRows;
	int numCols;

	FrameData(int rows, int cols) {
		numRows = rows;
		numCols = cols;

		//Initializes table as an int*[] with the size of numRows
		table = new int*[numRows];
		for (int i = 0; i < numRows; i++) {
			//Inside of each int*, a new int*[] of size numCols is created
			table[i] = new int[numCols];
		}

		//Steps through the number of rows and columns to make a DataFrame
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				//Each possible entry in the DataFrame is initially given the value of 0
				table[i][j] = 0;
			}
		}
	}

	void display() {
		cout << "Number of rows " << numRows << endl;
		cout << "Number of columns " << numCols << endl;
		cout << "***************************" << endl;

		//Steps through each column in each row and prints out the contents of the pointer
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				//Space at end of value for formatting
				cout << table[i][j] << " ";
			}
			//Ends line at end of each row for formatting
			cout << endl;
		}
	}
};

int main() {
	FrameData* fd = new FrameData(2, 3);
	(*fd).display();

	return 0;
}
*/