#include "SPPoint.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct sp_point_t {
	int index;
	int dim;
	double* data;
} SPPoint;


SPPoint* spPointCreate(double* data, int dim, int index) {
	SPPoint* p = malloc(sizeof(*p));
	p->data = (double*)malloc(sizeof(double)*dim);
	p->data = data;
	p->dim = dim;
	p->index = index;

	return p;
}


SPPoint* spPointCopy(SPPoint* source) {
	assert(source != NULL);
	SPPoint* copy = malloc(sizeof(*copy));
	int i = 0;
	copy->data = (double*)malloc(sizeof(double)*source->dim);
	for(i = 0; i < source->dim; ++i) {
		copy->data[i] = source->data[i];
	}
	copy->dim = source->dim;
	copy->index = source->index;

	return copy;
}

int main(int argc, char **argv) {
	double arr[] = {1,2,3,4,5};
	int size = 5;
	int index = 2;
	SPPoint* p = spPointCreate(arr, size , index);
	SPPoint * p2 = spPointCopy(p);
}
