#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Sensor {
    int sensor_id;
    float sicaklik;
};

int main() {
    long long student_id;

    cout << " (Student ID) : ";
    cin >> student_id;

    int N = student_id % 50;
    int E = student_id % 100;





    fstream bin_file("sensors.bin", ios::in | ios::out | ios::binary);

    if (!bin_file.is_open()) {
        cerr << "Hata: 'sensors.bin' dosyasi acilamadi! Dosyanin ayni dizinde oldugundan emin olun." << endl;
        return 1;
    }

    Sensor tempSensor;


    bin_file.seekg(N * sizeof(Sensor), ios::beg);


    bin_file.read(reinterpret_cast<char*>(&tempSensor), sizeof(Sensor));


    float ilk_sicaklik = tempSensor.sicaklik;





    tempSensor.sicaklik += E;



    bin_file.seekp(N * sizeof(Sensor), ios::beg);


    bin_file.write(reinterpret_cast<char*>(&tempSensor), sizeof(Sensor));


    bin_file.close();





    string txt_filename = to_string(student_id) + "_Quiz5.txt";


    ofstream txt_file(txt_filename, ios::out);

    if (!txt_file.is_open()) {
        cerr << "Hata: Rapor dosyasi olusturulamadi!" << endl;
        return 1;
    }


    txt_file << "Number: [" << student_id << "]\n";
    txt_file << "Sensor Index Used in the Process: [" << N << "]\n";
    txt_file << "First Temperature: [" << ilk_sicaklik << "] -> New Temperature: [" << tempSensor.sicaklik << "]\n";

    txt_file.close();

    cout << "Islem basariyla tamamlandi. Rapor dosyasi olusturuldu: " << txt_filename << endl;

    return 0;
}
