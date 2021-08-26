#pragma once

#include <cmath>

namespace Taxes
{
	const double taxRate = 0.06;
	double Round(double num, int places);
	double GetTaxAmount(double &total);
	double GetTotal(double &total);
}
