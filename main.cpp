#include "mylib.h"
#include "timer.h"
#include "Zmogus.h"
#include "Studentas.h"

int main() {

    list<Studentas> studentuSarasas;
    list<Studentas> nuskaitymui;
    list<Studentas> vargsiukai;
    list<Studentas> kietakai;

    int bandymai = 3;
    double trys_nusk = 0;
    double trys_rus = 0;
    double trys_k_isved = 0;
    double trys_p_isved = 0;

    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failu ir atlikti skaiciavimus. Spauskite 2, jei norite ivesti duomenis. Spauskite 3, jei norite nuskaityti faila ir isspausdinti duomenis ekrane. Spauskite 4, jei norite Rule of Three demonstravimo. Spauskite 5, jei norite kurti Zmogaus klases ir Studento klases objektus " << endl;
    cin >> x;

    if (x == 1) {
        int y;
        cout << "Spauskite 1, jei norite sugeneruoti failus, juos nuskaityti ir atlikti veiksmus. Spauskite 2, jei norite nuskaityti jau egzistuojancius failus ir atlikti veiksmus." << endl;
        cin >> y;

        if (y == 1) {

            int rusiavimas;
            cout << "Pagal ka norite rusiuoti studentus? 1 - pagal varda. 2 - pagal pavarde. 3 - pagal galutini bala" << endl;
            cin >> rusiavimas;

            vector<int> stud_sk = {/*1000, 10000,*/ 100000, 1000000/*, 10000000*/};

            for (int x : stud_sk) {

                double trys_nusk = 0.0;
                double trys_rus = 0.0;
                double trys_v_isved = 0.0;
                double trys_k_isved = 0.0;
                double tris_k_rusiuoja = 0.0;

                nuskaitymui.clear();
                vargsiukai.clear();
                kietakai.clear();
                string pvd = to_string(x) + ".txt";

                Timer a;
                Studentas::generavimas(x);
                double gen_laikas = a.elapsed();
                cout << "Generavimas uztruko " << gen_laikas << " sekundziu" << endl;

                for (int i = 1; i <= bandymai; i++) {
                    nuskaitymui.clear();
                    vargsiukai.clear();
                    kietakai.clear();

                    Timer b;
                    Studentas::nuskaityk2(nuskaitymui, pvd);
                    double nusk_laikas = b.elapsed();
                    trys_nusk += nusk_laikas;

                    Timer h;
                    Studentas::rusiuotiStudentus(nuskaitymui, rusiavimas);
                    double rusiavimo_laikas = h.elapsed();
                    tris_k_rusiuoja += rusiavimo_laikas;

                    Timer c;
                    Studentas::sort_galutinio(nuskaitymui, vargsiukai);
                    double rus_laikas = c.elapsed();
                    trys_rus += rus_laikas;

                    string vargsu = "vargsiukai" + pvd;
                    string kietuku = "kietakai" + pvd;

                    Timer d;
                    Studentas::irasymas_i_faila(vargsiukai, vargsu);
                    double isved_laikas1 = d.elapsed();
                    trys_v_isved += isved_laikas1;

                    Timer e;
                    Studentas::irasymas_i_faila(nuskaitymui, kietuku);
                    double isved_laikas2 = e.elapsed();
                    trys_k_isved += isved_laikas2;
                }

                double vidurkis1 = trys_nusk / bandymai;
                cout << "Vidutinis nuskaitymo laikas: " << vidurkis1 << endl;

                double vidurkis99 = tris_k_rusiuoja / bandymai;
                cout << "Vidutinis rusiavimo laikas: " << vidurkis99 << endl;

                double vidurkis2 = trys_rus / bandymai;
                cout << "Vidutinis isskirstymo laikas: " << vidurkis2 << endl;

                double vidurkis3 = trys_k_isved / bandymai;
                cout << "Vidutinis vargsiuku isvedimo i faila laikas: " << vidurkis3 << endl;

                double vidurkis4 = trys_p_isved / bandymai;
                cout << "Vidutinis kietaku isvedimo i faila laikas: " << vidurkis4 << endl;
                cout << "\n";
            }

        } else if (y == 2) {

            string pvd;
            vector<string> pavadinimai;

            while (pvd != "0") {
                cout << "Iveskite failo pavadinima (su .txt). Spauskite 0, jei nebenorite ivesti daugiau failu" << endl;
                cin >> pvd;
                if (pvd != "0") {
                    pavadinimai.push_back(pvd);
                }
            }

            int rusiavimas2;
            cout << "Pagal ka norite rusiuoti studentus? 1 - pagal varda. 2 - pagal pavarde. 3 - pagal galutini bala" << endl;
            cin >> rusiavimas2;

            for (string z : pavadinimai) {

                double trys_nusk = 0.0;
                double trys_rus = 0.0;
                double trys_v_isved = 0.0;
                double trys_k_isved = 0.0;
                double tris_k_rusiuoja = 0.0;

                cout << z << endl;

                for (int i = 1; i <= bandymai; i++) {
                    nuskaitymui.clear();
                    vargsiukai.clear();
                    kietakai.clear();

                    Timer b;
                    Studentas::nuskaityk2(nuskaitymui, z);
                    double nusk_laikas = b.elapsed();
                    trys_nusk += nusk_laikas;

                    Timer h;
                    Studentas::rusiuotiStudentus(nuskaitymui, rusiavimas2);
                    double rusiavimo_laikas = h.elapsed();
                    tris_k_rusiuoja += rusiavimo_laikas;

                    Timer c;
                    Studentas::sort_galutinio(nuskaitymui, vargsiukai);
                    double rus_laikas = c.elapsed();
                    trys_rus += rus_laikas;

                    string vargsu = "vargsiukai_is_" + z;
                    string kietuku = "kietakai_is_" + z;

                    Timer d;
                    Studentas::irasymas_i_faila(vargsiukai, vargsu);
                    double isved_laikas1 = d.elapsed();
                    trys_v_isved += isved_laikas1;

                    Timer e;
                    Studentas::irasymas_i_faila(nuskaitymui, kietuku);
                    double isved_laikas2 = e.elapsed();
                    trys_k_isved += isved_laikas2;
                }

                double vidurkis1 = trys_nusk / bandymai;
                cout << "Vidutinis nuskaitymo laikas: " << vidurkis1 << endl;

                double vidurkis990 = tris_k_rusiuoja / bandymai;
                cout << "Vidutinis rusiavimo laikas: " << vidurkis990 << endl;

                double vidurkis2 = trys_rus / bandymai;
                cout << "Vidutinis isskirstymo laikas: " << vidurkis2 << endl;

                double vidurkis3 = trys_k_isved / bandymai;
                cout << "Vidutinis vargsiuku isvedimo i faila laikas: " << vidurkis3 << endl;

                double vidurkis4 = trys_p_isved / bandymai;
                cout << "Vidutinis kietaku isvedimo i faila laikas: " << vidurkis4 << endl;
                cout << "\n";
            }

        }

    } else if (x == 2) {

        while (true) {
        Studentas studentai2;
        cin >> studentai2;

        if (studentai2.getVardas() == "0") {
            break;
        }

        studentuSarasas.push_back(studentai2);
    }

        Studentas studentas123;
        int pasirink;
        cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
        cin >> pasirink;

        Studentas::setPasirink(pasirink);

        studentas123.spausdintiLentele(studentuSarasas, pasirink);

    } else if (x == 3) {

        cout << "Iveskite failo pavadinima: ";
        string failo_pvd;
        cin >> failo_pvd;

        Studentas::nuskaityk2(studentuSarasas, failo_pvd);

        int pasirink;
        cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
        cin >> pasirink;
        Studentas::setPasirink(pasirink);

        Studentas studentas321;
        studentas321.spausdintiLentele(studentuSarasas, pasirink);

    } else if (x==4){

        string failo_pvd;
        cout << "Iveskite failo pavadinima: ";
        cin >> failo_pvd;

        Studentas::nuskaityk2(studentuSarasas, failo_pvd);
        list<Studentas> nukopijuotas1(studentuSarasas);

        list<Studentas> nukopijuotas2;
        nukopijuotas2 = studentuSarasas;

        cout << "Originalus:\n";
        for (const auto& student : studentuSarasas) {
            cout << student.getVardas() << " " << student.getPavarde() << endl;
        }

        cout << "\nNukopijuotas 1:\n";
        for (const auto& student : nukopijuotas1) {
            cout << student.getVardas() << " " << student.getPavarde() << endl;
        }

        cout << "\nNukopijuotas 2:\n";
        for (const auto& student : nukopijuotas2) {
            cout << student.getVardas() << " " << student.getPavarde() << endl;
        }


    } else if (x==5){

        cout << "Klasiu demonstravimas:" << endl;

        /*Zmogus humanObject;*/



    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }

    return 0;
}


