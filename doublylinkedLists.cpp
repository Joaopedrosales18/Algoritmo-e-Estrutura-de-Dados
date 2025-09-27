#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

void printForward(Node* head) {
    Node* traverser = head;
    while (traverser != nullptr){
        cout << traverser -> value << endl;
        traverser = traverser -> next;
    }
}

void printBackwards(Node* tail) {
    Node* traverser = tail;
    while (traverser != nullptr){
        cout << traverser -> value << endl;
        traverser = traverser -> prev;
    }
}

int main() {

    Node* head;
    Node* tail;
    //adding 1st node to list
    Node* node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    //adding 2nd node to list
    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    //adding 3rd node to list
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    //adding 4th node to list
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    cout << "\n";
    printBackwards(tail);

    return 0;
}