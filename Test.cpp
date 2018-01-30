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

		table = new int*[numRows];
		for (int i = 0; i < numRows; i++) {
			table[i] = new int[numCols];
		}

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				table[i][j] = 0;
			}
		}
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
};

int main() {
	FrameData* fd = new FrameData(2, 3);
	(*fd).display();

	return 0;
}