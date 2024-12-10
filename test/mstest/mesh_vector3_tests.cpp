#include "CppUnitTest.h"
#include "mesh/mesh_vector3.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mesh;

namespace mesh_tests
{
	TEST_CLASS(mesh_vector3)
	{
	public:
		TEST_METHOD(test_construct)
		{
			constexpr vector3 v1;
			Assert::AreEqual(0.0, v1.x);
			Assert::AreEqual(0.0, v1.y);
			Assert::AreEqual(0.0, v1.z);

			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::AreEqual(1.0, v2.x);
			Assert::AreEqual(2.0, v2.y);
			Assert::AreEqual(3.0, v2.z);
		}

		TEST_METHOD(test_length2)
		{
			constexpr vector3 v1;
			Assert::AreEqual(0.0, v1.length2());

			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::AreEqual(14.0, v2.length2());
		}

		TEST_METHOD(test_length)
		{
			constexpr vector3 v1;
			Assert::AreEqual(0.0, v1.length());

			constexpr vector3 v2{ 3.0, 4.0, 12.0 };
			Assert::AreEqual(13.0, v2.length());
		}

		TEST_METHOD(test_dot)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			Assert::AreEqual(32.0, v1.dot(v2));
		}

		TEST_METHOD(test_cross)
		{
			constexpr vector3 v1{ 2.0, 0.0, 0.0 };
			constexpr vector3 v2{ 0.0, 3.0, 0.0 };
			constexpr vector3 v3{ 0.0, 0.0, 6.0 };
			Assert::IsTrue(v1.cross(v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_normalized)
		{
			constexpr vector3 v1;
			Assert::IsTrue(v1.normalized().is_zero_approx());

			constexpr vector3 v2{ 352.0, 360.0, 864.0 };
			constexpr vector3 v3{ 0.352, 0.360, 0.864 };
			Assert::IsTrue(v2.normalized().is_equal_approx(v3));
		}

		TEST_METHOD(test_lerp)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 2.5, 3.5, 4.5 };
			Assert::IsTrue(v1.lerp(v2, 0.5).is_equal_approx(v3));
		}

		TEST_METHOD(test_is_zero_approx)
		{
			constexpr vector3 v1;
			Assert::IsTrue(v1.is_zero_approx());

			constexpr vector3 v2{ 0.0, 0.0, 0.0 };
			Assert::IsTrue(v2.is_zero_approx());

			constexpr vector3 v3{ 0.00000000000000001, 0.00000000000000001, 0.00000000000000001 };
			Assert::IsTrue(v3.is_zero_approx());

			constexpr vector3 v4{ 0.1, 0.1, 0.1 };
			Assert::IsFalse(v4.is_zero_approx());
		}

		TEST_METHOD(test_is_equal_approx)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsTrue(v1.is_equal_approx(v2));

			constexpr vector3 v3{ 1.00000000000000001, 2.00000000000000001, 3.00000000000000001 };
			Assert::IsTrue(v1.is_equal_approx(v3));

			constexpr vector3 v4{ 1.1, 2.1, 3.1 };
			Assert::IsFalse(v1.is_equal_approx(v4));
		}

		TEST_METHOD(test_operator_equals)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsTrue(v1 == v2);

			constexpr vector3 v3{ 1.1, 2.1, 3.1 };
			Assert::IsFalse(v1 == v3);
		}

		TEST_METHOD(test_operator_not_equals)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsFalse(v1 != v2);

			constexpr vector3 v3{ 1.1, 2.1, 3.1 };
			Assert::IsTrue(v1 != v3);
		}

		TEST_METHOD(test_operator_less_than)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsFalse(v1 < v2);

			constexpr vector3 v3{ 1.0, 2.0, 4.0 };
			Assert::IsTrue(v1 < v3);

			constexpr vector3 v4{ 1.0, 3.0, 3.0 };
			Assert::IsTrue(v1 < v4);

			constexpr vector3 v5{ 2.0, 2.0, 3.0 };
			Assert::IsTrue(v1 < v5);
		}

		TEST_METHOD(test_operator_greater_than)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsFalse(v2 > v1);

			constexpr vector3 v3{ 1.0, 2.0, 4.0 };
			Assert::IsTrue(v3 > v1);

			constexpr vector3 v4{ 1.0, 3.0, 3.0 };
			Assert::IsTrue(v4 > v1);

			constexpr vector3 v5{ 2.0, 2.0, 3.0 };
			Assert::IsTrue(v5 > v1);
		}

		TEST_METHOD(test_operator_less_than_or_equals)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsTrue(v1 <= v2);

			constexpr vector3 v3{ 1.0, 2.0, 4.0 };
			Assert::IsTrue(v1 <= v3);

			constexpr vector3 v4{ 1.0, 3.0, 3.0 };
			Assert::IsTrue(v1 <= v4);

			constexpr vector3 v5{ 2.0, 2.0, 3.0 };
			Assert::IsTrue(v1 <= v5);
		}

		TEST_METHOD(test_operator_greater_than_or_equals)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 1.0, 2.0, 3.0 };
			Assert::IsTrue(v2 >= v1);

			constexpr vector3 v3{ 1.0, 2.0, 4.0 };
			Assert::IsTrue(v3 >= v1);

			constexpr vector3 v4{ 1.0, 3.0, 3.0 };
			Assert::IsTrue(v4 >= v1);

			constexpr vector3 v5{ 2.0, 2.0, 3.0 };
			Assert::IsTrue(v5 >= v1);
		}

		TEST_METHOD(test_operator_negation)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ -1.0, -2.0, -3.0 };
			Assert::IsTrue((-v1).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_addition)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 5.0, 7.0, 9.0 };
			Assert::IsTrue((v1 + v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_subtraction)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ -3.0, -3.0, -3.0 };
			Assert::IsTrue((v1 - v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_multiplication)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 4.0, 10.0, 18.0 };
			Assert::IsTrue((v1 * v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_division)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 0.25, 0.4, 0.5 };
			Assert::IsTrue((v1 / v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_scalar_multiplication)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr float f = 2.0;
			constexpr vector3 v2{ 2.0, 4.0, 6.0 };
			Assert::IsTrue((v1 * f).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_scalar_division)
		{
			constexpr vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr float f = 2.0;
			constexpr vector3 v2{ 0.5, 1.0, 1.5 };
			Assert::IsTrue((v1 / f).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_addition_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 5.0, 7.0, 9.0 };
			v1 += v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_subtraction_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ -3.0, -3.0, -3.0 };
			v1 -= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_multiplication_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 4.0, 10.0, 18.0 };
			v1 *= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_division_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr vector3 v2{ 4.0, 5.0, 6.0 };
			constexpr vector3 v3{ 0.25, 0.4, 0.5 };
			v1 /= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_scalar_multiplication_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr float f = 2.0;
			constexpr vector3 v2{ 2.0, 4.0, 6.0 };
			v1 *= f;
			Assert::IsTrue(v1.is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_scalar_division_assignment)
		{
			vector3 v1{ 1.0, 2.0, 3.0 };
			constexpr float f = 2.0;
			constexpr vector3 v2{ 0.5, 1.0, 1.5 };
			v1 /= f;
			Assert::IsTrue(v1.is_equal_approx(v2));
		}
	};
}
