#include "Project7-5Conversions.h"

namespace Conversions
{
	double FeetToMeters(double feet)
	{
		return feet * conversion_const;
	}
	
	double MetersToFeet(double meters)
	{
		return meters / conversion_const;
	}
}
