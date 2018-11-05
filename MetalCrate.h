//Nick Condos

#ifndef METALCRATE_H_
#define METALCRATE_H_

#include "Crate.h"
#include <string>
#include <iostream>

using namespace std;

class MetalCrate : public Crate
{
	private:

	double crateCost;
	double crateWeight;
	int trackingNum;

	public:

	double getCost() const { return crateCost; }
	double getWeight() const { return crateWeight; }
	int getTrackNum() const { return trackingNum; }

	~MetalCrate(); //Virtual keyword optional, defaults to virtual anyways
	MetalCrate(int trackNumber, double cWeight, double cCost);
	virtual void print(ostream& out=cout) const;


};

ostream& operator<<(ostream& out, const MetalCrate& wc);

#endif
