#include "CppUnitTest.h"
#include "mesh/mesh_vector2.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace mesh_tests
{
	TEST_CLASS(mesh_vector2)
	{
	public:
		TEST_METHOD(test_construct)
		{
			constexpr mesh::vector2 v1;
			Assert::AreEqual(0.0, v1.x);
			Assert::AreEqual(0.0, v1.y);

			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::AreEqual(1.0, v2.x);
			Assert::AreEqual(2.0, v2.y);
		}

		TEST_METHOD(test_length2)
		{
			constexpr mesh::vector2 v1;
			Assert::AreEqual(0.0, v1.length2());

			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::AreEqual(5.0, v2.length2());
		}

		TEST_METHOD(test_length)
		{
			constexpr mesh::vector2 v1;
			Assert::AreEqual(0.0, v1.length());

			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			Assert::AreEqual(5.0, v2.length());
		}

		TEST_METHOD(test_dot)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			Assert::AreEqual(11.0, v1.dot(v2));
		}

		TEST_METHOD(test_normalized)
		{
			constexpr mesh::vector2 v1;
			Assert::IsTrue(v1.normalized().is_equal_approx(v1));

			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 0.6, 0.8 };
			Assert::IsTrue(v2.normalized().is_equal_approx(v3));
		}

		TEST_METHOD(test_lerp)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 2.0, 3.0 };
			Assert::IsTrue(v1.lerp(v2, 0.5).is_equal_approx(v3));
		}

		TEST_METHOD(test_is_zero_approx)
		{
			constexpr mesh::vector2 v1;
			Assert::IsTrue(v1.is_zero_approx());

			constexpr mesh::vector2 v2{ 0.0, 0.0 };
			Assert::IsTrue(v2.is_zero_approx());

			constexpr mesh::vector2 v3{ 0.0, 1.0 };
			Assert::IsFalse(v3.is_zero_approx());
		}

		TEST_METHOD(test_is_equal_approx)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsTrue(v1.is_equal_approx(v2));

			constexpr mesh::vector2 v3{ 1.0, 2.0 };
			constexpr mesh::vector2 v4{ 1.0, 2.1 };
			Assert::IsFalse(v3.is_equal_approx(v4));
		}

		TEST_METHOD(test_operator_equals)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsTrue(v1 == v2);

			constexpr mesh::vector2 v3{ 1.0, 2.0 };
			constexpr mesh::vector2 v4{ 1.0, 2.1 };
			Assert::IsFalse(v3 == v4);
		}

		TEST_METHOD(test_operator_not_equals)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsFalse(v1 != v2);

			constexpr mesh::vector2 v3{ 1.0, 2.0 };
			constexpr mesh::vector2 v4{ 1.0, 2.1 };
			Assert::IsTrue(v3 != v4);
		}

		TEST_METHOD(test_operator_less_than)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsFalse(v1 < v2);

			constexpr mesh::vector2 v3{ 1.0, 2.0 };
			constexpr mesh::vector2 v4{ 1.0, 2.1 };
			Assert::IsTrue(v3 < v4);

			constexpr mesh::vector2 v5{ 1.0, 2.0 };
			constexpr mesh::vector2 v6{ 1.1, 2.0 };
			Assert::IsTrue(v5 < v6);
		}

		TEST_METHOD(test_operator_greater_than)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsFalse(v1 > v2);

			constexpr mesh::vector2 v3{ 1.0, 2.1 };
			constexpr mesh::vector2 v4{ 1.0, 2.0 };
			Assert::IsTrue(v3 > v4);

			constexpr mesh::vector2 v5{ 1.1, 2.0 };
			constexpr mesh::vector2 v6{ 1.0, 2.0 };
			Assert::IsTrue(v5 > v6);
		}

		TEST_METHOD(test_operator_less_than_or_equal)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsTrue(v1 <= v2);

			constexpr mesh::vector2 v3{ 1.0, 2.0 };
			constexpr mesh::vector2 v4{ 1.0, 2.1 };
			Assert::IsTrue(v3 <= v4);

			constexpr mesh::vector2 v5{ 1.0, 2.0 };
			constexpr mesh::vector2 v6{ 1.1, 2.0 };
			Assert::IsTrue(v5 <= v6);
		}

		TEST_METHOD(test_operator_greater_than_or_equal)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsTrue(v1 >= v2);

			constexpr mesh::vector2 v3{ 1.0, 2.1 };
			constexpr mesh::vector2 v4{ 1.0, 2.0 };
			Assert::IsTrue(v3 >= v4);

			constexpr mesh::vector2 v5{ 1.1, 2.0 };
			constexpr mesh::vector2 v6{ 1.0, 2.0 };
			Assert::IsTrue(v5 >= v6);
		}

		TEST_METHOD(test_operator_negation)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ -1.0, -2.0 };
			Assert::IsTrue((-v1).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_addition)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 4.0, 6.0 };
			Assert::IsTrue((v1 + v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_subtraction)
		{
			constexpr mesh::vector2 v1{ 3.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			constexpr mesh::vector2 v3{ 2.0, 2.0 };
			Assert::IsTrue((v1 - v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_multiplication)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 3.0, 8.0 };
			Assert::IsTrue((v1 * v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_division)
		{
			constexpr mesh::vector2 v1{ 3.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			constexpr mesh::vector2 v3{ 3.0, 2.0 };
			Assert::IsTrue((v1 / v2).is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_scalar_multiplication)
		{
			constexpr mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 2.0, 4.0 };
			Assert::IsTrue((v1 * 2.0).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_scalar_division)
		{
			constexpr mesh::vector2 v1{ 2.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			Assert::IsTrue((v1 / 2.0).is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_addition_assignment)
		{
			mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 4.0, 6.0 };
			v1 += v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_subtraction_assignment)
		{
			mesh::vector2 v1{ 3.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			constexpr mesh::vector2 v3{ 2.0, 2.0 };
			v1 -= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_multiplication_assignment)
		{
			mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 3.0, 4.0 };
			constexpr mesh::vector2 v3{ 3.0, 8.0 };
			v1 *= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_division_assignment)
		{
			mesh::vector2 v1{ 3.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			constexpr mesh::vector2 v3{ 3.0, 2.0 };
			v1 /= v2;
			Assert::IsTrue(v1.is_equal_approx(v3));
		}

		TEST_METHOD(test_operator_scalar_multiplication_assignment)
		{
			mesh::vector2 v1{ 1.0, 2.0 };
			constexpr mesh::vector2 v2{ 2.0, 4.0 };
			v1 *= 2.0;
			Assert::IsTrue(v1.is_equal_approx(v2));
		}

		TEST_METHOD(test_operator_scalar_division_assignment)
		{
			mesh::vector2 v1{ 2.0, 4.0 };
			constexpr mesh::vector2 v2{ 1.0, 2.0 };
			v1 /= 2.0;
			Assert::IsTrue(v1.is_equal_approx(v2));
		}
	};
}
