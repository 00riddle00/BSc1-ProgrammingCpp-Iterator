#ifndef MAIN_H
#define MAIN_H


#include "Nuoma.h"
#include "ApartamentuNuoma.h"
#include "myContainer.h"
#include "myException.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>
#include <list>




Container <Nuoma>esp;
std::list<Nuoma> holdEsp;

int Nuoma::input_count = 0;
const size_t ivestysPerPsl = 5;

void AppStart();
int menu();
void nuomosIvedimas();
void nuomosApartamentuIvedimas();
void visosNuomos();
void visosNuomos(int &kiekRodyti);
void AppEnd();
void failoNuskaitymas();
std::string addressInput();
void ChangeValues();
std::string datosIvedimas();
bool datosValidacija(const std::string& data);
double CostInput();
void rikiuok();
void pagalSali(std::vector<Nuoma*> hold);
bool aToz(const std::string &a, const std::string &b);
bool zToa(const std::string &a, const std::string &b);
bool asc(const double &a, const double &b);
bool desc(const double &a, const double &b);
void rusiuok();
void maxNuomos();

void AppStart() {
	int menuPasirinkimas = 1;
    try {
        failoNuskaitymas();
    } catch(std::exception &ex) {
        std::cout << "Klaida: " << ex.what() << "!\n";
    }

    maxNuomos();
	while (menuPasirinkimas != 0) {
		menuPasirinkimas = menu();
		switch (menuPasirinkimas) {
		case 1: nuomosIvedimas();
			break;
        case 7: nuomosApartamentuIvedimas();
            break;
		case 2: visosNuomos();
			break;
		case 3: rikiuok();
			break;
		case 4: rusiuok();
			break;
        case 5: ChangeValues();
            break;
        case 6: std::cout << "Iveskite kiek nuomu norite pamatyti: ";
                int kiek;
                std::cin >> kiek;
                visosNuomos(kiek);
                break;
		case 0: AppEnd();
			break;
		}
	}
}



int menu() {
	int x = 0;
	while (true) {
		std::cout << "Pasirinkite opcija is meniu: " << std::endl;
		std::cout << "1 - Ivesti nauja nuomą" << std::endl;

		std::cout << "2 - Pamatyti visas nuomas" << std::endl;
		std::cout << "3 - Rikiuoti" << std::endl;
        std::cout << "4 - Rusiuoti" << std::endl;
		std::cout << "5 - Pakeisti kuri nors irasa" << std::endl;
        std::cout << "6 - Perziureti nuomu sarasa" << std::endl;
        std::cout << "7 - Ivesti nauja apartamentu nuomą" << std::endl;
        std::cout << "0 - Baigti programa" << std::endl;
        std::cout << "Siuo metu yra nuomu: " << Nuoma::getInputCount() << std::endl;
		std::cin >> x;
		if (x == 1 || x == 7 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 0) return x;
	}
}

void nuomosIvedimas() {
    Nuoma* nuoma = new Nuoma();
    std::cin >> *nuoma;
    esp.push_back(nuoma);
}

void nuomosApartamentuIvedimas(){
    std::string address, start, end;
    double cost, apart_cost;
    std::cout << "Iveskite nuomos adresa: ";
    address = addressInput();
    std::cout << "Iveskite nuomos pradžios data (formatas yyyy:mm:dd): ";
    start = datosIvedimas();
    std::cout << "Iveskite nuomos pabaigos data (formatas yyyy:mm:dd): ";
    end = datosIvedimas();
    std::cout << "Iveskite nuomos kaina : ";
    cost = CostInput();
    std::cout << "Iveskite apartamentu nuomos kaina : ";
    apart_cost = CostInput();
    esp.push_back(new ApartamentuNuoma(address, start, end, cost, apart_cost));
}

void visosNuomos() {
    for(Container<Nuoma>::iterator start = esp.begin(); start != esp.end(); start++)
        std::cout << (*start)->ShowInformation() << std::endl;
}

void visosNuomos(int &kiekRodyti){
    for (int i = 0; i < kiekRodyti; i++) {
        std::cout << esp[i].ShowInformation() << std::endl;
    }
}

void maxNuomos(){
    if(esp.size() > ivestysPerPsl){
        std::cout << "Nuomu daugiau nei 5, rodomos tik pirmos 5. Jei norite matyti visas pasirinkite opcija nr. 2 \n\n";
    }
}

void AppEnd() {
	std::ofstream myFile;
    myFile.open("duomenys.txt", std::ios_base::trunc);
	std::cout << "Duomenys irasinejami i faila..." << std::endl;
	for (int i = 0; i < esp.size(); i++) {
		myFile << esp[i].InformationForFile() << std::endl;
	}
	myFile.close();
    std::cout << "Duomenys irasyti!" << std::endl;
}


void failoNuskaitymas() {
	std::string hold, address, start, end, price;
	double price_d;
    std::ifstream myFile("duomenys.txt");
    if (myFile) {
        while (true) {
            getline(myFile, address, ' ');
            getline(myFile, start, ' ');
            getline(myFile, end, ' ');
            getline(myFile, price, '\n');
            price_d = atof(price.c_str());
            if (!myFile.good()) break;
            esp.push_back(new Nuoma(address, start, end, price_d));
        }
    } else {
        throw std::runtime_error("Could not open file");
    }
	myFile.close();
}

std::string addressInput() {
	std::string saliesPavadinimas;
	int hold = 1;
	while (hold == 1) {
		getline(std::cin, saliesPavadinimas);
		if (!isupper(saliesPavadinimas[0])) {
			std::cout << "Pirma raide turi buti didzioji ";
		}
		else hold = 0;
	}
	return saliesPavadinimas;
}

void ChangeValues() {
	std::cout << "Pasirinkite kuri irasa nori pakeisti: " << std::endl;
	for (int i = 0; i < esp.size(); i++) {
		std::cout << i + 1 << ") " << esp[i].ShowInformation() << std::endl;
	}
	int numeris;
	std::cin >> numeris;
	if (numeris > esp.size() || numeris <= 0) {
		std::cout << "Tokio numerio nera!" << std::endl;
		return;
	}
	std::cout << esp[numeris - 1].ShowInformation() << std::endl;
	std::cout << "Ka norite pakeisti: \n1. Adresa \n2. Nuomos pradzia \n3. Nuomos pabaiga \n4. Kaina" << std::endl;
	int change = 0;
	std::cin >> change;
	std::cout << "Iveskite i ka norite pakeisti: ";
	esp[numeris - 1].changeSomething(change);
}

std::string datosIvedimas() {
	std::string data;
	int hold = 0;
	while (hold == 0) {
		std::cin >> data;
		if (datosValidacija(data)) {
			hold = 1;
			return data;
		}
		else {
			std::cout << "Blogai ivesta data, veskite is naujo!: ";
		}
	}
    return data;
}

bool datosValidacija(const std::string& data) {
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

double CostInput() {
	double kaina = 0;
	int hold = 0;
	while (hold == 0) {
		std::cin >> kaina;
		if (kaina > 0 && kaina < 1000000) {
			hold = 1;
			return kaina;
		}
		else {
			std::cout << "Blogai ivesta kaina, iveskite is naujo!: ";
		}
	}
    return kaina;
}

void rikiuok(){

    for (size_t i = 0; i < esp.size(); i++) {
        holdEsp.push_back(esp[i]);
    }

    std::cout << "Pasirinkite pagal ka rikiuoti \n1) Adresa A-Z \n2) Adresa Z-A \n3) Nuomos pradzia nuo artimiausios \n4) Nuomos pradzia nuo tolimiausios \n5) Nuomos pabaiga nuo artimiausios \n6) Nuomos pabaiga nuo tolimiausios \n7) Kaina didejimo \n8) Kaina mazejimo \n0) Grizti" << std::endl;
	int pagalKa;
	std::cin >> pagalKa;
	Nuoma::setPagalKaRikiuoti(pagalKa);
	Nuoma holder;

	for (std::_List_iterator<Nuoma> it1 = holdEsp.begin(); it1 != holdEsp.end(); ++it1) {
        for (std::_List_iterator<Nuoma> it2 = holdEsp.begin(); it2 != holdEsp.end(); ++it2) {
            if (*it2 < *it1) {
                holder = *it1;
                *it1 = *it2;
                *it2 = holder;
            }
        }
    }

    for (std::_List_iterator<Nuoma> it1 = holdEsp.begin(); it1 != holdEsp.end(); ++it1) {
         std::cout << (*(it1)).ShowInformation() << std::endl;
	}
}

bool aToz(const std::string &a, const std::string &b){
    return a > b;
}

bool zToa(const std::string &a, const std::string &b){
    return a < b;
}

bool asc(const double &a, const double &b){
    return a > b;
}

bool desc(const double &a, const double &b){
    return a < b;
}

void rusiuok(){
    std::cout << "Pagal ka rusiuosim?: \n1) Adresa \n2) Pradzia \n3) Pabaiga \n4) Kaina \n0) Grizti" << std::endl;
    int pasirinkimas;
    std::string hold;
    double holdDouble;
    std::cin >> pasirinkimas;
    switch (pasirinkimas) {
        case 1:
            std::cout << "Iveskite visa adresa ar dali adreso: ";
            std::cin >> hold;
            for (size_t i = 0; i < esp.size(); i++) {
                if(esp[i].getAddress().find(hold) != std::string::npos){
                    std::cout << "Adresas: " << esp[i].getAddress() << ", Pradzia: " << esp[i].getRentStart() << ", Pabaiga: " << esp[i].getRentEnd() << ", Kaina: " << esp[i].getCost() << std::endl;
                }
            }
            break;
        case 2:
            std::cout << "Iveskite pilna data arba dali datos: ";
            std::cin >> hold;
            for (size_t i = 0; i < esp.size(); i++) {
                if(esp[i].getRentEnd().find(hold) != std::string::npos){
                    std::cout << "Adresas: " << esp[i].getAddress() << ", Pradzia: " << esp[i].getRentStart() << ", Pabaiga: " << esp[i].getRentEnd() << ", Kaina: " << esp[i].getCost() << std::endl;
                }
            }
            break;
        case 3:
            std::cout << "Iveskite pilna data arba dali datos: ";
            std::cin >> hold;
            for (size_t i = 0; i < esp.size(); i++) {
                if(esp[i].getRentEnd().find(hold) != std::string::npos){
                    std::cout << "Adresas: " << esp[i].getAddress() << ", Pradzia: " << esp[i].getRentStart() << ", Pabaiga: " << esp[i].getRentEnd() << ", Kaina: " << esp[i].getCost() << std::endl;
                }
            }
            break;
        case 4:
            std::cout << "Iveskite kaina: ";
            std::cin >> holdDouble;
            for (size_t i = 0; i < esp.size(); i++) {
                if(esp[i].getCost() == holdDouble){
                    std::cout << "Adresas: " << esp[i].getAddress() << ", Pradzia: " << esp[i].getRentStart() << ", Pabaiga: " << esp[i].getRentEnd() << ", Kaina: " << esp[i].getCost() << std::endl;
                }
            }
        default:
            break;
    }
}



#endif /* MAIN_H */

