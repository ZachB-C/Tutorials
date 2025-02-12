#include <iostream>

using namespace std;

int main() {
	double sales = 95000;
	
	const double stateTaxRate = 0.04;
	const double countyTaxRate = 0.02;
	const double totalTaxRate = stateTaxRate + countyTaxRate;

	double stateTax = stateTaxRate * sales;
	double countyTax = countyTaxRate * sales;
	double totalTax = totalTaxRate * sales;
	
	double netRevenue = sales - totalTax;

	cout << "Profit: \t$"    << sales << endl
	     << "State Tax: \t$" << stateTax << endl
	     << "County Tax: \t$"<< countyTax << endl
	     << "Total Tax: \t$"<< totalTax << endl
	     << "Net Revenue: \t$"<< netRevenue << endl;

	return 0;
}
