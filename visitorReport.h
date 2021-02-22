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
		demogData DD = *e;
		cout << "Demographics Info(State) : " << DD.getState();
		cout << "\nEducation info :";
		cout << "\n(% bachelor degree or more) : " << DD.getBAup();
		cout << "\n(% high school or more) : " << DD.getHSup();
		cout << "\n% below poverty : " << DD.getBelowPoverty();
	}
	virtual void visit(hospitalData* e) {
		hospitalData HD = *e;
		cout << "Hosptial Info: " << HD.getName();
		cout << "\nOverall rating (out of 5): " << HD.getOverallRate();
		cout << "\nOverall rating (out of 5): " << HD.getOverallRate();
	}
};

#endif