#include "SPPoint.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sp_point_t {
	int index;
	int dim;
	double* data;
} SPPoint;


SPPoint* spPointCreate(double* data, int dim, int index) {
	SPPoint* p = (SPPoint*)malloc(sizeof(*p));
	p->data = (double*)malloc(sizeof(double)*dim);
	p->data = data;
	p->dim = dim;
	p->index = index;

	return p;
}


SPPoint* spPointCopy(SPPoint* source) {
	assert(source != NULL);
	SPPoint* copy = (SPPoint*)malloc(sizeof(*copy));
	int i = 0;
	copy->data = (double*)malloc(sizeof(double)*source->dim);
	for(i = 0; i < source->dim; ++i) {
		copy->data[i] = source->data[i];
	}
	copy->dim = source->dim;
	copy->index = source->index;

	return copy;
}

void spPointDestroy(SPPoint* point) {
	if (point != NULL) {
		free(point);
	}
}

int spPointGetDimension(SPPoint* point) {
	assert(point != NULL);
	return (point->dim);
}


int spPointGetIndex(SPPoint* point) {
	assert(point != NULL);
	return (point->index);
}


double spPointGetAxisCoor(SPPoint* point, int axis) {
	assert(point != NULL);
	assert(axis < point->dim);
	return (point->data[axis]);
}

double spPointL2SquaredDistance(SPPoint* p, SPPoint* q) {
	assert(p != NULL && q != NULL);
	assert(p->dim == q->dim);
	double result = 0;
	int i = 0;
	for (i = 0; i < p->dim; ++i) {
		result+= pow((q->data[i] - p->data[i]),2);
	}
	return result;
}

int main(int argc, char **argv) {
	double arr[] = {1,2,3,4,5};
	int size = 5;
	int index = 2;
	SPPoint* p = spPointCreate(arr, size , index);
	SPPoint* p2 = spPointCopy(p);
	printf("%d",p->dim);
	spPointDestroy(p);
	printf("%d",p->dim);
}
