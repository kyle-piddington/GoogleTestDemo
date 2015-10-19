#include "gtest/gtest.h"
#include "Adders/Adder.h"

TEST(Adder, testWithoutFixture)
{
   Adder adder(5);
   EXPECT_EQ(adder.getValue(), 5);
   EXPECT_EQ(adder.addTo(5), 10);
   EXPECT_EQ(adder.getValue(), 10);
}


/**
 * Demonstration of a test fixture. Setup, teardown, and initialization code can go in here. (Think of this like a JUnit class)
 */
class AdderTest : public ::testing::Test {
protected:
   // You can remove any or all of the following functions if its body
   // is empty.
   AdderTest():
   adder(0)
   {

      // You can do set-up work for each test here.
   }

   virtual ~AdderTest() {
      // You can do clean-up work that doesn't throw exceptions here.
   }

   // If the constructor and destructor are not enough for setting up
   // and cleaning up each test, you can define the following methods:
   virtual void SetUp() {
      // Code here will be called immediately after the constructor (right
      // before each test).
   }

   virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
   }

   // Objects declared here can be used by all tests in the test case for Project1.
   Adder adder;
};

TEST_F(AdderTest, testAddValueToAdder)
{
   EXPECT_EQ(adder.addTo(5),5);
}


TEST_F(AdderTest, testGetInitialValue)
{
   EXPECT_EQ(adder.getValue(),0);
}

