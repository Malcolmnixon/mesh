#include "CppUnitTest.h"
#include "mesh/mesh_plane3.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mesh;

namespace mesh_tests
{
	TEST_CLASS(mesh_plane3)
	{
	public:
		TEST_METHOD(test_construct)
		{
			constexpr plane3 p1;
			Assert::IsTrue(p1.normal.is_zero_approx());
			Assert::AreEqual(0.0, p1.distance);

			constexpr plane3 p2{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			Assert::IsTrue(p2.normal.is_equal_approx(vector3{ 0.0, 1.0, 0.0 }));
			Assert::AreEqual(1.0, p2.distance);

			constexpr plane3 p3{ vector3{ 0.0, 1.0, 0.0 }, vector3{ 0.0, 1.0, 0.0 } };
			Assert::IsTrue(p3.normal.is_equal_approx(vector3{ 0.0, 1.0, 0.0 }));
			Assert::AreEqual(1.0, p3.distance);

			const plane3 p4{ vector3{ 0.0, 1.0, 0.0 }, vector3{ 0.0, 1.0, 1.0 }, vector3{ 1.0, 1.0, 0.0 } };
			Assert::IsTrue(p4.normal.is_equal_approx(vector3{ 0.0, 1.0, 0.0 }));
			Assert::AreEqual(1.0, p4.distance);
		}

		TEST_METHOD(test_is_equal_approx)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			constexpr plane3 p2{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			Assert::IsTrue(p1.is_equal_approx(p2));

			constexpr plane3 p3{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			constexpr plane3 p4{ vector3{ 0.0, 1.0, 0.0 }, 1.1 };
			Assert::IsFalse(p3.is_equal_approx(p4));
		}

		TEST_METHOD(test_distance_to)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			constexpr vector3 v1{ 0.0, 2.0, 0.0 };
			Assert::AreEqual(1.0, p1.distance_to(v1));

			constexpr plane3 p2{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			constexpr vector3 v2{ 0.0, 0.0, 0.0 };
			Assert::AreEqual(-1.0, p2.distance_to(v2));
		}

		TEST_METHOD(test_side)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };

			constexpr vector3 v1{ 0.0, 2.0, 0.0 };
			Assert::AreEqual(1, p1.side(v1));

			constexpr vector3 v2{ 0.0, 0.0, 0.0 };
			Assert::AreEqual(-1, p1.side(v2));

			constexpr vector3 v3{ 0.0, 1.0, 0.0 };
			Assert::AreEqual(0, p1.side(v3));
		}

		TEST_METHOD(test_project)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };
			constexpr vector3 v1{ 3.0, 2.0, 4.0 };
			constexpr vector3 v2{ 3.0, 1.0, 4.0 };
			Assert::IsTrue(p1.project(v1).is_equal_approx(v2));
		}

		TEST_METHOD(test_intersect_ray)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };

			constexpr vector3 o1{ 0.0, 0.0, 0.0 };
			constexpr vector3 d1{ 0.0, 1.0, 0.0 };
			vector3 i1;
			Assert::IsTrue(p1.intersect_ray(o1, d1, &i1));
			Assert::IsTrue(i1.is_equal_approx(vector3{ 0.0, 1.0, 0.0 }));

			constexpr vector3 o2{ 0.0, 0.0, 0.0 };
			constexpr vector3 d2{ 0.0, -1.0, 0.0 };
			vector3 i2;
			Assert::IsFalse(p1.intersect_ray(o2, d2, &i2));
		}

		TEST_METHOD(test_intersect_segment)
		{
			constexpr plane3 p1{ vector3{ 0.0, 1.0, 0.0 }, 1.0 };

			constexpr vector3 o1{ 0.0, 0.0, 0.0 };
			constexpr vector3 d1{ 1.0, 2.0, 4.0 };
			vector3 i1;
			Assert::IsTrue(p1.intersect_segment(o1, d1, &i1));
			Assert::IsTrue(i1.is_equal_approx(vector3{ 0.5f, 1.0, 2.0 }));

			constexpr vector3 o2{ 0.0, 0.0, 0.0 };
			constexpr vector3 d2{ 0.0, -1.0, 0.0 };
			vector3 i2;
			Assert::IsFalse(p1.intersect_segment(o2, d2, &i2));
		}
	};
}
