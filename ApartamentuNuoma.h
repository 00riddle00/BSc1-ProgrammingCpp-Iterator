#ifndef Apartamentu_Nuoma_h
#define Apartamentu_Nuoma_h

#include <stdio.h>
#include <string>
#include "Nuoma.h"



class ApartamentuNuoma : public Nuoma{
    double price;
public:
    ApartamentuNuoma();
    ApartamentuNuoma(const std::string &address = "NA", const std::string &start = "NA", const std::string &end = "NA", const double &cost = 0, const double &price = 0);
    void setApartCost(const double &val);
    const virtual std::string ShowInformation();
    const virtual std::string InformationForFile();
};

#endif /* Apartamentu_Nuoma_h */
