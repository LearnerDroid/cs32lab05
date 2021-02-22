#ifndef VISITREP_H
#define VISITREP_H

#include "hospitalData.h"
#include "demogData.h"
#include "visitor.h"

using namespace std;

class visitorReport : public Visitor
{
public:
	virtual void visit(demogData* e) {
		//these are all totals
		demogData DD = *e;
		cout << "Demographics Info(State) : " << DD.getState();
		cout << "\nEducation info : ";
		cout << "\n(% bachelor degree or more) : " << (DD.getBAup() / DD.getTotalPop()) * 100;
		cout << "\n(% high school or more) : " << (DD.getHSup() / DD.getTotalPop()) * 100;
		cout << "\n % below poverty : " << (DD.getBelowPoverty() / DD.getTotalPop()) * 100 << "\n";
	}
	virtual void visit(hospitalData* e) {
		hospitalData HD = *e;
		cout << "Hospital Info : " << HD.getState();
		cout << "\nOverall rating(out of 5) : " << HD.getOverallRate() << "\n";
	}
};

#endif