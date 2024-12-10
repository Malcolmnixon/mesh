#include "CppUnitTest.h"
#include "mesh/mesh_math.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mesh;

namespace mesh_tests
{
	TEST_CLASS(mesh_math)
	{
	public:
		TEST_METHOD(test_cabs)
		{
			Assert::AreEqual(0.0, cabs(0.0));
			Assert::AreEqual(0.0, cabs(-0.0));
			Assert::AreEqual(0.001, cabs(0.001));
			Assert::AreEqual(0.001, cabs(-0.001));
		}

		TEST_METHOD(test_is_zero_approx)
		{
			Assert::IsTrue(is_zero_approx(0.0));
			Assert::IsFalse(is_zero_approx(-0.001));
			Assert::IsFalse(is_zero_approx(0.001));
		}

		TEST_METHOD(test_is_equal_approx)
		{
			Assert::IsTrue(is_equal_approx(0.0, 0.0));
			Assert::IsTrue(is_equal_approx(10.0, 10.0));
			Assert::IsTrue(is_equal_approx(-10.0, -10.0));
			Assert::IsFalse(is_equal_approx(0.0, 0.001));
		}

		TEST_METHOD(test_get_sign)
		{
			Assert::AreEqual(0, get_sign(0.0));
			Assert::AreEqual(1, get_sign(0.001));
			Assert::AreEqual(-1, get_sign(-0.001));
		}

		TEST_METHOD(test_lerp)
		{
			Assert::AreEqual(0.0, lerp(0.0, 0.0, 0.0));
			Assert::AreEqual(0.0, lerp(0.0, 0.0, 1.0));
			Assert::AreEqual(0.0, lerp(0.0, 0.0, 0.5));
			Assert::AreEqual(0.0, lerp(0.0, 10.0, 0.0));
			Assert::AreEqual(10.0, lerp(0.0, 10.0, 1.0));
			Assert::AreEqual(5.0, lerp(0.0, 10.0, 0.5));
		}
	};
}
