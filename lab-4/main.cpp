#include <iostream>
#include <string>

using namespace std;


struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};


struct Courier {
    string courierName;
    string vehicleType;
};



Package* top = nullptr;

const int MAX_SIZE = 5;
Courier courierQueue[MAX_SIZE];
int front = -1;
int rear = -1;




void arrival(string id, string city, int l, int w, int h) {
    Package* newPackage = new Package();
    newPackage->packageID = id;
    newPackage->destinationCity = city;
    newPackage->dimensions[0] = l;
    newPackage->dimensions[1] = w;
    newPackage->dimensions[2] = h;


    newPackage->next = top;
    top = newPackage;

    cout << "[OK] Paket " << id << " yigina eklendi." << endl;
}


void courierRegister(string name, string vehicle) {

    if ((rear + 1) % MAX_SIZE == front) {
        cout << " Kuyruk dolu " << name << " eklenemedi." << endl;
        return;
    }

    if (front == -1) front = 0;

    rear = (rear + 1) % MAX_SIZE;
    courierQueue[rear].courierName = name;
    courierQueue[rear].vehicleType = vehicle;

    cout << "[OK] Kurye " << name << " kuyruga eklendi." << endl;
}


void dispatch() {
    if (top == nullptr) {
        cout << " Gonderilecek paket yok" << endl;
        return;
    }
    if (front == -1) {
        cout << "Bekleyen kurye yok" << endl;
        return;
    }


    Package* pToDispatch = top;
    top = top->next;


    Courier cToDispatch = courierQueue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    cout << "\n SEVKIYAT BASLADI " << endl;
    cout << "Kurye: " << cToDispatch.courierName << " (" << cToDispatch.vehicleType << ")" << endl;
    cout << "Paket: " << pToDispatch->packageID << " Hedef: " << pToDispatch->destinationCity << endl;


    delete pToDispatch;
}


void display() {
    cout << "\n Mevcut Durum :" << endl;


    cout << "Yigin (Paketler): ";
    if (top == nullptr) cout << "[Bos]";
    Package* temp = top;
    while (temp != nullptr) {
        cout << "|" << temp->packageID << "| ";
        temp = temp->next;
    }


    cout << "\nKuyruk (Kuryeler): ";
    if (front == -1) {
        cout << "[Bos]";
    } else {
        int i = front;
        while (true) {
            cout << "(" << courierQueue[i].courierName << ") ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
    }
    cout << "\n--------------------\n" << endl;
}


int main() {

    arrival("Paket-1","Tepebaþý Balkan Caddesi",30,20,10);






    arrival("PKT-1", "Eskiþehir", 30, 20, 10);
    arrival("PKT-1", "Samsun", 15, 15, 15);
    arrival("PKT-1", "Adana", 40, 30, 20);


    courierRegister("Emirhan", "Motor");
    courierRegister("EmirhanP", "motor");
    courierRegister("EmirhanPE", "Motor");



    display();


    dispatch();
    dispatch();
    display();

    return 0;
}
