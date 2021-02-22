#include "comboDemogData.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>


void comboDemogData::addDemogtoRegion(shared_ptr<demogData> CD) {
	setpopOver65(getpopOver65() + CD->getpopOver65());
	setpopUnder18(getpopUnder18() + CD->getpopUnder18());
	setpopUnder5(getpopUnder5() + CD->getpopUnder5());
	setBAup(getBAup() + CD->getBAup());
	setHSup(getHSup() + CD->getHSup());
	setBelowPoverty(getBelowPoverty() + CD->getBelowPoverty());
	setTotalPop(getTotalPop() + CD->getTotalPop());
	counties.push_back(CD);
}