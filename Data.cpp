
#include "Data.h"
#include "myException.h"
#include <string>
#include <stdexcept>

using exception::myException;

DataSpace::Data::Data(){
    this->diena = 0;
    this->menuo = 0;
    this->metai = 0;
}

DataSpace::Data::Data(const std::string &data){
    try {
        if(data == "NA"){
            this->diena = 0;
            this->menuo = 0;
            this->metai = 0;
            return;
        }
        std::string testData = data;
        std::string metai, menuo, diena;
        int metaiInt, menuoInt, dienaInt;
        metai.append(testData, 0, 4);
        menuo.append(testData, 5, 2);
        diena.append(testData, 8, 2);
        metaiInt = stoi(metai, 0);
        menuoInt = stoi(menuo, 0);
        dienaInt = stoi(diena, 0);
        this->diena = dienaInt;
        this->menuo = menuoInt;
        this->metai = metaiInt;
        dataAsString = data;
    } catch (const std::out_of_range ex) {
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return;
    } catch (std::invalid_argument& e){
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return;
    }
    
}

int DataSpace::Data::validateDiena(int *diena){
    if(*diena > 0 && *diena < 32){
        return *diena;
    }
    else return 0;
    
}
int DataSpace::Data::validateMenuo(int *menuo){
    if(*menuo > 0 && *menuo < 13){
        return *menuo;
    }
    else return 0;
    
}
int DataSpace::Data::validateMetai(int *metai){
    std::time_t t = time(NULL);
    tm* timeptr = localtime(&t);
    if(*metai >= timeptr->tm_year){
        return *metai;
    }
    else return 0;
}
bool DataSpace::Data::validateFullDate(const std::string &data){
    if(data == "NA"){
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return false;
    }
    std::string testData = data;
    std::string metai, menuo, diena;
    int metaiInt, menuoInt, dienaInt;
    try {
        metai.append(testData, 0, 4);
        menuo.append(testData, 5, 2);
        diena.append(testData, 8, 2);
        metaiInt = stoi(metai, 0);
        menuoInt = stoi(menuo, 0);
        dienaInt = stoi(diena, 0);
    } catch (myException& e) {
        e.what();
    }
    this->diena = dienaInt;
    this->menuo = menuoInt;
    this->metai = metaiInt;
    return true;
}
/*  Keep this for current date validation algorithm
bool Data::vvalidateFullDate(const std::string &data){
    if(data == "NA"){
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return false;
    }
    std::string testData = data;
    std::string metai, menuo, diena;
    int metaiInt, menuoInt, dienaInt;
    metai.append(testData, 0, 4);
    menuo.append(testData, 5, 2);
    diena.append(testData, 8, 2);
    metaiInt = stoi(metai, 0);
    menuoInt = stoi(menuo, 0);
    dienaInt = stoi(diena, 0);
    std::time_t t = time(NULL);
    tm* timeptr = localtime(&t);
    if(metaiInt > timeptr->tm_year){
        if(validateMenuo(&menuoInt) != 0){
            if(validateDiena(&dienaInt) != 0){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return true;
            }
            else return false;
        }
        else return false;
    }
    else if(metaiInt == timeptr->tm_year){
        if(validateMenuo(&menuoInt) > timeptr->tm_mon){
            if(validateDiena(&dienaInt) != 0){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return true;
            }
            else return false;
        }
        else if(validateMenuo(&menuoInt) == timeptr->tm_mon){
            if(validateDiena(&dienaInt) >= timeptr->tm_mday){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
*/
void DataSpace::Data::setFullDate(const std::string &data){
    if(data == "NA"){
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return;
    }
    std::string testData = data;
    std::string metai, menuo, diena;
    int metaiInt, menuoInt, dienaInt;
    metai.append(testData, 0, 4);
    menuo.append(testData, 5, 2);
    diena.append(testData, 8, 2);
    metaiInt = stoi(metai, 0);
    menuoInt = stoi(menuo, 0);
    dienaInt = stoi(diena, 0);
    std::time_t t = time(NULL);
    tm* timeptr = localtime(&t);
    if(metaiInt > timeptr->tm_year){
        if(validateMenuo(&menuoInt) != 0){
            if(validateDiena(&dienaInt) != 0){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else {
            this->diena = 0;
            this->menuo = 0;
            this->metai = 0;
            return;
        }
    }
    else if(metaiInt == timeptr->tm_year){
        if(validateMenuo(&menuoInt) > timeptr->tm_mon){
            if(validateDiena(&dienaInt) != 0){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else if(validateMenuo(&menuoInt) == timeptr->tm_mon){
            if(validateDiena(&dienaInt) >= timeptr->tm_mday){
                this->diena = dienaInt;
                this->menuo = menuoInt;
                this->metai = metaiInt;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else{
            this->diena = 0;
            this->menuo = 0;
            this->metai = 0;
            return;
        }
    }
    else {
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return;
    }
}

void DataSpace::Data::setFullDate(int &diena, int &menuo, int &metai){
    std::time_t t = time(NULL);
    tm* timeptr = localtime(&t);
    if(metai > timeptr->tm_year){
        if(validateMenuo(&menuo) != 0){
            if(validateDiena(&diena) != 0){
                this->diena = diena;
                this->menuo = menuo;
                this->metai = metai;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else {
            this->diena = 0;
            this->menuo = 0;
            this->metai = 0;
            return;
        }
    }
    else if(metai == timeptr->tm_year){
        if(validateMenuo(&menuo) > timeptr->tm_mon){
            if(validateDiena(&diena) != 0){
                this->diena = diena;
                this->menuo = menuo;
                this->metai = metai;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else if(validateMenuo(&menuo) == timeptr->tm_mon){
            if(validateDiena(&diena) >= timeptr->tm_mday){
                this->diena = diena;
                this->menuo = menuo;
                this->metai = metai;
                return;
            }
            else {
                this->diena = 0;
                this->menuo = 0;
                this->metai = 0;
                return;
            }
        }
        else{
            this->diena = 0;
            this->menuo = 0;
            this->metai = 0;
            return;
        }
    }
    else {
        this->diena = 0;
        this->menuo = 0;
        this->metai = 0;
        return;
    }
}

std::string DataSpace::Data::retInfo() const {
    std::string ret = std::to_string(metai) + ":" + std::to_string(menuo) + ":" + std::to_string(diena);
    return ret;
}

std::string DataSpace::Data::getDataAsString() const {
    return dataAsString;
}
