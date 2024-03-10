#include "familyInsurance.h"

FamilyInsurance::FamilyInsurance(double price, int members)
	: Insurance(price), familyInsurance_members(members)
{

}

FamilyInsurance::FamilyInsurance(const FamilyInsurance& F)
	: familyInsurance_members(F.familyInsurance_members), Insurance(F)

{

}

FamilyInsurance::~FamilyInsurance()
{

}

void FamilyInsurance::print()
{
	std::cout << "Family Insurance:  price - " << this->insurance_price << " , members - " << this->familyInsurance_members << " , total price - " << this->totalPrice() << std::endl;
}


void FamilyInsurance::printOn(std::ostream& os) const
{
	os << "price: " << this->insurance_price << ", members: " << this->familyInsurance_members;
}

void FamilyInsurance::readFrom(std::istream& is)
{
	is >> this->insurance_price >> this->familyInsurance_members;
}

double FamilyInsurance::totalPrice() const
{
	return this->insurance_price * this->familyInsurance_members;
}