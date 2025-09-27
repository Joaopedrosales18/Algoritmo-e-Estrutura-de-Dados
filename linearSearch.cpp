#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int searchValue){

    for(int j = 0; j < size; j++){
        if (searchValue == array[j]){
            return j;
        }
    }
    return -1;
}

int main()
{
    int array[5];
    int userValue;
    int size = sizeof(array)/ sizeof(array[0]);

    cout << "Enter 5 integers to the array: " << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    cout << "Enter an integer to search: " << endl;
    cin >> userValue;

    int result = linearSearch(array, 5, userValue);

    if (result >= 0) {
        cout << "The number " << array[result] << " was found at the index " << result << endl;
    }
    else{
        cout << "The number " << userValue << " was not found";
    }
}