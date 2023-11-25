#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>

#include <fstream>
#include <ctime>
#include <cstdlib>

#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::sort;
using std::ifstream;
using std::stringstream;
using std::istringstream;
using std::cerr;
using std::invalid_argument;
using std::out_of_range;

using std::ofstream;
using std::to_string;
using std::default_random_engine;
using std::uniform_int_distribution;

using std::list;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<double> pazymiai;
    double pazymiai2[10];
    double egzaminas;
    double rez_vid;
    double rez_med;

public:

    Studentas() : egzaminas(0), rez_vid(0), rez_med(0){}

    string getVardas() const {
        return vardas;
    }
    void setVardas(const string& newVardas) {
        vardas = newVardas;
    }


    string getPavarde() const{
        return vardas;
    }
    void setPavarde(const string& newPavarde){
        pavarde = newPavarde;

    }


    void addPazymys(int pazymys) {
        pazymiai.push_back(pazymys);
    }

    vector<double>& getPazymiai() {
        return pazymiai;
    }
    void setPazymiai(const vector<double>& newPazymiai);


    const double* getPazymiai2() const;
    void setPazymiai2(const double newPazymiai2[10]);

    double getEgzaminas() const {
        return egzaminas;
    }


    void setEgzaminas(double newEgzaminas);

    double getRezVid() const{
        return rez_vid;
    }
    void setRezVid(double rezVid){
     rez_vid = rezVid;
    }

    double getRezMed() const;
    void setRezMed(double rezMed){
     rez_med = rezMed;
    }



    static double mediana(const vector<double>& pazymiai) {
        if (pazymiai.empty()) {
            return 0;
        }

        vector<double> rusiavimui = pazymiai;
        sort(rusiavimui.begin(), rusiavimui.end());

        int n = rusiavimui.size();
        if (n % 2 == 0) {
            int vid = n / 2;
            return (rusiavimui[vid - 1] + rusiavimui[vid]) / 2.0;
        } else {
            return rusiavimui[n / 2];
        }
    }

    static double vidurkis(const vector<double>& pazymiai) {
        double paz_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
        return pazymiai.size() > 0 ? paz_suma / pazymiai.size() : 0;
    }

    static Studentas ivesk();
    void spausdintiLentele(const list<Studentas>& studentuSarasas, int pasirink) const;
    static Studentas nuskaityk();
    static void generavimas(int stud_sk);
    static void nuskaityk2(list<Studentas>& vekt, string failopvd);
    static void sort_galutinio(list<Studentas>& studentai, list<Studentas>& vargsiukai);
    static void irasymas_i_faila(const list<Studentas>& studentai, const string& failo_pvd);
    static bool palyginimas(const Studentas& a, const Studentas& b, int rusiavimas);
    static void rusiuotiStudentus(list<Studentas>& studentai, int rusiavimas);
};

Studentas Studentas::ivesk() {
    Studentas temp;

    cout << "Iveskite varda (arba 0, jei norite baigti ivedima): ";
    string inputVardas;
    cin >> inputVardas;

    temp.setVardas(inputVardas);

    if (temp.getVardas() == "0") {
        return temp;
    }

    cout << "Iveskite pavarde: ";
    string inputPavarde;
    cin >> inputPavarde;
    temp.setPavarde(inputPavarde);

    double pazymys;
    cout << "Ar norite sugeneruoti atsitiktinius pazymius? (1 - Taip, 0 - Ne): ";
    double rand_pazymiai;
    cin >> rand_pazymiai;

    if (rand_pazymiai == 1) {
        srand(time(0));
        int rand_pazymiu_sk = rand() % 11;
        cout << "Sugeneruoti atsitiktiniai pazymiai: ";
        for (int i = 0; i < rand_pazymiu_sk; ++i) {
            int rand_pazymys = rand() % 11;
            temp.getPazymiai().push_back(rand_pazymys);
            cout << rand_pazymys << " ";
        }
        cout << endl;

        srand(time(0));
        temp.egzaminas = rand() % 11;
        cout << "Sugeneruotas egzamino pazymys: " << temp.egzaminas << endl;
        cout << "\n";

    } else {
        double pazymys;

        while (true) {
            try {
                cout << "Iveskite pazymi (nuo 0 iki 10, iveskite -1, jei norite baigti ivedima ): ";
                if (cin >> pazymys) {
                    if (pazymys == -1) {
                        break;
                    }

                    if (pazymys >= 0 && pazymys <= 10) {
                        temp.pazymiai.push_back(pazymys);
                    } else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                } else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        double egz;

        while (true) {
            try {
                cout << "Iveskite egzamino pazymi (0-10): ";

                if (cin >> egz) {
                    if (egz >= 0 && egz <= 10) {
                        temp.egzaminas = egz;
                        break;
                    } else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                } else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    temp.rez_vid = 0.4 * vidurkis(temp.pazymiai) + 0.6 * temp.egzaminas;
    temp.rez_med = 0.4 * mediana(temp.pazymiai) + 0.6 * temp.getEgzaminas();

    return temp;
}

void Studentas::spausdintiLentele(const list<Studentas>& studentuSarasas, int pasirink) const {

if (pasirink == 1) {
        cout << "\n";
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Adresas" << "\n";
        cout << string(80, '-') << endl;
        for (const Studentas& student : studentuSarasas) {
            cout << left << setw(15) << student.vardas << setw(20) << student.pavarde << setw(15) << fixed << setprecision(2) << student.rez_vid << setw(20) << &student << "\n";
        }
    } else if (pasirink == 2) {
        cout << "\n";
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << setw(20) << "Adresas" << "\n";
        cout << string(80, '-') << endl;
        for (const Studentas& student : studentuSarasas) {
            cout << left << setw(15) << student.vardas << setw(20) << student.pavarde << setw(15) << fixed << setprecision(2) << student.rez_med << setw(20) << &student << "\n";
        }
    } else {
        cout << "Netinkamas pasirinkimas, rodomas galutinis su vidurkiu: " << "\n";
        cout << "\n";
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis" << setw(20) << "Adresas" << "\n";
        cout << string(50, '-') << endl;
        for (const Studentas& student : studentuSarasas) {
            cout << left << setw(15) << student.vardas << setw(20) << student.pavarde << setw(5) << fixed << setprecision(2) << student.rez_vid << setw(20) << &student << "\n";
        }
    }

    cout << string(80, '-') << endl;

}

Studentas Studentas::nuskaityk() {

string failo_pvd;
    cout << "Iveskite failo pavadinima: ";
    cin >> failo_pvd;

    vector<Studentas> studentai;
    ifstream failas(failo_pvd);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
    }

    string eil;
    getline(failas, eil);

    stringstream eil_stream(eil);
    string sk;
    int stulp = 0;
    while (eil_stream >> sk) {
        stulp++;
    }

    stulp = stulp - 3;
    while (getline(failas, eil)) {
        Studentas studentas;
        stringstream x(eil);
        x >> studentas.vardas >> studentas.pavarde;

        for (int i = 1; i <= stulp; i++) {
            int pazymys;
            if (x >> pazymys) {
                studentas.addPazymys(pazymys);
            }
        }
        x >> studentas.egzaminas;


        double galutinis = 0.4 * studentas.mediana(studentas.getPazymiai()) + 0.6 * studentas.getEgzaminas();
        studentas.setRezMed(galutinis);

        double galutinis1 = 0.4 * Studentas::vidurkis(studentas.getPazymiai()) + 0.6 * studentas.getEgzaminas();
        studentas.setRezVid(galutinis1);

        studentai.push_back(studentas);
    }

    failas.close();

    sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        if (a.vardas != b.vardas) {
            return a.vardas < b.vardas;
        } else {
            return a.pavarde < b.pavarde;
        }
    });

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << setw(20) << "Galutinis (Vid.)" << "\n";
    cout << string(70, '-') << endl;
    for (const Studentas& student : studentai) {
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde << setw(20) << fixed << setprecision(2) << student.rez_med << setw(20) << fixed << setprecision(2) << student.rez_vid << "\n";
    }
    cout << string(70, '-') << endl;

}

void Studentas::generavimas(int stud_sk) {

string failopavadinimas;

    if (stud_sk == 1000) {
        failopavadinimas = "1000.txt";
    } else if (stud_sk == 10000) {
        failopavadinimas = "10000.txt";
    } else if (stud_sk == 100000) {
        failopavadinimas = "100000.txt";
    } else if (stud_sk == 1000000) {
        failopavadinimas = "1000000.txt";
    } else if (stud_sk == 10000000) {
        failopavadinimas = "10000000.txt";
    } else {
        cerr << "Nepavyko nustatyti failo dydio!" << endl;
        return;
    }

    ofstream outputas(failopavadinimas);
    if (!outputas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return;
    }

    default_random_engine generator(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> distribution(0, 10);

    outputas << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int j = 1; j <= 10; ++j) {
        string nd = "ND" + to_string(j);
        outputas << left << setw(10) << nd;
    }
    outputas << left << setw(10) << "EGZ" << endl;

    for (int i = 1; i <= stud_sk; ++i) {
        string vardas = "Vardas" + to_string(i);
        string pavarde = "Pavarde" + to_string(i);

        outputas << left << setw(15) << vardas << setw(15) << pavarde;

        for (int j = 0; j < 10; ++j) {
            outputas << setw(10) << distribution(generator);
        }

        outputas << setw(10) << distribution(generator) << endl;
    }

    outputas.close();

    cout << "Sugeneruota " << stud_sk << " studentu duomenys. Duomenys issaugoti faile " << failopavadinimas << endl;

}

void Studentas::nuskaityk2(list<Studentas>& vekt, string failopvd) {

ifstream failas(failopvd);
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return;
    }

    string eil;
    getline(failas, eil);

    stringstream x(eil);

    string el;

    int num = 0;
    while (x >> el) {
        num++;
    }
    num = num - 3;

    while (getline(failas, eil)) {
        Studentas temp;
        stringstream stud(eil);
        stud >> temp.vardas >> temp.pavarde;
        for (int i = 1; i < num; i++) {
            int pazymys;
            if (stud >> pazymys) {
                temp.getPazymiai().push_back(pazymys);
            }
        }
        stud >> temp.egzaminas;

        double galutinis1 = 0.4 * vidurkis(temp.getPazymiai()) + 0.6 * temp.getEgzaminas();
        temp.setRezVid(galutinis1);
        vekt.push_back(temp);
    }
}


void Studentas::sort_galutinio(list<Studentas>& studentai, list<Studentas>& vargsiukai) {

auto it = studentai.begin();
    while (it != studentai.end()) {
        if (it->getRezVid() < 5) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }

}

void Studentas::irasymas_i_faila(const list<Studentas>& studentai, const string& failo_pvd) {

ofstream outputas(failo_pvd);

    if (!outputas.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failo_pvd << endl;
        return;
    }

    outputas << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis" << "\n";
    outputas << string(40, '-') << endl;

    for (const Studentas& stud : studentai) {
        outputas << left << setw(15) << stud.getVardas() << setw(15) << stud.getPavarde() << setw(20) << fixed << setprecision(2) << stud.getRezVid() << "\n";
    }

    outputas.close();

}

bool Studentas::palyginimas(const Studentas& a, const Studentas& b, int rusiavimas) {

if (rusiavimas == 1) {
        return a.getVardas() < b.getVardas();
    } else if (rusiavimas == 2) {
        return a.getPavarde() < b.getPavarde();
    } else if (rusiavimas == 3) {
        return a.getRezVid() < b.getRezVid();
    }

    return false;

}

void Studentas::rusiuotiStudentus(list<Studentas>& studentai, int rusiavimas) {

studentai.sort([rusiavimas](const Studentas& a, const Studentas& b) {
        return palyginimas(a, b, rusiavimas);
    });

}











/*void spausdintiLentele(const list<Studentas>& studentuSarasas, int pasirink);
Studentas nuskaityk();
double mediana(const vector<double>& sk);
double vidurkis(const vector<double>& pazymiai);
void generavimas(int stud_sk);
void nuskaityk2(list<Studentas>& vekt, string failopvd);
void sort_galutinio(list<Studentas>& studentai, list<Studentas>& vargsiukai);
void irasymas_i_faila(const list<Studentas>& studentai, const string& failo_pvd);
void rusiuotiStudentus(list<Studentas>& studentai, int rusiavimas);*/

#endif // MYLIB_H_INCLUDED
