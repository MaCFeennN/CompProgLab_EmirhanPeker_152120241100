
#include <iostream>
#include <string>

using namespace std;


struct Node {
    string data;
    Node* next;
};
struct Song {
    string title;
    string artist;
    int ratings[3];
    song *next;
    Song *prev;
};

    Song* head = nullptr;
    Song* current = nullptr;

void addSong(string title, string artist,int rates[]) {
    Song* newSong    = new Song();
    newSong->title = title;
    newSong->artist = artist;

    for (int i=0; i<3; i++){
        newSong->ratings[i] = rates[i];
    }
    newSong->next = nullptr;

    if (head == nullptr) {
        newSong->prev = nullptr;
        head = newSong;
        current = head;
    } else {
        Song* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->prev = temp;
    }
}


void nextSong() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
        cout << "\n Sonraki sarkiya gecildi: " << current->title << endl;
    } else {
        cout << "\n Listenin sonundasiniz." << endl;
    }
}

void prevSong() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
        cout << "\n Onceki sarkiya gecildi: " << current->title << endl;
    } else {
        cout << "\n Listenin basindasiniz." << endl;
    }
}
void removeCurrent() {
    if (current == nullptr) return;

    Song* toDelete = current;


    if (toDelete->prev != nullptr) {
        toDelete->prev->next = toDelete->next;
    } else {
        head = toDelete->next;
    }

    if (toDelete->next != nullptr) {
        toDelete->next->prev = toDelete->prev;
        current = toDelete->next;
    } else {
        current = toDelete->prev;
    }

    delete toDelete;
    cout << "\n Sarki listeden kaldirildi." << endl;
}


int main() {

    int choice;
    do {
        display();
        cout << "\n1. Sonraki (|>) \n2. Onceki (<|) \n3. Su ankini sil (X) \n0. Cikis \nSeciminiz: ";
        cin >> choice;

        switch (choice) {
            case 1: nextSong(); break;
            case 2: prevSong(); break;
            case 3: removeCurrent(); break;
            case 0: cout << "Cikis yapiliyor...\n"; break;
            default: cout << "Gecersiz secim!\n";
        }
    } while (choice != 0);
    return 0;
}
