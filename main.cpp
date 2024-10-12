#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Goat {
        private:
        int age;
        string name;
        string color;
        string names[15] = {"Ava", "Jack", "Ben", "Gloria", "Emma", "Emily", "Landon", "Jennifer", "Emelia", "Aidan", "Alex", "Lucas", "Rory", "Sterling", "Prince"};
        string colors[15] = {"Red", "Pink", "Green", "Orange", "Yellow", "Purple", "Blue", "Brown", "Coral", "Aqua", "Beige", "Black", "White", "Gray", "Cream"};

        public:
        //constructors
        Goat() {
            age = rand() % (20-1+1) + 1;
            name = names[rand() % 15];
            color = colors[rand() % 15];
        }
        Goat(int a, string n, string c)     { age = a; name = n; color = c; }

        int getAge() const        { return age; }
        string getName() const    { return name; }
        string getColor() const   { return color; }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat g, Node* p = nullptr, Node* n = nullptr) {
            data = g; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat g) {
        Node* newNode = new Node(g);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {
        Node* newNode = new Node(g);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty.\n";
            return;
        }
        while (current) {
            cout << "\t" << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")\n"; 
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty.\n";
            return;
        }
        while (current) {
            cout << "\t" << current->data.getName() << " (" << current->data.getColor() << ", " << current->data.getAge() << ")\n"; 
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;

    int goats = rand() % (20-5+1) + 5;
    for (int i = 0; i < goats; i++){
        Goat temp;
        list.push_back(temp);
    }

    cout << "Forward:\n";
    list.print();
    cout << "Backward:\n";
    list.print_reverse();

    return 0;
}
