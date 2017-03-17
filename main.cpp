#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "LeftistHeap.h"
#include "SkewHeap.h"

class Timer
{
private:

    timeval startTime;
    timeval endTime;

public:

    void start()
    {
        gettimeofday( &startTime, NULL );
    }

    double stop()
    {
        long seconds, nseconds;
        double duration;

        gettimeofday( &endTime, NULL );

        seconds = endTime.tv_sec - startTime.tv_sec;
        nseconds = endTime.tv_usec - startTime.tv_usec;

        duration = seconds + nseconds / 1000000.0;

        return duration;
    }

    void printTime(double duration)
    {
        printf( "%5.6f seconds\n", duration );
    }
};

int main()
{
    Timer myTimer;
    double leftistHeapBuildDuration[20];
    double skewHeapBuildDuration[20];
    double leftistHeapOperationsDuration[20] = { };
    double skewHeapOperationsDuration[20] = { };
    double x;

    long nValues[] = { 50000, 100000, 200000, 400000 };

    for( unsigned int i = 0; i < 4; i++ )
    {
        long n = nValues[i];


        std::cout << "Start loop " << i << " with n: " << n << " ----------------------" << std::endl;
        for( int j = 0; j < 5; j++ )
        {
            srand( j );
            int currentDurationIndex = i * 5 + j;
            long* testArray = new long[n];

            for( long k = 0; k < n; k++ )
            {
                testArray[k] = ( rand() % ( 4 * n ) ) + 1;
            }

            myTimer.start();
            LeftistHeap leftistHeap;
            for( long k = 0; k < n; k++ )
            {
                leftistHeap.insert( testArray[k] );
            }
            leftistHeapBuildDuration[currentDurationIndex] = myTimer.stop();

            myTimer.start();
            SkewHeap skewHeap;
            for( long k = 0; k < n; k++ )
            {
                skewHeap.insert( testArray[k] );
            }
            skewHeapBuildDuration[currentDurationIndex] = myTimer.stop();

            for( long z = 0; z < ( 0.1 * n ); z++ )
            {
                x = rand() / (double) RAND_MAX;

                if( x >= 0 && x < 0.5 )
                {
                    myTimer.start();
                    leftistHeap.deleteMin();
                    leftistHeapOperationsDuration[currentDurationIndex] += myTimer.stop();

                    myTimer.start();
                    skewHeap.deleteMin();
                    skewHeapOperationsDuration[currentDurationIndex] += myTimer.stop();
                }
                else
                {
                    long valueToInsert = ( rand() % ( 4 * n ) ) + 1;

                    myTimer.start();
                    leftistHeap.insert( valueToInsert );
                    leftistHeapOperationsDuration[currentDurationIndex] += myTimer.stop();

                    myTimer.start();
                    skewHeap.insert( valueToInsert );
                    skewHeapOperationsDuration[currentDurationIndex] += myTimer.stop();
                }
            }
            std::cout << "\tFor seed " << j << " we have the following durations:\n";
            std::cout << "\t\tLeftist Heap Build Duration: " << leftistHeapBuildDuration[currentDurationIndex] << std::endl;
            std::cout << "\t\tSkew Heap Build Duration: " << skewHeapBuildDuration[currentDurationIndex] << std::endl;
            std::cout << std::endl;
            std::cout << "\t\tLeftist Heap Operations Duration: " << leftistHeapOperationsDuration[currentDurationIndex] << std::endl;
            std::cout << "\t\tSkew Heap Operations Duration: " << skewHeapOperationsDuration[currentDurationIndex] << std::endl;
            std::cout << std::endl;
            delete[] testArray;
        }

        std::cout << std::endl;
    }

    for( int i = 0; i < 4; i++ )
    {
        double leftistHeapBuildSum = 0;
        double skewHeapBuildSum = 0;
        double leftistHeapOperationsSum = 0;
        double skewHeapOperationsSum = 0;

        for( int j = 0; j < 5; j++ )
        {
            int currentDurationIndex = i * 5 + j;

            leftistHeapBuildSum += leftistHeapBuildDuration[currentDurationIndex];
            skewHeapBuildSum += skewHeapBuildDuration[currentDurationIndex];
            leftistHeapOperationsSum += leftistHeapOperationsDuration[currentDurationIndex];
            skewHeapOperationsSum += skewHeapOperationsDuration[currentDurationIndex];
        }

        std::cout << "For n = " << nValues[i] << ":" << std::endl;
        std::cout << "\tLeftist Heap Build Average is: " << ( leftistHeapBuildSum / 5 ) << "s" << std::endl;
        std::cout << "\tSkew Heap Build Average is: " << ( skewHeapBuildSum / 5 ) << "s" << std::endl;
        std::cout << "\tLeftist Heap Operations Average is: " << ( leftistHeapOperationsSum / 5 ) << "s"
                << std::endl;
        std::cout << "\tSkew Heap Operations Average is: " << ( skewHeapOperationsSum / 5 ) << "s"
                << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

