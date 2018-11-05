//Nick Condos

#ifndef LETTER_H_
#define LETTER_H_

#include <iostream>
#include <string>
#include "Package.h"

using namespace std;

class Letter : public Package
{
	private:

	double letterCost;
	double letterWeight;
	int trackingNum;

	public:

	double getCost() const { return letterCost; }
	double getWeight() const { return letterWeight; }
	int getTrackNum() const { return trackingNum; }

	~Letter(); //Virtual keyword optional, defaults to virtual anyways
	Letter(int trackNumber, double lWeight, double lCost);
	virtual void print(ostream& out=cout) const;


};

ostream& operator<<(ostream& out, const Letter& l);

#endif /* LETTER_H_ */
