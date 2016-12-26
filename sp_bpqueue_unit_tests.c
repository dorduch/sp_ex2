#include "../SPBPriorityQueue.h"
#include "unit_test_util.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//Checks Enqueue Dequeue with bounded number of elements
bool Enqueue_Dequeue_Check() {
	//Generate random size for SPBPQueue
	srand(time(NULL));
	int sizeofqueue = rand()%100;

	//Create an empty queue
	SPBPQueue* QueueTest = spBPQueueCreate(sizeofqueue);

	//Adds elements until full capacity, saves lowest & highest values
	int index = rand()%1000;
	double value =(double)(rand()%1000);
	int max = value;
	int min = value;
	for (int i = 0; i < sizeofqueue; i++) {
		spBPQueueEnqueue(QueueTest,index,value);
		if (value > max) {
			max = value;
		}
		if (value < min) {
			min = value;
		}
		index = rand()%1000;
		value =(double)(rand()%1000);
	}

	//Assert Min Max queue are Min Max values
	ASSERT_TRUE(spBPQueueMinValue(QueueTest) == min);
	ASSERT_TRUE(spBPQueueMaxValue(QueueTest) == max);

	//Dequeue all elements
	//Each one has to have higher value than his prev
	//Each one has to be lower than max and higher than min
	BPQueueElement* res = (BPQueueElement*)malloc(sizeof(res));
	SP_BPQUEUE_MSG Deq = spBPQueuePeek(QueueTest,res);
	int prevValue = res->value;
	SP_BPQUEUE_MSG Deq2 = spBPQueueDequeue(QueueTest);
	while (Deq2 == SP_BPQUEUE_SUCCESS) {
		Deq = spBPQueuePeek(QueueTest,res);
		ASSERT_TRUE(res->value >= prevValue);
		ASSERT_TRUE(res->value <= max);
		ASSERT_TRUE(res->value >= min);
		prevValue = res->value;
		Deq2 = spBPQueueDequeue(QueueTest);

	}

	//Enqueue and Dequeue randomly
	int howManyLoops = rand()%50;
	for (int i = 0; i < howManyLoops; i++){

		//clear with prob 0.5 (must happened at least once in expected
		if ((rand()%10)%2==0){
			spBPQueueIsEmpty(QueueTest);
		}

		//Adding Elements
		int howManyAdds = rand()%20;
		for (int j = 0; j < howManyAdds; j++){
			spBPQueueEnqueue(QueueTest,rand()%100,(double)(rand()%1000));
		}


		//Delete Elements
		int howManyRemoves = rand()%4;
		for (int j = 0; j < howManyAdds; j++){
			spBPQueueDequeue(QueueTest);
		}
	}

	//Check queque while not empty
	if (!spBPQueueIsEmpty(QueueTest)){
		SP_BPQUEUE_MSG Deq = spBPQueuePeek(QueueTest,res);
		int prevValue = res->value;
		SP_BPQUEUE_MSG Deq2 = spBPQueueDequeue(QueueTest);
		while (Deq2 == SP_BPQUEUE_SUCCESS) {
			Deq = spBPQueuePeek(QueueTest,res);
			ASSERT_TRUE(res->value >= prevValue);
			prevValue = res->value;
			Deq2 = spBPQueueDequeue(QueueTest);
			}
	}

	//free resources
	spBPQueueDestroy(QueueTest);
	free(res);
	return true;
}


//Check Copy
bool Copy_E() {

	//Create the same queue as the queue in the example
	SPBPQueue* QueueTest = spBPQueueCreate(4);
	spBPQueueEnqueue(QueueTest,5,1);
	spBPQueueEnqueue(QueueTest,5,2);
	spBPQueueEnqueue(QueueTest,2,10);
	spBPQueueEnqueue(QueueTest,3,2.1);
	spBPQueueEnqueue(QueueTest,7,2.5);
	spBPQueueEnqueue(QueueTest,100,20);

	//Queue should look like this (<1,5>,<2,5>,<2.1,3>,<2.5,>)
	//Create copy of our Queue, Destroy the original
	SPBPQueue* QueueTestCopy = spBPQueueCopy(QueueTest);
	spBPQueueDequeue(QueueTest);
	spBPQueueDequeue(QueueTest);




	//Verifying that the copy is the same
	ASSERT_TRUE(spBPQueueMinValue(QueueTestCopy) == 1);
	ASSERT_TRUE(spBPQueueMaxValue(QueueTestCopy) == 2.5);


	//free resources
	spBPQueueDestroy(QueueTest);
	spBPQueueDestroy(QueueTestCopy);
	return true;

}

/*
void printarry (SPBPQueue* spbqueue) {
	printf("\nStart printing...\n");
	int k = spBPQueueSize(spbqueue);
	for (int i = 0; i < k ;i++ ){
		printf ("index in array: %d index of element %d value of element %f \n",i,spbqueue->queue[(i+spbqueue->start)%spbqueue->maxSize].index,spbqueue->queue[(i+spbqueue->start)%(spbqueue->maxSize)].value);
	}*/

int main() {
	RUN_TEST(Enqueue_Dequeue_Check);
	RUN_TEST(Copy_E);
	return 0;
}

