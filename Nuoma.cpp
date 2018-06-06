#include <string>
#include <iostream>
#include "Nuoma.h"
#include <sstream>
#include <iomanip>


bool datosValidacijaTemp(const std::string& data) {
	size_t datosIlgis = data.length();
    std::string metai, menuo, diena;
    int metaiInt, menuoInt, dienaInt;
	if (datosIlgis < 10) return false;
    try{
        metai.append(data, 0, 4);
        menuo.append(data, 5, 2);
        diena.append(data, 8, 2);
        metaiInt = stoi(metai, 0);
        menuoInt = stoi(menuo, 0);
        dienaInt = stoi(diena, 0);
    }
    catch(std::invalid_argument& ex){
        return false;
    }
    std::time_t t = time(NULL);
    tm* timeptr = localtime(&t);
    if(metaiInt > timeptr->tm_year + 1900){
        if(menuoInt > 0 && menuoInt < 13){
            if(dienaInt > 0 && dienaInt < 32){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else if(metaiInt == timeptr->tm_year + 1900){
        if(menuoInt > timeptr->tm_mon + 1 && menuoInt < 13){
            if(dienaInt > 0 && dienaInt < 32){
                return true;
            }
            else return false;
        }
        else if(menuoInt == timeptr->tm_mon + 1){
            if(dienaInt >= timeptr->tm_mday && dienaInt < 32){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

Nuoma::Nuoma(const std::string& address) {
	this->nuomos_adresas = address;
}
Nuoma::Nuoma(const double& cost) {
	this->nuomos_kaina = cost;
};
Nuoma::Nuoma(const std::string& address, const std::string& start, const std::string& end, const double& cost) : pradzia(nuomos_pradzia) , pabaiga(nuomos_pabaiga){
	this->nuomos_adresas = validateAddressConst(address);
    this->nuomos_pradzia = validateDataKonst(nuomos_pradzia);
    this->nuomos_pabaiga = validateDataKonst(nuomos_pabaiga);
	this->nuomos_kaina = validateCostKonst(cost);
	input_count++;
};
Nuoma::Nuoma(const Nuoma &var) : pradzia(var.nuomos_pradzia) , pabaiga(var.nuomos_pabaiga){
    input_count++;
    this->nuomos_adresas = validateAddressConst(var.nuomos_adresas);
    this->nuomos_pradzia = validateDataKonst(var.nuomos_pradzia);
    this->nuomos_pabaiga = validateDataKonst(var.nuomos_pabaiga);
    this->nuomos_kaina = validateCostKonst(var.nuomos_kaina);
}

//get
std::string Nuoma::getAddress() const {
	return this->nuomos_adresas;
};
std::string Nuoma::getRentStart() const {
	return this->nuomos_pradzia;
};

std::string Nuoma::getRentEnd() const {
	return this->nuomos_pabaiga;
};


double Nuoma::getCost() const {
	return this->nuomos_kaina;
};

//set
void Nuoma::setAddress(const std::string& val){
	this->nuomos_adresas = val;
}
void Nuoma::setRentStart(const std::string& val){
	this->nuomos_pradzia = val;
}
void Nuoma::setRentEnd(const std::string& val){
	this->nuomos_pabaiga = val;
}
void Nuoma::setCost(const double& val){
	this->nuomos_kaina = val;
}

void Nuoma::InformationInput(const std::string& address, const std::string& start, const std::string& end, const double& cost) {
	this->nuomos_adresas = address;
	this->nuomos_pradzia = start;
	this->nuomos_pabaiga = end;
	this->nuomos_kaina = cost;

};
std::string Nuoma::ShowInformation() const {
    double kaina = this->nuomos_kaina;
    std::string infoAll = "Adresas: " + this->nuomos_adresas + ", Pradzia: " + this->pradzia.retInfo() + ", Pabaiga: " + this->pabaiga.retInfo() + ", Kaina: " + std::to_string(kaina);
	return infoAll;
};
std::string Nuoma::InformationForFile() const {
	std::stringstream kk;
	kk << this->nuomos_kaina;
	std::string infoAll = this->nuomos_adresas + " " + this->nuomos_pradzia + " " + this->nuomos_pabaiga + " " + kk.str();
	return infoAll;
};

Nuoma::~Nuoma()
{

}

void Nuoma::changeSomething(const int& change) {
    std::string hold;
    double holdSum;
	switch (change)
	{
	case 1: std::cin >> hold;
            nuomos_adresas = validateAddressConst(hold);
		break;
	case 2:	std::cin >> hold;
            nuomos_pradzia = validateDataKonst(hold);
		break;
	case 3:	std::cin >> hold;
            nuomos_pabaiga = validateDataKonst(hold);
		break;
	case 4: std::cin >> holdSum;
            nuomos_kaina = validateCost(holdSum);
        break;
	default:
		break;
	}
}

std::string Nuoma::validateAddress(const std::string& salis){
    std::string testSalis = salis;
    while (true) {
        if (!isupper(testSalis[0])) {
            std::cout << "Pirma vedama raide turi buti didzioji!: ";
        }
        else break;
        getline(std::cin, testSalis);
    }
    return testSalis;
}
std::string Nuoma::validateAddressConst(const std::string& salis){
    std::string testSalis = salis;
    if (!isupper(testSalis[0])) {
            return "ERROR";
    }
    return testSalis;
}

std::string Nuoma::validateData(const std::string& data, const std::string& kur ){
	std::string testData = data;
	while(true){
		std::string metai, menuo, diena;
		int metaiInt, menuoInt, dienaInt;
		metai.append(testData, 0, 4);
		menuo.append(testData, 5, 2);
		diena.append(testData, 8, 2);
		metaiInt = stoi(metai, 0);
		menuoInt = stoi(menuo, 0);
		dienaInt = stoi(diena, 0);
		if (metaiInt < 3000 && metaiInt > 2000 && menuoInt > 0 && menuoInt < 13 && dienaInt > 0 && dienaInt < 32) {
			return testData;
		}
		else{
			std::cout << "Blogai ivesta " << kur <<" data, veskite is naujo!: ";
			getline(std::cin, testData);
		}
	}
	
}

std::string Nuoma::validateDataKonst(const std::string& data){
    std::string testData = data;
    std::string metai, menuo, diena;
    int metaiInt, menuoInt, dienaInt;
    try{
        metai.append(testData, 0, 4);
        menuo.append(testData, 5, 2);
        diena.append(testData, 8, 2);
        metaiInt = stoi(metai, 0);
        menuoInt = stoi(menuo, 0);
        dienaInt = stoi(diena, 0);
    }
    catch(std::invalid_argument& e){
        return "ERROR ARGUMENT";
    }
    catch(std::out_of_range& e){
        return "ERROR RANGE";
    }
    if (metaiInt < 3000 && metaiInt > 2000 && menuoInt > 0 && menuoInt < 13 && dienaInt > 0 && dienaInt < 32) {
        return testData;
    }
    else{
        return "ERROR METAI";
    }
}

double Nuoma::validateCost(const double& kaina){
	double testKaina = kaina;
	while(true){
		if(testKaina > 0 && testKaina < 100000){
			return testKaina;
		}
		else{
			std::cout << "Blogai ivesta kaina, veskite is naujo!: ";
			std::cin >> testKaina;
		}
	}
}

double Nuoma::validateCostKonst(const double& kaina){
    double testKaina = kaina;
    if(testKaina > 0 && testKaina < 100000){
        return testKaina;
    }
    else{
        return -1;
    }
}

bool Nuoma::sortByAddress(const Nuoma &a, const Nuoma &b){
    return a.nuomos_adresas < b.nuomos_adresas;
}

std::ostream& operator<<(std::ostream& os, const Nuoma &var){
    std::cout << "Adresas: " << var.getAddress() << ", Pradzia: " << var.getRentStart() << ", Pabaiga: " << var.getRentEnd() << ", Kaina: " << var.getCost();
    return os;
}

std::istream& operator>>(std::istream& is, Nuoma &var) {

	std::cout << "Iveskite nuomos adresa: ";

	int hold = 1;
	while (hold == 1) {
	    is >> var.nuomos_adresas;
		if (!isupper(var.nuomos_adresas[0])) {
			std::cout << "Pirma raide turi buti didzioji ";
		}
		else hold = 0;
	}
	is.get();

	std::cout << "Iveskite nuomos pradžios data (formatas yyyy:mm:dd): ";

	while (true) {
		is >> var.nuomos_pradzia;
		if (datosValidacijaTemp(var.nuomos_pradzia)) {
			break;
		} else {
			std::cout << "Blogai ivesta data, veskite is naujo!: ";
		}
	}

	std::cout << "Iveskite nuomos pabaigos data (formatas yyyy:mm:dd): ";

    while (true) {
		is >> var.nuomos_pabaiga;
		if (datosValidacijaTemp(var.nuomos_pabaiga)) {
			break;
		} else {
			std::cout << "Blogai ivesta data, veskite is naujo!: ";
		}
	}

    std::cout << "Iveskite nuomos kaina : ";

	while (true) {
		is >> var.nuomos_kaina;
		if (var.nuomos_kaina > 0 && var.nuomos_kaina < 1000000) {
			break;
		} else {
			std::cout << "Blogai ivesta kaina, iveskite is naujo!: ";
		}
	}

	return is;
}

int Nuoma::getInputCount() {
	return input_count;
}

void Nuoma::setInputCount(const int val) {
	input_count = val;
}

// definition of static variable
int Nuoma::pagalKaRikiuoti = 0;

int Nuoma::getPagalKaRikiuoti() {
	return pagalKaRikiuoti;
};

void Nuoma::setPagalKaRikiuoti(int pagalKa) {
    pagalKaRikiuoti = pagalKa;
}

bool operator<(const Nuoma& obj1, const Nuoma& obj2) {
    switch(Nuoma::getPagalKaRikiuoti()) {
        // Adresas nuo A iki Z
        case 1:
            return obj1.getAddress() > obj2.getAddress();
        // Adresas nuo Z iki A
        case 2:
            return obj1.getAddress() < obj2.getAddress();
        // Nuomos pradzia nuo artimiausios
        case 3:
            return obj1.pradzia.getDataAsString() > obj2.pradzia.getDataAsString();
        // Nuomos pradzia nuo tolimiausios
        case 4:
            return obj1.pradzia.getDataAsString() < obj2.pradzia.getDataAsString();
        // Nuomos pabaiga nuo tolimiausios
        case 5:
            return obj1.pabaiga.getDataAsString() > obj2.pabaiga.getDataAsString();
        // Nuomos pabainga nuo tolimiausios
        case 6:
            return obj1.pabaiga.getDataAsString() < obj2.pabaiga.getDataAsString();
        // Kaina didejimo
        case 7:
            return obj1.nuomos_kaina > obj2.nuomos_kaina;
        // Kaina mazejimo
        case 8:
            return obj1.nuomos_kaina < obj2.nuomos_kaina;
        default:
            std::cout << "Nuoma object Comparison field (PagalKaRikiuoti) is not set or set to the invalid value" << std::endl;
            return false;
    }
}
