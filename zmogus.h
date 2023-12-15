#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED

class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() : vardas(""), pavarde("") {}

    Zmogus(const string& newVardas, const string& newPavarde):
        vardas(newVardas), pavarde(newPavarde) {}

    virtual ~Zmogus() {}

    virtual void kalba() const = 0;
};


#endif // ZMOGUS_H_INCLUDED
