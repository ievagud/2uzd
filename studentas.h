#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "Zmogus.h"

class Studentas : public Zmogus {
private:
    vector<double> pazymiai;
    double egzaminas;
    double rez_vid;
    double rez_med;
    static int pasirink;

public:
    Studentas() : Zmogus(), pazymiai(), egzaminas(0), rez_vid(0), rez_med(0) {}

    Studentas(const string& newVardas, const string& newPavarde, const vector<double>& newPazymiai,
            double newEgzaminas, double newRez_vid, double newRez_med)
        : Zmogus(newVardas, newPavarde), pazymiai(newPazymiai), egzaminas(newEgzaminas),
          rez_vid(newRez_vid), rez_med(newRez_med) {}

    ~Studentas() {}

    Studentas(const Studentas& other) : Zmogus(other), pazymiai(other.pazymiai),
                                    egzaminas(other.egzaminas), rez_vid(other.rez_vid), rez_med(other.rez_med) {}

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            pazymiai = other.pazymiai;
            egzaminas = other.egzaminas;
            rez_vid = other.rez_vid;
            rez_med = other.rez_med;
        }
        return *this;
    }


    string getVardas() const {
        return vardas;
    }

    void setVardas(const string& newVardas) {
        vardas = newVardas;
    }

    string getPavarde() const {
        return pavarde;
    }

    void setPavarde(const string& newPavarde) {
        pavarde = newPavarde;
    }

    void addPazymys(int pazymys) {
        pazymiai.push_back(pazymys);
    }

    vector<double> getPazymiai() const {
        return pazymiai;
    }

    void setPazymiai(const vector<double>& newPazymiai);

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

    double getRezMed() const{
        return rez_vid;
    }

    void setRezMed(double rezMed){
     rez_med = rezMed;
    }

    static void setPasirink(int newPasirink) {
        pasirink = newPasirink;
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

     void kalba() const override {
        std::cout << vardas << " " << pavarde << " sako labas!" << std::endl;
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

    friend std::istream& operator>>(std::istream& is, Studentas& student);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& student);



};


#endif // STUDENTAS_H_INCLUDED
