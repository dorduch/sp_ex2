#include "SPPoint.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sp_bpq_element_t {
	int index;
	double value;
} BPQueueElement;

typedef struct sp_bp_queue_t {
	int maxSize;
	int size;
	BPQueueElement* queue;
} SPBPQueue;


SPBPQueue* spBPQueueCreate(int maxSize) {
	if (maxSize > 0) {
		SPBPQueue* queue = (SPBPQueue*) malloc(sizeof(*queue));
		if (queue == NULL) {
			return NULL;
		}
		queue->maxSize = maxSize;
		queue->size = 0;
		queue->queue = (BPQueueElement*) malloc(
				sizeof(BPQueueElement) * maxSize);
		if (queue->queue == NULL) {
			free(queue);
			return NULL;
		}
		return queue;
	} else {
		return NULL;
	}

}

SPBPQueue* spBPQueueCopy(SPBPQueue* source) {
	int i = 0;
	SPBPQueue* queueCopy = (SPBPQueue*) malloc(sizeof(queueCopy));
	queueCopy->maxSize = source->maxSize;
	queueCopy->size = source->size;
	queueCopy->queue = (BPQueueElement*) malloc(sizeof(BPQueueElement)*source->maxSize);
	for (i = 0; i < source->size; ++i) {
		queueCopy->queue[i].index = source->queue[i].index;
		queueCopy->queue[i].value = source->queue[i].value;
	}
	return queueCopy;
}

void spBPQueueDestroy(SPBPQueue* source) {
	free(source->queue);
	free(source);
}

void spBPQueueClear(SPBPQueue* source) {
	source->size = 0;
}

int spBPQueueSize(SPBPQueue* source) {
	return source->size;
}

int spBPQueueGetMaxSize(SPBPQueue* source) {
	return source->maxSize;
}

SP_BPQUEUE_MSG spBPQueueEnqueue(SPBPQueue* source, int index, double value) {
	int i = 0;
	if (source->size + 1 > source->maxSize) {
		// TODO return error
	} else {
		for (int i = 0; i < source->size; ++i) {
			if ()
		}
	}
	BPQueueElement* element = (BPQueueElement*) malloc(sizeof(element*));
	element->index = index;
	element->value = value;

}

int main(int argc, char **argv) {

}
