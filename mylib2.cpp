/*#include "mylib.h"

void generavimas(int stud_sk) {
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
        cerr << "Nepavyko nustatyti failo dydžio!" << endl;
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

void nuskaityk2(list<Studentas>& vekt, string failopvd) {
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
        stud >> temp.setVardas >> temp.setPavarde;
        for (int i = 1; i < num; i++) {
            int pazymys;
            if (stud >> pazymys) {
                temp.getPazymiai().push_back(pazymys);
            }
        }
        stud >> temp.setEgzaminas;

        double galutinis1 = 0.4 * vidurkis(temp.getPazymiai()) + 0.6 * temp.getEgzaminas();
        temp.setRezVid(galutinis1);
        vekt.push_back(temp);
    }
}

void sort_galutinio(list<Studentas>& studentai, list<Studentas>& vargsiukai) {
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

void irasymas_i_faila(const list<Studentas>& studentai, const string& failo_pvd) {
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

bool palyginimas(const Studentas& a, const Studentas& b, int rusiavimas) {
    if (rusiavimas == 1) {
        return a.getVardas() < b.getVardas();
    } else if (rusiavimas == 2) {
        return a.getPavarde() < b.getPavarde();
    } else if (rusiavimas == 3) {
        return a.getRezVid() < b.getRezVid();
    }

    return false;
}

void rusiuotiStudentus(list<Studentas>& studentai, int rusiavimas) {
    studentai.sort([rusiavimas](const Studentas& a, const Studentas& b) {
        return palyginimas(a, b, rusiavimas);
    });
}*/
