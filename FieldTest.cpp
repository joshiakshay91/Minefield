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

//when x is positively out of bound for isSafe i.e x>9 condi
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

//when x is -vely out of bound for isSafe i.e x<0 condi
TEST(FieldTest, outBoundNegX)
{
	bool flag=false;
	Field minefield;
	minefield.placeMine(4,5);
	try{
		minefield.isSafe(-9,5); //passing a negative value
	}catch(...)//expecting a throw from function
	{
		flag=true;
	}
	ASSERT_TRUE(flag);
}

//when y is positively out of bound for isSafe i.e y>9 condi
TEST(FieldTest, outBoundSafeY)
{
	bool flag=false;
	Field minefield;
	minefield.placeMine(4,5);
	try{
		minefield.isSafe(4,99);//parameters passed are out of bound
	}catch(...)//expecting a throw from function
	{
		flag=true;
	}
	ASSERT_TRUE(flag);
}

//when y is -vely out of bound for isSafe i.e y<0 condi
TEST(FieldTest, outBoundNegY)
{
	bool flag=false;
	Field minefield;
	minefield.placeMine(4,5);
	try{
		minefield.isSafe(4,-9);//passing a negative value
	}catch(...)//expecting a throw from function
	{
		flag=true;
	}
	ASSERT_TRUE(flag);
}


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

TEST(FieldTest, SidesXup)
{
  Field minefield; //default const everything to be EMPTY_HIDDEN
  minefield.revealAdjacent(4,4);
  ASSERT_EQ(EMPTY_SHOWN,minefield.get(3,4));
}
