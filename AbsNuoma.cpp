
#include "AbsNuoma.h"


AbsNuoma::AbsNuoma(const std::string &adresas, const std::string &pradzia, const std::string &pabaiga, const double &kaina) {
    nuomos_adresas = adresas;
    nuomos_pradzia = pradzia;
    nuomos_pabaiga = pabaiga;
    nuomos_kaina = kaina;
}

std::string AbsNuoma::getAddress() const {
    return nuomos_adresas;
}

std::string AbsNuoma::getRentStart() const {
    return nuomos_pradzia;
}

std::string AbsNuoma::getRentEnd() const {
    return nuomos_pabaiga;
}

double AbsNuoma::getCost() const {
    return nuomos_kaina;
}

void AbsNuoma::setAddress(const std::string &val) {
    nuomos_adresas = val;
}

void AbsNuoma::setRentStart(const std::string &val) {
    nuomos_pradzia = val;
}

void AbsNuoma::setRentEnd(const std::string &val) {
    nuomos_pabaiga = val;
}

void AbsNuoma::setCost(const double &val) {
    nuomos_kaina = val;
}

AbsNuoma::~AbsNuoma() {}