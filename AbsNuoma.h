#ifndef _AbsNuoma_h
#define _AbsNuoma_h

#include <stdio.h>
#include <string>

class AbsNuoma {
protected:
    std::string nuomos_adresas, nuomos_pradzia, nuomos_pabaiga;
    double nuomos_kaina;
public:
    AbsNuoma(const std::string &adresas = "", const std::string &pradzia = "", const std::string &pabaiga = "", const double &kaina = -1);
    virtual ~AbsNuoma();

    virtual std::string getAddress() const = 0;
    virtual std::string getRentStart() const = 0;
    virtual std::string getRentEnd() const = 0;
    virtual double getCost() const = 0;

    virtual void setAddress(const std::string& val);
    virtual void setRentStart(const std::string& val);
    virtual void setRentEnd(const std::string& val);
    virtual void setCost(const double& val);
};

#endif /* _AbsNuoma_h */
