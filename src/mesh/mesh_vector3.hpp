#pragma once

#include "mesh_math.hpp"

namespace mesh
{
    /// 3D vector
    struct vector3
    {
        double x; ///< X component
        double y; ///< Y component
        double z; ///< Z component

        /// Constructor
        /// @param p_x                  X component
        /// @param p_y                  Y component
        /// @param p_z                  Z component
		constexpr explicit vector3(const double p_x = 0.0, const double p_y = 0.0, const double p_z = 0.0)
			: x(p_x), y(p_y), z(p_z)
		{
		}

        /// Calculate vector length squared
        /// @return                     Length squared
        constexpr double length2() const
		{
			return x * x + y * y + z * z;
		}

        /// Calculate vector length
        /// @return                     Length
        double length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

        /// Calculate vector dot product
        /// @param p_v                  Vector to dot with
        /// @return                     Dot product
        constexpr double dot(const vector3& p_v) const
		{
			return x * p_v.x + y * p_v.y + z * p_v.z;
		}

        /// Calculate vector cross product
        /// @param p_v                  Vector to cross with
        /// @return                     Cross product
        constexpr vector3 cross(const vector3& p_v) const
		{
			return vector3{
				y * p_v.z - z * p_v.y,
				z * p_v.x - x * p_v.z,
				x * p_v.y - y * p_v.x
			};
		}

        /// Calculate normalized vector
        /// @return                     Normalized vector
        vector3 normalized() const
		{
            const double l = length();
            if (l == 0.0)
                return vector3{ 0.0, 0.0, 0.0 };

            return vector3{ x / l, y / l, z / l };
        }

        /// Calculate linear interpolation
        /// @param p_v                  Vector to lerp to
        /// @param p_t                  Interpolation factor
        /// @return                     Interpolated vector
        constexpr vector3 lerp(const vector3& p_v, const double p_t) const
		{
			return vector3{
			   mesh::lerp(x, p_v.x, p_t),
			   mesh::lerp(y, p_v.y, p_t),
			   mesh::lerp(z, p_v.z, p_t)
			};
		}

        /// Check if vector is zero
        /// @return                     True if zero
        constexpr bool is_zero_approx() const
		{
			return mesh::is_zero_approx(x) &&
				mesh::is_zero_approx(y) &&
				mesh::is_zero_approx(z);
		}

        /// Check if vector is approximately equal to another vector
        /// @param p_v                  Vector to compare with
        /// @return                     True if equal
        constexpr bool is_equal_approx(const vector3& p_v) const
		{
			return mesh::is_equal_approx(x, p_v.x) &&
				mesh::is_equal_approx(y, p_v.y) &&
				mesh::is_equal_approx(z, p_v.z);
		}

        /// Vector equality operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if equal
        friend constexpr bool operator==(const vector3& p_a, const vector3& p_b)
		{
			return p_a.x == p_b.x && p_a.y == p_b.y && p_a.z == p_b.z;
		}

        /// Vector inequality operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if not equal
        friend constexpr bool operator!=(const vector3& p_a, const vector3& p_b)
		{
			return p_a.x != p_b.x || p_a.y != p_b.y || p_a.z != p_b.z;
		}

        /// Vector less than operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if less than
        friend constexpr bool operator<(const vector3& p_a, const vector3& p_b)
		{
            if (p_a.x == p_b.x)
            {
                if (p_a.y == p_b.y)
                {
                    return p_a.z < p_b.z;
                }
            	return p_a.y < p_b.y;
            }
            return p_a.x < p_b.x;
		}

        /// Vector greater than operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if greater than
        friend constexpr bool operator>(const vector3& p_a, const vector3& p_b)
		{
            if (p_a.x == p_b.x)
            {
                if (p_a.y == p_b.y)
                {
                    return p_a.z > p_b.z;
                }
                return p_a.y > p_b.y;
            }
            return p_a.x > p_b.x;
        }

        /// Vector less than or equal operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if less than or equal
        friend constexpr bool operator<=(const vector3& p_a, const vector3& p_b)
        {
            if (p_a.x == p_b.x)
            {
                if (p_a.y == p_b.y)
                {
                    return p_a.z <= p_b.z;
                }
                return p_a.y < p_b.y;
            }
            return p_a.x < p_b.x;
        }

        /// Vector greater than or equal operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     True if greater than or equal
        friend constexpr bool operator>=(const vector3& p_a, const vector3& p_b)
        {
            if (p_a.x == p_b.x)
            {
                if (p_a.y == p_b.y)
                {
                    return p_a.z >= p_b.z;
                }
                return p_a.y > p_b.y;
            }
            return p_a.x > p_b.x;
        }

        /// Vector negation operator
        /// @param p_v                  Vector to negate
        /// @return                     Negated vector
        friend constexpr vector3 operator-(const vector3& p_v)
		{
			return vector3{ -p_v.x, -p_v.y, -p_v.z };
		}

        /// Vector addition operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Vector sum
        friend constexpr vector3 operator+(const vector3& p_a, const vector3& p_b)
		{
			return vector3{ p_a.x + p_b.x, p_a.y + p_b.y, p_a.z + p_b.z };
		}

        /// Vector subtraction operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Vector difference
        friend constexpr vector3 operator-(const vector3& p_a, const vector3& p_b)
		{
			return vector3{ p_a.x - p_b.x, p_a.y - p_b.y, p_a.z - p_b.z };
		}

        /// Vector multiplication operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Vector product
        friend constexpr vector3 operator*(const vector3& p_a, const vector3& p_b)
		{
			return vector3{ p_a.x * p_b.x, p_a.y * p_b.y, p_a.z * p_b.z };
		}

        /// Vector division operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Vector quotient
        friend constexpr vector3 operator/(const vector3& p_a, const vector3& p_b)
		{
			return vector3{ p_a.x / p_b.x, p_a.y / p_b.y, p_a.z / p_b.z };
		}

        /// Vector multiplication operator
        /// @param p_v                  Vector to multiply
        /// @param p_f                  Scalar to multiply
        /// @return                     Vector product
        friend constexpr vector3 operator*(const vector3& p_v, const double p_f)
		{
			return vector3{ p_v.x * p_f, p_v.y * p_f, p_v.z * p_f };
		}

        /// Vector division operator
        /// @param p_v                  Vector to divide
        /// @param p_f                  Scalar to divide
        /// @return                     Vector quotient
        friend constexpr vector3 operator/(const vector3& p_v, const double p_f)
		{
			return vector3{ p_v.x / p_f, p_v.y / p_f, p_v.z / p_f };
		}

        /// Vector addition assignment operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Reference to updated first vector
        friend constexpr vector3& operator+=(vector3& p_a, const vector3& p_b)
		{
			p_a.x += p_b.x;
			p_a.y += p_b.y;
			p_a.z += p_b.z;
			return p_a;
		}

        /// Vector subtraction assignment operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Reference to updated first vector
        friend constexpr vector3& operator-=(vector3& p_a, const vector3& p_b)
		{
			p_a.x -= p_b.x;
			p_a.y -= p_b.y;
			p_a.z -= p_b.z;
			return p_a;
		}

        /// Vector multiplication assignment operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Reference to updated first vector
        friend constexpr vector3& operator*=(vector3& p_a, const vector3& p_b)
		{
			p_a.x *= p_b.x;
			p_a.y *= p_b.y;
			p_a.z *= p_b.z;
			return p_a;
		}

        /// Vector division assignment operator
        /// @param p_a                  First vector
        /// @param p_b                  Second vector
        /// @return                     Reference to updated first vector
        friend constexpr vector3& operator/=(vector3& p_a, const vector3& p_b)
		{
			p_a.x /= p_b.x;
			p_a.y /= p_b.y;
			p_a.z /= p_b.z;
			return p_a;
		}

        /// Vector multiplication assignment operator
        /// @param p_v                  Vector to multiply
        /// @param p_f                  Scalar to multiply
        /// @return                     Reference to updated vector
        friend constexpr vector3& operator*=(vector3& p_v, const double p_f)
		{
			p_v.x *= p_f;
			p_v.y *= p_f;
			p_v.z *= p_f;
			return p_v;
		}

        /// Vector division assignment operator
        /// @param p_v                  Vector to divide
        /// @param p_f                  Scalar to divide
        /// @return                     Reference to updated vector
        friend constexpr vector3& operator/=(vector3& p_v, const double p_f)
		{
			p_v.x /= p_f;
			p_v.y /= p_f;
			p_v.z /= p_f;
			return p_v;
		}
    };
}
