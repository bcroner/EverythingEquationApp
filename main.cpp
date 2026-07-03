#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>

#include "EverythingEquationApp.cpp"

int main() {

	XNOR_VECTOR* definition = XNOR_VECTOR_create();
	XNOR_VECTOR* translation = XNOR_VECTOR_create();

	XNOR_VECTOR_create_entry(definition, TRUE_3SAT, TRUE_3SAT);
	XNOR_VECTOR_create_entry(definition, TRUE_3SAT, TRUE_3SAT);
	XNOR_VECTOR_create_entry(definition, FALSE_3SAT, FALSE_3SAT);

    return 0;
}

#endif
