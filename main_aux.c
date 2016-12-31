#include "SPPoint.h"
#include "SPBPriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

double* getPointDataFromUser(int dim) {
	int i;
	double* pointData = (double*) malloc(sizeof(double) * dim);
	for (i = 0; i < dim; ++i) {
		scanf("%lf", &pointData[i]);
	}
	return pointData;
}

SPBPQueue* fillQueueWithL2Distance(SPPoint** pointsArr, SPPoint* q, int k,
		int n) {
	int i;
	double l2Distance;
	SPBPQueue* queue = spBPQueueCreate(k);
	for (i = 0; i < n; ++i) {
		l2Distance = spPointL2SquaredDistance(pointsArr[i], q);
		spBPQueueEnqueue(queue, spPointGetIndex(pointsArr[i]), l2Distance);
	}
	return queue;
}

void printQueue(SPBPQueue* queue) {
	int i;
	char comma;
	int queueSize = spBPQueueSize(queue);
	for (i = 0; i < queueSize; ++i) {
		BPQueueElement* queueHead = (BPQueueElement*) malloc(
				sizeof(BPQueueElement));
		spBPQueuePeek(queue, queueHead);
		spBPQueueDequeue(queue);
		if (i + 1 == queueSize) {
			comma = '\n';
		} else {
			comma = ',';
		}
		printf("%d%c ", queueHead->index, comma);
	}
}
