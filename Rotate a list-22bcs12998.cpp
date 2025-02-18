#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;  
    }

    void rotate(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        Node* temp = head;
        int length = 1; 
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        k = k % length;
        if (k == 0) {
            return; 
        }

        temp->next = head;

        for (int i = 0; i < length - k - 1; i++) {
            head = head->next;
        }

        Node* newHead = head->next;
        head->next = nullptr;
        head = newHead;
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Original List: ";
    list.display();

    list.rotate(2);

    cout << "After Rotating by 2 positions: ";
    list.display();

    return 0;
}
