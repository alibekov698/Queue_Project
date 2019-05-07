
#ifndef QUEUE_INCLUDED
#define QUEUE_INCLUDED  1

#include <iostream>
#include <initializer_list>

struct queue
{
    size_t current_size;
    size_t current_capacity;
    size_t begin;
    size_t end;

    double* data;
        // INVARIANТ: I wrote a function checkinvariant( ) const
        // which checks the invariant as much as possible. Use this
        // function in your tests.

    void ensure_capacity( size_t c );
        // Ensure that queue has capacity of at least c.
        // This function is given, so you don't have to write it.

    // Return i+1, but 0 if we reach current_capacity.

    size_t next( size_t i ) const
    {
        i = i + 1;
        if( i == current_capacity )
            i = 0;
        return i;
    }

    void checkinvariant( ) const;
        // Call this function often during your tests. We will
        // call it during checking!

    void printfields( std::ostream& ) const;
        // Print the fields current_size, current_capacity,
        // begin, end. It should be used for debugging.

public:
   queue( )
    // Constructs empty queue.
        : current_size{0},
          current_capacity{10},
          begin{0},
          end{0},
          data{ new double[current_capacity] }
    { }

    queue( const queue& q )
        : current_size{ q. current_size },
          current_capacity{ q. current_capacity},
          begin {q. begin},
          end {q. end},
          data{ new double[current_capacity] }
    {
        for( size_t i = 0; i < current_capacity; i++ )
            data[i] = q.data[i];
    }

    ~queue( )
    {

        delete[] data;
    }

    const queue& operator = ( const queue& q )
    {
        ensure_capacity(q.current_size);
        end = q.current_size;
        begin = 0;
        current_size = q.current_size;
        size_t p = q.begin;

        for(size_t i = 0 ; i < current_size; ++i)
        {
            data[i] = q.data[p];
            p = next(p);
        }
    }

    queue( std::initializer_list<double> init )
    {
        current_size = init.size();
        current_capacity = current_size * 2;
        data = new double[current_capacity];
        end = current_size;
        begin = 0;
        size_t i = 0;

        for (double d : init)
        {
            data[i] = d;
            ++i;
        }
    }

    void push( double d )
    {
        ensure_capacity(current_size + 1);
        current_size ++;

        data[end] = d;
        end = next(end);
    }

    void pop( )
    {
        if(current_size != 0)
        {
            begin = next(begin);
            current_size--;
        }
    }

    void clear( )
    {
       current_size = 0;
       begin = 0;
       end = 0;
    }

    double peek( ) const
    {
        return data[begin];
    }

    size_t size( ) const
    {
        return current_size;
    }

    bool empty( ) const {
        return current_size == 0;
    }

    friend std::ostream& operator << ( std::ostream& , const queue& );
};

    std::ostream& operator << ( std::ostream& , const queue& );

#endif


