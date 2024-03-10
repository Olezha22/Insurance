#include "carInsurance.h"

CarInsurance::CarInsurance(double price, double engine)
	: Insurance(price), carInsurance_engine(engine)
{

}
CarInsurance::CarInsurance(const CarInsurance& C)
	: Insurance(C), carInsurance_engine(C.carInsurance_engine)
{
	
}
CarInsurance::~CarInsurance()
{

}


void CarInsurance::print()
{
	std::cout << "Car Insurance:  price - " << this->insurance_price << " , volume of engine - " << this->carInsurance_engine << " , total price - " << this->totalPrice() << std::endl;
}

void CarInsurance::printOn(std::ostream& os) const
{
	os << "price: " << this->insurance_price << ", engine_volume: " << this->carInsurance_engine;
}
void CarInsurance::readFrom(std::istream& is)
{
	is >> this->insurance_price >> this->carInsurance_engine;
}


double CarInsurance::totalPrice() const
{
	if (this->carInsurance_engine > 2.0 && this->carInsurance_engine < 3.0) {
		return insurance_price * 1.15;
	}
	else if (this->carInsurance_engine > 3.0) {
		return insurance_price * 1.25;
	}
	else {
		return insurance_price;
	}
}