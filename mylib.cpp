/*#include "mylib.h"

double mediana(const vector<double>& pazymiai) {
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

double vidurkis(const vector<double>& pazymiai) {
    double paz_suma = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
    return pazymiai.size() > 0 ? paz_suma / pazymiai.size() : 0;
}

Studentas ivesk() {
    Studentas temp;

    cout << "Iveskite varda (arba 0, jei norite baigti ivedima): ";
    string inputVardas;
    cin >> inputVardas;
    temp.setVardas(inputVardas);

    if (temp.getVardas == "0") {
        return temp;
    }

    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;

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
            temp.pazymiai.push_back(rand_pazymys);
            cout << rand_pazymys << " ";
        }

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
    temp.rez_med = 0.4 * mediana(temp.pazymiai) + 0.6 * temp.egzaminas;

    return temp;
}

void spausdintiLentele(const list<Studentas>& studentuSarasas, int pasirink) {
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

Studentas nuskaityk() {
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
                studentas.pazymiai.push_back(pazymys);
            }
        }
        x >> studentas.egzaminas;

        double galutinis = 0.4 * mediana(studentas.pazymiai) + 0.6 * studentas.egzaminas;
        studentas.rez_med = galutinis;
        double galutinis1 = 0.4 * vidurkis(studentas.pazymiai) + 0.6 * studentas.egzaminas;
        studentas.rez_vid = galutinis1;
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
*/
