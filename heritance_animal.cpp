#include <iostream>
using namespace std;

class Animal{
    public:
        bool alive = true;
        void eat(){
            cout << "This animal is eating\n";
        }
};

class Dog : public Animal {
    public:

    void bark(){
        cout << "The dog goes woof!\n";
    }
};

class Cat : public Animal {
    public:

    void meow() {
        cout << "The cat goes meow!\n";
    }
};

int main() {
Dog doggy;
Cat cat;

    cout << doggy.alive << endl;
    doggy.eat();
    doggy.bark();

    cout << cat.alive << endl;
    cat.eat();
    cat.meow();

}
