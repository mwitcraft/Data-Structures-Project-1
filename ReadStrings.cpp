#include <iostream>
using namespace std;

int main(){
    char c;
    int size = 0;

    cin.get(c);

    while (!cin.eof() && c != '\n'){
        if(c != ','){
            size++;
        }else{
            size = 0;
        }

        cin.get(c);
    }

    cout << size << endl;

}
