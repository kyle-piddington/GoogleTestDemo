#include "gtest/gtest.h"
#include "foo.h"

TEST(TestFoo, testFooSuccess)
{
   Foo foo;
   EXPECT_EQ(foo.bar(5),10);
   EXPECT_EQ(foo.bar(-5),-10);
}
TEST(TestFoo, testFooFailure)
{
   Foo foo;
   EXPECT_EQ(foo.bar(5),5);
}

