#include "stdafx.h"
#include "Sales_data.h"



istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << "ISBN: " << item.isbn() << " " << " Units sold: " << item.units_sold << " Revenue: "
		<< item.revenue << " Average price: " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs; // copy data members from lhs into sum
	sum.combine(rhs); // add data members from rhs into sum
	return sum;
}

double Sales_data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into
	revenue += rhs.revenue; // the members of ''this'' object
	return *this; // return the object on which the function was called
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this); // read will read a transaction from is into this object
}
