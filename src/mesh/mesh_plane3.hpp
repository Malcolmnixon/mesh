#pragma once

#include "mesh_vector3.hpp"

namespace mesh
{
    /// 3D Plane
    struct plane3
    {
        /// Plane normal vector
        vector3 normal;

        /// Plane distance from origin
        double distance = 0.0;

        /// Default constructor
        plane3() = default;

        /// Construct a plane from a normal and a distance from origin
        /// @param p_normal             Plane normal vector
        /// @param p_distance           Plane distance from origin
		constexpr explicit plane3(const vector3& p_normal, const double p_distance)
    		: normal(p_normal), distance(p_distance)
		{
		}

        /// Construct a plane from a normal and a point on the plane
        /// @param p_normal             Plane normal vector
        /// @param p_point              Point on the plane
        constexpr explicit plane3(const vector3& p_normal, const vector3& p_point)
			: normal(p_normal), distance(p_normal.dot(p_point))
		{
		}

        /// Construct a plane from three points
        /// @param p_point1             First point
        /// @param p_point2             Second point
        /// @param p_point3             Third point
        explicit plane3(const vector3& p_point1, const vector3& p_point2, const vector3& p_point3)
		{
            normal = (p_point2 - p_point1).cross(p_point3 - p_point1).normalized();
            distance = normal.dot(p_point1);
        }

        /// Check if plane is approximately equal to another plane
        /// @param p_p                  Plane to compare with
        /// @return                     True if equal
        constexpr bool is_equal_approx(const plane3& p_p) const
		{
            return normal.is_equal_approx(p_p.normal) &&
                mesh::is_equal_approx(distance, p_p.distance);
		}

        /// Calculate distance from plane to point
        /// @param p_point              Point to calculate distance to
        /// @return                     Distance to point
        constexpr double distance_to(const vector3& p_point) const
		{
            return normal.dot(p_point) - distance;
        }

        /// Calculate which side of the plane a point is on
        /// @param p_point              Point to test
        /// @return                     -1 if behind, 0 if on, 1 if in front
        constexpr int side(const vector3& p_point) const
		{
            return get_sign(distance_to(p_point));
        }

        /// Project a point onto the plane
        /// @param p_point              Point to project
        /// @return                     Projected point
        constexpr vector3 project(const vector3& p_point) const
		{
            return p_point - normal * distance_to(p_point);
        }

        /// Intersect ray with plane
        /// @param p_origin             Ray origin
        /// @param p_direction          Ray direction
        /// @param p_point              Optional intersection point
        /// @return                     True if intersection
        constexpr bool intersect_ray(const vector3& p_origin, const vector3& p_direction, vector3* p_point = nullptr) const
		{
            // Calculate the denominator
            const double den = normal.dot(p_direction);
            if (is_zero_approx(den))
                return false;

            // Calculate the distance along the ray to the intersection point
            const double dist = (distance - normal.dot(p_origin)) / den;
            if (dist < std::numeric_limits<double>::epsilon())
                return false;

            // Save the optional intersection point
            if (p_point)
                *p_point = p_origin + p_direction * dist;

            return true;
        }

        /// Intersect segment with plane
        /// @param p_point1             Segment start point
        /// @param p_point2             Segment end point
        /// @param p_point              Optional intersection point
        /// @return                     True if intersection
        constexpr bool intersect_segment(const vector3& p_point1, const vector3& p_point2, vector3* p_point = nullptr) const
		{
            // Calculate the distance from the segment points to the plane
            const double dist1 = distance_to(p_point1);
            const double dist2 = distance_to(p_point2);

            // If the points are on the same side of the plane then there is no intersection
            if (get_sign(dist1) == get_sign(dist2))
            {
                return false;
            }

            // Save the optional the intersection point
            if (p_point)
            {
                const double t = dist1 / (dist1 - dist2);
                *p_point = p_point1.lerp(p_point2, t);
            }

            return true;
        }

        /// Plane equality operator
        /// @param p_a                  First plane to compare
        /// @param p_b                  Second plane to compare
        /// @return                     True if equal
        friend constexpr bool operator==(const plane3 &p_a, const plane3& p_b)
        {
            return p_a.normal == p_b.normal && p_a.distance == p_b.distance;
        }

        /// Plane inequality operator
        /// @param p_a                  First plane to compare
        /// @param p_b                  Second plane to compare
        /// @return                     True if not equal
        friend constexpr bool operator!=(const plane3& p_a, const plane3& p_b)
        {
            return p_a.normal != p_b.normal || p_a.distance != p_b.distance;
        }
    };
}
