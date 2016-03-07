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

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}
TEST(FieldTest, placeboundaryexception1)
{
	Field minefield;
  bool r=false;

  try{
	minefield.placeMine(12,5);
}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}

TEST(FieldTest, placeboundaryexception2)
{
	Field minefield;
  bool r=false;

  try{
	minefield.placeMine(-1,5);
}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}

TEST(FieldTest, placeboundaryexception3)
{
	Field minefield;
  bool r=false;

  try{
	minefield.placeMine(2,-1);
}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}

TEST(FieldTest, placeboundaryexception4)
{
	Field minefield;
  bool r=false;

  try{
	minefield.placeMine(2,10);
}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}



TEST(FieldTest, issafeboundaryexception1)
{
	Field minefield;
  bool r=false;

  try{
	minefield.isSafe(-1,2);

}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}

TEST(FieldTest, issafeboundaryexception2)
{
	Field minefield;
  bool r=false;

  try{
	minefield.isSafe(11,2);

}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}

TEST(FieldTest, isSafetestwithunsafe)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( false, minefield.isSafe(4,5) );
}

TEST(FieldTest, isSafetestwithsafe)
{
	Field minefield;

	ASSERT_EQ( true, minefield.isSafe(0,3) );
}

TEST(FieldTest, revealtest)
{
	Field minefield;

	minefield.placeMine(4,5);
  minefield.revealAdjacent(4,5);
	ASSERT_EQ( MINE_SHOWN, minefield.get(4,5) );
}
TEST(FieldTest, revealadjtest)
{
	Field minefield;

	minefield.placeMine(4,5);
  minefield.revealAdjacent(4,5);
	ASSERT_EQ( MINE_SHOWN, minefield.get(4,5) );
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(4,6) );
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(5,5) );
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(4,4) );
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(3,5) );

}

TEST(FieldTest, revealboundaryexception1)
{
	Field minefield;
  bool r=false;

  try{
	minefield.revealAdjacent(2,10);

}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}
TEST(FieldTest, revealAdjacentboundaryexception1)
{
	Field minefield;
  bool r=false;

  try{
	minefield.revealAdjacent(2,9);

}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}
TEST(FieldTest, revealAdjacentboundaryexception2)
{
	Field minefield;
  bool r=false;

  try{
	minefield.revealAdjacent(1,0);

}
catch(const char * exp){
  if(strcmp(exp,"Out of bounds")==0){
    r=true;

  }

}
  ASSERT_TRUE( r);
}
