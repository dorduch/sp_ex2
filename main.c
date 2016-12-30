#include <stdio.h>
#include <stdlib.h>
#include "SPPoint.h"
#include "SPBPriorityQueue.h"
#include "main_aux.h"

int main() {
	int n, d, k, i;
	SPPoint** pointsArr;
	SPPoint* q;
	SPBPQueue* queue;
	scanf("%d %d %d", &n, &d, &k);
	pointsArr = (SPPoint**) malloc(sizeof(SPPoint*) * n);

	for (i = 0; i < n + 1; ++i) {
		double* pointData = getPointDataFromUser(d);
		if (i == n) {
			q = spPointCreate(pointData, d, i+1);
		} else {
			pointsArr[i] = spPointCreate(pointData, d, i+1);
		}
	}
	queue = fillQueueWithL2Distance(pointsArr, q, k, n);
	printQueue(queue);
}
