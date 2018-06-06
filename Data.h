#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>
#include <string>
#include <chrono>

namespace DataSpace {

    class Data {
        int diena, menuo, metai;
        std::string dataAsString;
    public:
        Data();

        Data(const std::string &data);

        Data(int *diena, int *menuo, int *metai);

        virtual int validateDiena(int *diena = 0);

        virtual int validateMenuo(int *menuo = 0);

        virtual int validateMetai(int *metai = 0);

        virtual bool validateFullDate(const std::string &data);

        virtual void setFullDate(const std::string &data);

        virtual void setFullDate(int &diena, int &menuo, int &metai);

        std::string getDataAsString() const;

        std::string retInfo() const;
    };

};

#endif /* _DATA_H_ */
