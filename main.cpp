
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "queue.h"

void teststqueue( )
{
	queue q1 = { 1, 2, 3, 4, 5 };
	queue q2 = q1; // Copy constructor.
	for( unsigned int j = 0; j < 30; ++ j )
	{
	q1. push( j * j );
	std::cout << q1. peek( ) << "\n";
	q1. pop( );
	}
	q1 = q2; // Assignment.
	q1 = q1; // Self assignment.
	q1 = { 100,101,102,103 };
	std::cout << q1 << "\n";
	queue q3 = { 1,2,3,4,5,6 };
	std::cout << q3 << "\n";
	for( unsigned int i = 0; i < 10000; ++ i )
	{
	q3. push(i); q3. checkinvariant( );
	double d = q3. peek( ); q3. checkinvariant( );
	q3. pop( ); q3. checkinvariant( );
	q3. push(d); q3. checkinvariant( );
	}
	// Try to show in your solution that you enjoy programming!
}

int main( int argc, char* argv [ ] )
{
   queue q;

   q. push(1); q. push(2); q. push(3);
   q. push(4); q. push(5); q. push(6);
   q. push(7); q. push(8);

   std::cout << q << "\n";
  
   while( q. size( ) > 3 )
   {
      double d = q. peek( );
      std::cout << d << "\n";
      q. pop( );
   }

   queue q2 = q;
   std::cout << q << "\n";

   std::cout << q2 << "\n";

   while( q. size( ) > 3 )
   {
      double d = q. peek( );
      std::cout << d << "\n";
      q. pop( );
   }
   q2 = q;
   std::cout << q << "\n";
   std::cout << q2 << "\n";

   queue q3 = { 1,2,3,4,5,6 };
   std::cout << q3 << "\n";

   for( unsigned int i = 0; i < 10000; ++ i )
   {
      q3. push(i); q3. checkinvariant( );
      double d = q3. peek( ); q3. checkinvariant( );
      q3. pop( ); q3. checkinvariant( );
      q3. push(d); q3. checkinvariant( );
   }
   teststqueue( );

      
   return 0;
}

