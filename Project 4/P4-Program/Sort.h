//
// Data Structures and Algorithm Analysis in C++ (Fourth Edition), by Mark Allen Weiss.
//


#ifndef P4_PROGRAM_SORT_H
#define P4_PROGRAM_SORT_H


/**
 * Several sorting routines.
 * Arrays are rearranged with smallest item first.
 */

#include <vector>
#include <functional>
using namespace std;

/**
 * Simple insertion sort.
 */
template <typename Comparable>
vector<int> insertionSort( vector<Comparable> & a )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    for( int p = 1; p < a.size( ); ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        //
        // Increment READS.
        reads++;


        int j;
        // Increment READS.
        //
        reads++;
        for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ) {

            a[j] = std::move(a[j - 1]);
            //
            // Increment READS and WRITES.
            reads++;
            writes++;

        }

        a[ j ] = std::move( tmp );
        //
        // Increment WRITES.
        writes++;

    }

    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;
    reads_writes.push_back(reads);
    reads_writes.push_back(writes);

    return reads_writes;

}


/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
vector<int> insertionSort( vector<Comparable> & a, int left, int right )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        //
        // Increment WRITES.
        writes++;


        int j;

        for( j = p; j > left && tmp < a[ j - 1 ]; --j ) {
            //
            // Increment READS.
            reads++;

            a[j] = std::move(a[j - 1]);
            //
            // Increment READS and WRITES.
            reads++;
            writes += 2;

        }

        a[ j ] = std::move( tmp );
        //
        // Increment WRITES.
        writes++;

    }

    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;
    reads_writes.push_back(reads);
    reads_writes.push_back(writes);

    return reads_writes;

}



/**
 * Shellsort, using Shell's (poor) increments.
 */
template <typename Comparable>
vector<int> shellsort( vector<Comparable> & a )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;


    for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
        for( int i = gap; i < a.size( ); ++i )
        {
            Comparable tmp = std::move( a[ i ] );
            //
            // Increment READS.
            reads++;
            int j = i;

            // Increment READS.
            reads++;
            //
            for( ; j >= gap && tmp < a[ j - gap ]; j -= gap ) {

                a[j] = std::move(a[j - gap]);
                //
                // Increment READS and WRITES.
                reads++;
                writes++;

            }
            a[ j ] = std::move( tmp );
            //
            // Increment WRITES.
            writes++;
        }


    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;
    reads_writes.push_back(reads);
    reads_writes.push_back(writes);

    return reads_writes;

}


/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n, int &reads, int &writes )
{
    int child;
    Comparable tmp;

    // Increment READS.
    reads++;
    //
    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {

        child = leftChild( i );
        // Increment READS.
        reads += 2;
        //
        if( child != n - 1 && a[ child ] < a[ child + 1 ] ) {

            ++child;

        }

        // Increment READS.
        reads++;
        //
        if( tmp < a[ child ] ) {


            a[i] = std::move(a[child]);
            //
            // Increment READS and WRITES.
            reads++;
            writes++;

        }

        else {
            break;
        }
    }

    a[ i ] = std::move( tmp );
    //
    // Increment WRITES.
    writes++;

}


/**
 * Standard heapsort.
 */
template <typename Comparable>
vector<int> heapsort( vector<Comparable> & a )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;


    for( int i = a.size( ) / 2 - 1; i >= 0; --i ) { /* buildHeap */

        // Perform percDown and obtain READS and WRITES.
        percDown(a, i, a.size(), reads, writes);

    }

    for( int j = a.size( ) - 1; j > 0; --j )
    {
        std::swap( a[ 0 ], a[ j ] );               /* deleteMax */
        //
        // Increment READS and WRITES.
        reads += 2;
        writes += 2;

        // Perform percDown and obtain READS and WRITES.
        percDown( a, 0, j, reads, writes );

    }

    // Define collection of READS and WRITES statistics.
    // Define collection of READS and WRITES statistics.
    vector<int> reads_writes;

    reads_writes.push_back(reads);
    reads_writes.push_back(writes);

    return reads_writes;

}


/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a,
                vector<Comparable> & tmpArray, int left, int right )
{
    if( left < right )
    {
        int center = ( left + right ) / 2;
        mergeSort( a, tmpArray, left, center );
        mergeSort( a, tmpArray, center + 1, right );
        merge( a, tmpArray, left, center + 1, right );
    }
}

/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort( vector<Comparable> & a )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    vector<Comparable> tmpArray( a.size( ) );

    mergeSort( a, tmpArray, 0, a.size( ) - 1 );
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
            int leftPos, int rightPos, int rightEnd )
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while( leftPos <= leftEnd && rightPos <= rightEnd ) {
        if (a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
    }

    while( leftPos <= leftEnd )    // Copy rest of first half
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )  // Copy rest of right half
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // Copy tmpArray back
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}


/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;

    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

    // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
vector<int> quicksort( vector<Comparable> & a, int left, int right, int &reads, int &writes )
{


    if( left + 10 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

        // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            //
            // Increment READS
            reads++;

            while( pivot < a[ --j ] ) { }
            //
            // Increment READS.
            reads++;

            if( i < j ) {
                std::swap(a[i], a[j]);
                //
                // Increment READS and WRITES.
                reads += 2;
                writes += 2;

            }
            else {

                break;

            }
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot
        //
        // Increment READS and WRITES.
        reads += 2;
        writes += 2;


        quicksort( a, left, i - 1, reads, writes );     // Sort small elements
        quicksort( a, i + 1, right, reads, writes );    // Sort large elements


        // Define collection of READS and WRITES statistics.
        vector<int> reads_writes;

        // Define collection of READS and WRITES statistics.
        reads_writes.push_back(reads);
        reads_writes.push_back(writes);

        return reads_writes;

    }
    else {

        // Do an insertion sort on the subarray
        return insertionSort(a, left, right);

    }

}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
vector<int> quicksort( vector<Comparable> & a )
{

    // Define counters for READS and WRITES.
    int reads = 0;
    int writes = 0;

    return quicksort( a, 0, a.size( ) - 1 , reads, writes);
}


/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect( vector<Comparable> & a, int left, int right, int k )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

        // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        // Recurse; only this part changes
        if( k <= i )
            quickSelect( a, left, i - 1, k );
        else if( k > i + 1 )
            quickSelect( a, i + 1, right, k );
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
}

/**
 * Quick selection algorithm.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * k is the desired rank (1 is minimum) in the entire array.
 */
template <typename Comparable>
void quickSelect( vector<Comparable> & a, int k )
{
    quickSelect( a, 0, a.size( ) - 1, k );
}


template <typename Comparable>
void SORT( vector<Comparable> & items )
{
    if( items.size( ) > 1 )
    {
        vector<Comparable> smaller;
        vector<Comparable> same;
        vector<Comparable> larger;

        auto chosenItem = items[ items.size( ) / 2 ];

        for( auto & i : items )
        {
            if( i < chosenItem )
                smaller.push_back( std::move( i ) );
            else if( chosenItem < i )
                larger.push_back( std::move( i ) );
            else
                same.push_back( std::move( i ) );
        }

        SORT( smaller );     // Recursive call!
        SORT( larger );      // Recursive call!

        std::move( begin( smaller ), end( smaller ), begin( items ) );
        std::move( begin( same ), end( same ), begin( items ) + smaller.size( ) );
        std::move( begin( larger ), end( larger ), end( items ) - larger.size( ) );

/*
        items.clear( );
        items.insert( end( items ), begin( smaller ), end( smaller ) );
        items.insert( end( items ), begin( same ), end( same ) );
        items.insert( end( items ), begin( larger ), end( larger ) );
*/
    }
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object.
 */
template <typename RandomIterator, typename Comparator>
void insertionSort( const RandomIterator & begin,
                    const RandomIterator & end,
                    Comparator lessThan )
{
    if( begin == end )
        return;

    RandomIterator j;

    for( RandomIterator p = begin+1; p != end; ++p )
    {
        auto tmp = std::move( *p );
        for( j = p; j != begin && lessThan( tmp, *( j-1 ) ); --j )
            *j = std::move( *(j-1) );
        *j = std::move( tmp );
    }
}

/*
 * The two-parameter version calls the three parameter version, using C++11 decltype
 */
template <typename RandomIterator>
void insertionSort( const RandomIterator & begin,
                    const RandomIterator & end )
{
    insertionSort( begin, end, less<decltype(*begin )>{ } );
}



#endif //P4_PROGRAM_SORT_H
