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

#endif // MYLIB_H_INCLUDED
