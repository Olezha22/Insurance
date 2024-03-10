#pragma once
#include "insurance.h"

class FamilyInsurance : public Insurance
{
private: 
	int familyInsurance_members;
public:

	FamilyInsurance() = default;
	FamilyInsurance(double price, int members);
	FamilyInsurance(const FamilyInsurance& F);
	virtual ~FamilyInsurance();




	virtual void printOn(std::ostream& os) const override;
	virtual void readFrom(std::istream& is) override;
	virtual double totalPrice() const override;
	virtual void print() override;
};