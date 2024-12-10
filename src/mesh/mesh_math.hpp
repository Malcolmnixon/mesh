#pragma once

#include <algorithm>
#include <cmath>
#include <limits>

namespace mesh
{
	/// Calculate absolute value of a double
	/// @param p_value              Value to calculate absolute value of
	/// @return						Absolute value
	constexpr double cabs(const double p_value)
	{
		return p_value < 0.0 ? -p_value : p_value;
	}

	/// Test if a double is approximately zero
	/// @param p_value              Value to test
	/// @return                     True if zero
	constexpr bool is_zero_approx(const double p_value)
	{
        // Return true if the value is under the numeric tolerance
		return cabs(p_value) < std::numeric_limits<double>::epsilon();
	}

	/// Test if two doubles are approximately equal
	/// @param p_value1             First value to test
	/// @param p_value2             Second value to test
	/// @return                     True if equal
	constexpr bool is_equal_approx(const double p_value1, const double p_value2)
	{
        // Handle exact match
		if (p_value1 == p_value2)
			return true;

        // Calculate tolerance base on magnitude of values
		const double tolerance = std::max(cabs(p_value1), cabs(p_value2)) * std::numeric_limits<double>::epsilon();
        
        // Return true if difference is under the tolerance
		return cabs(p_value1 - p_value2) < tolerance;
	}
    
    constexpr bool is_equal_approx(const double p_value1, const double p_value2, const double p_tolerance)
    {
        // Handle exact match
		if (p_value1 == p_value2)
			return true;
        
        // Return true if difference is under the tolerance
        return cabs(p_value1 - p_value2) < p_tolerance;
    }
    

	/// Get sign of a double
	/// @param p_value              Value to get sign of
	/// @return                     -1 if negative, 0 if zero, 1 if positive
	constexpr int get_sign(const double p_value)
	{
		if (p_value < -std::numeric_limits<double>::epsilon())
			return -1;
		if (p_value > std::numeric_limits<double>::epsilon())
			return 1;
		return 0;
	}

	/// Linear interpolation
	/// @param p_value1             First value
	/// @param p_value2             Second value
	/// @param p_s                  Interpolation factor
	/// @return                     Interpolated value
	constexpr double lerp(const double p_value1, const double p_value2, const double p_s)
	{
		return p_value1 + (p_value2 - p_value1) * p_s;
	}
}
