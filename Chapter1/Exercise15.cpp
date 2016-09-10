/*
//  Created by: Jacob Cassady
//  Date Created: 9/4/2016
//  Last Updated: 9/9/2016
*/

/*Problem Statement:
  Define a Rectangle class that provides getLength and getWidth.  using the findMax
  routines in figure 1.25, write a main that creates an array of Rectangle and finds
  the largest Rectangle first on the basis of area and then on the basis of perimeter.
*/

#include <iostream>
#include <vector>
#include <string>
#include <strings.h>
using namespace std;

/***************FIGURE 1.25 (GIVEN)***************/
// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object & findMax( const vector<Object> & arr, Comparator isLessThan )
{
    int maxIndex = 0;

    for( int i = 1; i < arr.size( ); ++i )
        if( isLessThan( arr[ maxIndex ], arr[ i ] ) )
            maxIndex = i;

    return arr[ maxIndex ];
}

// Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object & findMax( const vector<Object> & arr )
{
    return findMax( arr, less<Object>{ } );
}

class CaseInsensitiveCompare
{
  public:
    bool operator( )( const string & lhs, const string & rhs ) const
      { return strcasecmp( lhs.c_str( ), rhs.c_str( ) ) < 0; }
};
/***************FIGURE 1.25 (END)***************/



/***************BEGIN ORIGINAL CODE***************/
template <typename number>
class Rectangle{
	  public:
    //CONSTRUCTORS
    Rectangle(number s){
      width = s;
      length = s;
    }
    
    Rectangle(number l, number w){
      length = l;
      width = w;
    }
  
    //ACCESSOR METHODS
    number getLength() const{
      return length;
    }
    
    number getWidth() const{
      return width;
    }
    
    number getPerimeter() const{
      return ((2*length) + (2*width));
    }
    
    number getArea() const {
      return (length*width);
    }
    
    int compareArea(const Rectangle<number> r2) const{
    	if(this->getArea() < r2.getArea()){
    		return -1;
    	} else if (this->getArea() == r2.getArea()){
    		return 0;
    	} else {
    		return 1;
    	}
    }
    
    int comparePerimeter(const Rectangle<number> r2) const{
    	if(this->getPerimeter() < r2.getPerimeter()){
    		return -1;
    	} else if (this->getPerimeter() == r2.getPerimeter()){
    		return 0;
    	} else {
    		return 1;
    	}
    }

  private:
    number length;
    number width;
};

template <typename number>
number findMaxPerimeter(const vector<Rectangle<number>> & arr){
	number maxPerimeter = arr[0].getPerimeter();
	
	for(unsigned arr_i; arr_i< arr.size(); arr_i++){
		if(arr[arr_i].getPerimeter() > maxPerimeter){
			maxPerimeter = arr[arr_i].getPerimeter();
		}
	}
	
	return maxPerimeter;
}

template <typename number>
number findMaxArea(const vector<Rectangle<number>> & arr){
	number maxArea = arr[0].getArea();
	
	for(unsigned arr_i=0; arr_i < arr.size(); arr_i++){
		if(arr[arr_i].getArea() > maxArea){
			maxArea = arr[arr_i].getArea();
		}
	}
	
	return maxArea;
}

class AreaCompare{
	public:
		bool operator( )( const Rectangle<int> & r1, const Rectangle<int> & r2 ) const
		{ return r1.compareArea(r2) < 0; }
};

class PerimeterCompare{
	public:
		bool operator( )( const Rectangle<int> & r1, const Rectangle<int> & r2) const
		{ return r1.comparePerimeter(r2) < 0; }
};

int main( )
{
	vector<Rectangle<int>> arr;
	Rectangle<int> a(5,5);
	Rectangle<int> b(1,5);
	Rectangle<int> c(4,5);
	Rectangle<int> d(5,4);
	
	arr.push_back(b);
	arr.push_back(a);
	arr.push_back(c);
	arr.push_back(d);
	
	Rectangle<int> maxAreaR = findMax(arr, AreaCompare{ });
	Rectangle<int> maxPerimeterR = findMax(arr, PerimeterCompare{ });
	
	cout << "Max area of given vector of rectangles: " << maxAreaR.getArea() << endl;
	cout << "Max perimeter of given vector of rectangles: " << maxPerimeterR.getPerimeter() << endl;

    return 0;
}
