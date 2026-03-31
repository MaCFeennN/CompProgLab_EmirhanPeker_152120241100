#include <iostream>
#include <string>

using namespace std;


struct Node {
    string data;
    Node* next;
};


void addWord(Node*& head, string word) {
    Node* newNode = new Node();
    newNode->data = word;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void undo(Node*& head) {
    if (head == nullptr) {
        cout << "Liste zaten bos, geri alinacak bir sey yok!" << endl;
        return;
    }


    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }
}

void display(Node* head) {
    Node* temp = head;
    cout << "\nMetin: ";
    while (temp != nullptr) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
    Node* editor = nullptr;
    string input;

    cout << "(Cikmak icin 'EXIT', son kelimeyi silmek icin 'UNDO' yazin)" << endl;

    while (true) {
        cout << "\nKelime girin: ";
        cin >> input;

        if (input == "EXIT") {
            break;
        } else if (input == "UNDO") {
            undo(editor);
        } else {
            addWord(editor, input);
        }

        display(editor);
    }

    cout << "Programdan cikiliyor..." << endl;
    return 0;
}
