#include "pch.h"
#include "CppUnitTest.h"
#include "../DogAdoptionCenter/Test.h"
#include "../DogAdoptionCenter/Service.h"
#include "../DogAdoptionCenter/Console.h"
#include "../DogAdoptionCenter/Repository.h"
#include "../DogAdoptionCenter/Dog.h"
#include "../DogAdoptionCenter/DynamicVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DogAdoptionCenterTest
{
	TEST_CLASS(DogAdoptionCenterTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Test t;
			t.run_tests();
		}
	};
}
