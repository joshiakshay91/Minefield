#include "Field.h"
#include <iostream>
#include <vector>

/**
 * Constructor creates a 10x10 grid with no mines
**/
 Field::Field()
 {
 	_map.resize(FIELD_DIMENSION);
 	for(unsigned int i=0; i < _map.size(); i++)
 	{
 		_map[i].resize(FIELD_DIMENSION);
 		for(unsigned int j=0; j < _map[i].size(); j++)
 		{
 			_map[i][j] = EMPTY_HIDDEN;
 		}
 	}
 }

 /**
  * Places a mine at the x,y coordinate in the field
 **/
 void Field::placeMine(int x, int y)
 {
 	if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
 		throw "Out of bounds";
 	}
 	else
 		_map[x][y] = MINE_HIDDEN;
 }

/**
 * Retrieves the state of the field at location (x,y)
**/
FieldType Field::get(int x, int y)
{
	if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
 		throw "Out of bounds";
 	}
 	else
 		return _map[x][y];
}

/**
 * Returns whether or not _map at (x,y) has a mine and throws an
 * exception if the location is illegal
**/
 bool Field::isSafe(int x, int y)
 {
 	//T Complete this function, isSafe(int,int)
  if(x<0||x>=FIELD_DIMENSION||y<0||y>=FIELD_DIMENSION)
    {
      throw "location illegal";
    }
    else
    {
      if(_map[x][y] == MINE_HIDDEN) //checks for mine
      {
        return false; //mine present
      }
    }
   	  return true;
 }

/**
 * Changes the location from EMPTY_HIDDEN to EMPTY_SHOWN for the
 * location and any valid locations adjacent (immediately above,
 * below, left, or right as printed) to the provided (x,y) location
**/
void Field::revealAdjacent(int x, int y)
{
  if(x < 0 || x >= FIELD_DIMENSION || y < 0 || y >= FIELD_DIMENSION)
 	{
  	throw "tried revealing Out of bounds";
 	}
  else
  {
    if((y-1)>=0)// to check that it is not on
    {                           //left most colomn
      if(_map[x][y-1] == EMPTY_HIDDEN)
      {
        _map[x][y-1] = EMPTY_SHOWN;
      }
    }
    if((y+1)<FIELD_DIMENSION) //not leaving upper bounds
    {
      if(_map[x][y+1] == EMPTY_HIDDEN)
      {
        _map[x][y+1] = EMPTY_SHOWN;
      }
    }
    if((x+1)<FIELD_DIMENSION) //not leaving upper bounds
    {
      if(_map[x+1][y] == EMPTY_HIDDEN)
      {
        _map[x+1][y] = EMPTY_SHOWN;
      }
    }
    if((x-1)>=0) //to check that it is not on
    {                           //first row
      if(_map[x-1][y] == EMPTY_HIDDEN)
      {
        _map[x-1][y] = EMPTY_SHOWN;
      }
    }
  }
}
