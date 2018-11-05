//Nick Condos

#ifndef BOX_H_
#define BOX_H_

#include <iostream>
#include <string>
#include "Package.h"

using namespace std;

class Box : public Package
{
	private:

	double boxCost;
	double boxWeight;
	int trackingNum;

	public:

	double getCost() const { return boxCost; }
	double getWeight() const { return boxWeight; }
	int getTrackNum() const { return trackingNum; }

	~Box(); //Virtual keyword optional, defaults to virtual anyways
	Box(int trackNumber, double bWeight, double bCost);
	virtual void print(ostream& out=cout) const;

};

ostream& operator<<(ostream& out, const Box& b);


#endif /* BOX_H_ */
