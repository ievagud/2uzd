// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dll.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


int Studentas::pasirink = 1;


std::istream& operator>>(std::istream& is, Studentas& student) {
    cout << "Iveskite varda (arba 0, jei norite baigti ivedima): ";
    is >> student.vardas;

    if (student.vardas == "0") {
        return is;
    }

    cout << "Iveskite pavarde: ";
    is >> student.pavarde;

    double pazymys;
    cout << "Ar norite sugeneruoti atsitiktinius pazymius? (1 - Taip, 0 - Ne): ";
    double rand_pazymiai;
    is >> rand_pazymiai;

    if (rand_pazymiai == 1) {
        srand(time(0));
        int rand_pazymiu_sk = rand() % 11;
        cout << "Sugeneruoti atsitiktiniai pazymiai: ";
        for (int i = 0; i < rand_pazymiu_sk; ++i) {
            int rand_pazymys = rand() % 11;
            student.pazymiai.push_back(rand_pazymys);
            cout << rand_pazymys << " ";
        }
        cout << endl;

        srand(time(0));
        student.egzaminas = rand() % 11;
        cout << "Sugeneruotas egzamino pazymys: " << student.egzaminas << endl;
        cout << "\n";
    }
    else {
        double pazymys;

        while (true) {
            try {
                cout << "Iveskite pazymi (nuo 0 iki 10, iveskite -1, jei norite baigti ivedima ): ";
                if (is >> pazymys) {
                    if (pazymys == -1) {
                        break;
                    }

                    if (pazymys >= 0 && pazymys <= 10) {
                        student.pazymiai.push_back(pazymys);
                    }
                    else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                }
                else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
                is.clear();
                while (is.get() != '\n' && is) {}
            }
        }

        double egz;

        while (true) {
            try {
                cout << "Iveskite egzamino pazymi (0-10): ";

                if (is >> egz) {
                    if (egz >= 0 && egz <= 10) {
                        student.egzaminas = egz;
                        break;
                    }
                    else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                }
                else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
                is.clear();
                while (is.get() != '\n' && is) {}
            }
        }
    }

    student.rez_vid = 0.4 * Studentas::vidurkis(student.pazymiai) + 0.6 * student.egzaminas;
    student.rez_med = 0.4 * Studentas::mediana(student.pazymiai) + 0.6 * student.getEgzaminas();

    return is;
}



void Studentas::spausdintiLentele(const list<Studentas>& studentuSarasas, int pasirink) const {
    cout << "\n";
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";

    if (pasirink == 1) {
        cout << setw(20) << "Galutinis (Vid.)";
    }
    else if (pasirink == 2) {
        cout << setw(20) << "Galutinis (Med.)";
    }
    else {
        cout << setw(20) << "Galutinis";
    }

    cout << setw(20) << "Adresas" << "\n";
    cout << string(80, '-') << endl;

    for (const Studentas& student : studentuSarasas) {
        cout << student;
        cout << "\n";
    }

    cout << string(80, '-') << endl;
}
/*
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
        }
        else {
            return a.pavarde < b.pavarde;
        }
        });

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << setw(20) << "Galutinis (Vid.)" << "\n";
    cout << string(70, '-') << endl;
    for (const Studentas& student : studentai) {
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde << setw(20) << fixed << setprecision(2) << student.rez_med << setw(20) << fixed << setprecision(2) << student.rez_vid << "\n";
    }
    cout << string(70, '-') << endl;

}*/

void Studentas::generavimas(int stud_sk) {
    string failopavadinimas;

    if (stud_sk == 1000) {
        failopavadinimas = "1000.txt";
    }
    else if (stud_sk == 10000) {
        failopavadinimas = "10000.txt";
    }
    else if (stud_sk == 100000) {
        failopavadinimas = "100000.txt";
    }
    else if (stud_sk == 1000000) {
        failopavadinimas = "1000000.txt";
    }
    else if (stud_sk == 10000000) {
        failopavadinimas = "10000000.txt";
    }
    else {
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
        }
        else {
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
    }
    else if (rusiavimas == 2) {
        return a.getPavarde() < b.getPavarde();
    }
    else if (rusiavimas == 3) {
        return a.getRezVid() < b.getRezVid();
    }

    return false;

}

void Studentas::rusiuotiStudentus(list<Studentas>& studentai, int rusiavimas) {
    studentai.sort([rusiavimas](const Studentas& a, const Studentas& b) {
        return palyginimas(a, b, rusiavimas);
        });

}

std::ostream& operator<<(std::ostream& os, const Studentas& student) {
    os << left << setw(15) << student.getVardas()
        << left << setw(25) << student.getPavarde();

    if (Studentas::pasirink == 1) {
        os << setw(15) << fixed << setprecision(2) << student.getRezVid();
    }
    else {
        os << setw(15) << fixed << setprecision(2) << student.getRezMed();
    }

    os << left << setw(20) << &student;

    return os;
}





