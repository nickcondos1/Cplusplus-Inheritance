//Nick Condos

#ifndef CRATE_H_
#define CRATE_H_

#include "Package.h"
#include <string>
#include <iostream>

using namespace std;

class Crate : public Package
{
	private:

	double crateCost;
	double crateWeight;
	int trackingNum;
	string type;

	public:

	double getCost() const { return crateCost; }
	double getWeight() const { return crateWeight; }
	int getTrackNum() const { return trackingNum; }
	string getType() const { return type; }

	~Crate(); //Virtual keyword optional, defaults to virtual anyways
	Crate(int trackNumber, double cWeight, double cCost);
	virtual void print(ostream& out=cout) const = 0; //Abstract

};

ostream& operator<<(ostream& out, const Crate& c);


#endif /* CRATE_H_ */
