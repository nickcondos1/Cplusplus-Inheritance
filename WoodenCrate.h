//Nick Condos

#ifndef WOODENCRATE_H_
#define WOODENCRATE_H_

#include "Crate.h"
#include <string>
#include <iostream>

using namespace std;

class WoodenCrate : public Crate
{


	private:

	double crateCost;
	double crateWeight;
	int trackingNum;

	public:

	double getCost() const { return crateCost; }
	double getWeight() const { return crateWeight; }
	int getTrackNum() const { return trackingNum; }

	~WoodenCrate(); //Virtual keyword optional, defaults to virtual anyways
	WoodenCrate(int trackNumber, double cWeight, double cCost);
	virtual void print(ostream& out=cout) const;


};

ostream& operator<<(ostream& out, const WoodenCrate& wc);

#endif /* WOODENCRATE_H_ */
