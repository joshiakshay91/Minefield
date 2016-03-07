/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};
//all ready provided test
TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

//when expecting a mine so False
TEST(FieldTest, placeMineBOOM)
{
	Field minefield;
	minefield.placeMine(4,5);  //expecting a mine over here
	ASSERT_FALSE(minefield.isSafe(4,5));
}

//when expecting no mine so true
TEST(FieldTest, placeMineNOBOOM)
{
	Field minefield;
	minefield.placeMine(4,5); //expecting return of true bool
	ASSERT_TRUE(minefield.isSafe(5,5));
}

//when x is positively out of bound for isSafe i.e x>9
TEST(FieldTest, outBoundSafeX)
{
	bool flag=false;
	Field minefield;

	minefield.placeMine(4,5);
	try{
		minefield.isSafe(99,5); //parameters passed are out of bound
	}catch(...) //expecting a throw from function
	{
		flag=true;
	}
	ASSERT_TRUE(flag);

}
