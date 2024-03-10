#pragma once
#include "insurance.h"

class CarInsurance : public Insurance
{
private:
	double carInsurance_engine;
public:

	CarInsurance() = default;
	CarInsurance(double price, double engine);
	CarInsurance(const CarInsurance& C);
	virtual ~CarInsurance();




	virtual void printOn(std::ostream& os) const override;
	virtual void readFrom(std::istream& is) override;
	virtual double totalPrice() const override;
	virtual void print() override;
};