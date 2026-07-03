#ifndef __EVERYTHINGEQUATIONAPP_CPP__
#define __EVERYTHINGEQUATIONAPP_CPP__

#include "SATSolver.hpp"
#include "SATFramework.hpp"
#include "EverythingEquationApp.hpp"

XNOR_VECTOR* XNOR_VECTOR_create() {

	XNOR_VECTOR* xnor_vector = new XNOR_VECTOR;

	xnor_vector->a = simp_vector_create(16);
	xnor_vector->b = simp_vector_create(16);
	xnor_vector->a_vtop = -1;
	xnor_vector->a_vcap = 16;
	xnor_vector->b_vtop = -1;
	xnor_vector->b_vcap = 16;

	simp_vector_append(&(xnor_vector->a), &(xnor_vector->a_vtop), &(xnor_vector->a_vcap), TRUE_3SAT);
	simp_vector_append(&(xnor_vector->b), &(xnor_vector->b_vtop), &(xnor_vector->b_vcap), TRUE_3SAT);
	simp_vector_append(&(xnor_vector->a), &(xnor_vector->a_vtop), &(xnor_vector->a_vcap), FALSE_3SAT);
	simp_vector_append(&(xnor_vector->b), &(xnor_vector->b_vtop), &(xnor_vector->b_vcap), FALSE_3SAT);

	return xnor_vector;
}

XNOR_VECTOR* XNOR_VECTOR_destroy(XNOR_VECTOR* xnor_vector) {

	if (xnor_vector) {
		if (xnor_vector->a) {
			delete[] xnor_vector->a;
			xnor_vector->a = nullptr;
		}
		if (xnor_vector->b) {
			delete[] xnor_vector->b;
			xnor_vector->b = nullptr;
		}
		delete xnor_vector;
		xnor_vector = nullptr;
	}

	return xnor_vector;

}

void XNOR_VECTOR_create_entry(XNOR_VECTOR* xnor_vector, __int64 a, __int64 b) {

	simp_vector_append(&(xnor_vector->a), &(xnor_vector->a_vtop), &(xnor_vector->a_vcap), a);
	simp_vector_append(&(xnor_vector->b), &(xnor_vector->b_vtop), &(xnor_vector->b_vcap), b);

}

XNOR_VECTOR* XNOR_VECTOR_create_translation(XNOR_VECTOR* definition) {

	if (definition->a_vtop + 1 < 2) {
		return nullptr;
	}

	XNOR_VECTOR* translation = XNOR_VECTOR_create();

	for (__int64 i = 2; i <= definition->a_vtop + 1; i++) {
		
		for (__int64 j = i; j >= 0; j--) {
			
			for (__int64 k = j-1; k >= 0; k--) {
				
				simp_vector_append(&(translation->a), &(translation->a_vtop), &(translation->a_vcap), -definition->a[j]);
				simp_vector_append(&(translation->b), &(translation->b_vtop), &(translation->b_vcap), definition->b[k]);
			}

		}

	}

	return translation;

}

#endif
