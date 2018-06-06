#ifndef _Nuoma_H
#define _Nuoma_H

#include <string>
#include "Data.h"
#include "AbsNuoma.h"

std::string addressInput();

std::string datosIvedimas();

double CostInput();

class Nuoma : public AbsNuoma{
	std::string nuomos_adresas, nuomos_pradzia, nuomos_pabaiga;
	DataSpace::Data pradzia, pabaiga;
	double nuomos_kaina;
	static int input_count;
	static int pagalKaRikiuoti;
public:
    virtual ~Nuoma();

    Nuoma(const std::string &address);

    Nuoma(const double &cost);

    Nuoma(const std::string &address = "NA", const std::string &start = "NA", const std::string &end = "NA",
          const double &cost = 0);

    Nuoma(const Nuoma &var);

    std::string getAddress() const;

    std::string getRentStart() const;
    std::string getRentStartRetInfo() const;

    std::string getRentEnd() const;
    std::string getRentEndRetInfo() const;

    double getCost() const;

    static int getInputCount();

    static int getPagalKaRikiuoti();

    void setAddress(const std::string &val);

    void setRentStart(const std::string &val);

    static void setInputCount(const int val);

    static void setPagalKaRikiuoti(int pagalKa);

    void setRentEnd(const std::string &val);

    void setCost(const double &val);

    std::string validateAddress(const std::string &salis);

    std::string validateAddressConst(const std::string &salis);

    std::string validateData(const std::string &data, const std::string &kur);

    std::string validateDataKonst(const std::string &data);

    double validateCost(const double &kaina);

    double validateCostKonst(const double &kaina);

    void
    InformationInput(const std::string &address, const std::string &start, const std::string &end, const double &cost);

    virtual std::string ShowInformation() const;

    virtual std::string InformationForFile() const;

    void changeSomething(const int &change);

    bool sortByAddress(const Nuoma &a, const Nuoma &b);

    bool sortByDate();

    template<class T>
    bool getBigger(T &a, T &b);


    friend void rikiuok();

    friend void rusiuok();

    friend class ApartamentuNuoma;

    friend std::ostream &operator<<(std::ostream &is, const Nuoma &var);

    friend std::istream &operator>>(std::istream &is, Nuoma &var);

    friend bool operator<(const Nuoma &obj1, const Nuoma &obj2);

};


template<class T>
bool Nuoma::getBigger(T &a, T &b) {
    return (a > b);
}


#endif /* _Nuoma_H */


