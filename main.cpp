#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include "dataAQ.h"
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "parse.h"

using namespace std;

int main() {

    dataAQ theAnswers;
    cout << std::setprecision(2) << std::fixed;
    //read in the hospital data
    std::vector<shared_ptr<placeData>> theHospitalData = read_csv(
        "hospitals.csv", HOSPITAL);

    //read in the demographic data
    std::vector<shared_ptr<placeData>> theCountyDemogData = read_csv(
        "county_demographics.csv", DEMOG);
    /*
    for (shared_ptr<placeData> p : theCountyDemogData) {
        shared_ptr<demogData> county = static_pointer_cast<demogData>(p);
        if (county->getBelowPoverty() > county->getTotalPop()) {
            std::cout << county->getBelowPoverty() << "  brrrrrrrruh  " << county->getTotalPop() << std::endl;
        }
    }
    */
    //create the state demographic data
    theAnswers.createStateDemogData((std::vector<shared_ptr<demogData>>&)theCountyDemogData);

    //create the state hospital data
    theAnswers.createStateHospData((std::vector<shared_ptr<hospitalData>>&)theHospitalData);
    cout << theAnswers.allStateDemogData["MS"]->getBelowPoverty() / theAnswers.allStateDemogData["MS"]->getTotalPop() << endl;
    return 0;
}