#include <iostream>
using namespace std;

int bS(int array[], int size, int userTarget){

    int low = 0;
    int high = size - 1;
    
    int mid;
    while (low <= high){

        mid = (low + high) / 2;
        
        if (userTarget  == array[mid]){
            return mid;
        }
        else if (userTarget > array[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main() {

        int array[10];
        int userTarget;
        int size = sizeof(array)/sizeof(array[0]);

        cout << "Enter 10 integers to fill the array: ";
        for (int i = 0; i < size; i++){
            cin >> array[i];
        }

        cout << "Enter an integer you wanna find: " <<  endl;
        cin >> userTarget;

        int index = bS(array, 10, userTarget);

        if (index >= 0) {
            cout << "The number " << array[index] << " was found at the element with index " << index << endl; 
        }
        else{
            cout << "The number " << userTarget << " was not found. " << endl;
        }

    return 0;

}