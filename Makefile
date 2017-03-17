lab7: main.o PrecondViolatedExcep.o LeftistNode.o LeftistHeap.o SkewHeap.o SkewNode.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o LeftistNode.o LeftistHeap.o SkewHeap.o SkewNode.o -o lab7

main.o: QNode.h QNode.hpp Queue.h Queue.hpp main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

LeftistNode.o: LeftistNode.h LeftistNode.cpp
	g++ -std=c++11 -g -Wall -c LeftistNode.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp
    
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -Wall -c LeftistHeap.cpp

SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -Wall -c SkewHeap.cpp

SkewNode.o: SkewNode.h SkewNode.cpp
	g++ -std=c++11 -g -Wall -c SkewNode.cpp

clean:
	rm *.o lab7
	echo clean done