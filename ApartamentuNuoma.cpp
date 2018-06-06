#include "ApartamentuNuoma.h"
#include <string>
#include <sstream>

ApartamentuNuoma::ApartamentuNuoma() : Nuoma(){
    price = 0;
}

ApartamentuNuoma::ApartamentuNuoma(const std::string &address, const std::string &start, const std::string &end, const double &cost, const double &price) : Nuoma(address + " APARTAMENTAI", start, end, cost){
    setApartCost(price);
}

void ApartamentuNuoma::setApartCost(const double &val){
    price = val;
    this->setCost(getCost()+price);
}

const std::string ApartamentuNuoma::ShowInformation() {
    double kaina = getCost();
    std::string infoAll = "Adresas: " + getAddress() + ", Pradzia: " + pradzia.retInfo() + ", Pabaiga: " + pabaiga.retInfo() + ", Visos nuomos + apartamentu kaina: " + std::to_string(kaina);
    return infoAll;
};

const std::string ApartamentuNuoma::InformationForFile() {
    std::string infoAll = this->getAddress() + " " + this->getRentStart() + " " + this->getRentEnd() + " " + std::to_string(this->getCost());
    return infoAll;
};
