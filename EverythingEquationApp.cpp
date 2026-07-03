#ifndef __EVERYTHINGEQUATIONAPP_CPP__
#define __EVERYTHINGEQUATIONAPP_CPP__

#include "SATSolver.hpp"
#include "EverythingEquationApp.hpp"

NAND_VECTOR* NAND_VECTOR_create() {

	NAND_VECTOR* nand_vector = new NAND_VECTOR();

	nand_vector->a = simp_vector_create(16);
	nand_vector->b = simp_vector_create(16);
	nand_vector->a_vtop = -1;
	nand_vector->a_vcap = 16;
	nand_vector->b_vtop = -1;
	nand_vector->b_vcap = 16;

	simp_vector_append(&(nand_vector->a), &(nand_vector->a_vtop), &(nand_vector->a_vcap), TRUE_3SAT);
	simp_vector_append(&(nand_vector->b), &(nand_vector->b_vtop), &(nand_vector->b_vcap), TRUE_3SAT);
	simp_vector_append(&(nand_vector->a), &(nand_vector->a_vtop), &(nand_vector->a_vcap), FALSE_3SAT);
	simp_vector_append(&(nand_vector->b), &(nand_vector->b_vtop), &(nand_vector->b_vcap), FALSE_3SAT);

	return nand_vector;
}

NAND_VECTOR* NAND_VECTOR_destroy(NAND_VECTOR* nand_vector) {

	if (nand_vector) {
		if (nand_vector->a) {
			delete[] nand_vector->a;
			nand_vector->a = nullptr;
		}
		if (nand_vector->b) {
			delete[] nand_vector->b;
			nand_vector->b = nullptr;
		}
		delete nand_vector;
		nand_vector = nullptr;
	}

	return nand_vector;

}

void NAND_VECTOR_create_entry(NAND_VECTOR* nand_vector, __int64 a, __int64 b) {

	simp_vector_append(&(nand_vector->a), &(nand_vector->a_vtop), &(nand_vector->a_vcap), a);
	simp_vector_append(&(nand_vector->b), &(nand_vector->b_vtop), &(nand_vector->b_vcap), b);

}

SAT_VECTOR* SAT_VECTOR_create(NAND_VECTOR* definition) {

	if (definition->a_vtop + 1 < 2) {
		return nullptr;
	}

	SAT_VECTOR* translation = new SAT_VECTOR ();

	translation->a = simp_vector_create(16);
	translation->b = simp_vector_create(16);
	translation->c = simp_vector_create(16);

	translation->p = simp_vector_create(16);
	translation->h = simp_vector_create(16);

	translation->a_vtop = -1;
	translation->a_vcap = 16;
	translation->b_vtop = -1;
	translation->b_vcap = 16;
	translation->c_vtop = -1;
	translation->c_vcap = 16;

	translation->p_vtop = -1;
	translation->p_vcap = 16;
	translation->h_vtop = -1;
	translation->h_vcap = 16;

	__int64 first_avail_p_h_ix = 1;

	for (__int64 i = 2; i <= definition->a_vtop + 1; i++) {
		
		for (__int64 j = i; j >= 0; j--) {

			__int64 p = first_avail_p_h_ix;

			simp_vector_append(&(translation->p), &(translation->p_vtop), &(translation->p_vcap), p);
			first_avail_p_h_ix++;
			
			for (__int64 k = j-1; k >= 0; k--) {

				__int64 h = first_avail_p_h_ix;

				simp_vector_append(&(translation->h), &(translation->h_vtop), &(translation->h_vcap), p);
				first_avail_p_h_ix++;

				// (!P | !A | H) & (!H | !B | C) & (!P | A | C) & (!P | B | C)
				
				simp_vector_append(&(translation->a), &(translation->a_vtop), &(translation->a_vcap), -p);
				simp_vector_append(&(translation->b), &(translation->b_vtop), &(translation->b_vcap), -j);
				simp_vector_append(&(translation->c), &(translation->c_vtop), &(translation->c_vcap), h);

				simp_vector_append(&(translation->a), &(translation->a_vtop), &(translation->a_vcap), -h);
				simp_vector_append(&(translation->b), &(translation->b_vtop), &(translation->b_vcap), -k);
				simp_vector_append(&(translation->c), &(translation->c_vtop), &(translation->c_vcap), i);

				simp_vector_append(&(translation->a), &(translation->a_vtop), &(translation->a_vcap), -p);
				simp_vector_append(&(translation->b), &(translation->b_vtop), &(translation->b_vcap), j);
				simp_vector_append(&(translation->c), &(translation->c_vtop), &(translation->c_vcap), i);

				simp_vector_append(&(translation->a), &(translation->a_vtop), &(translation->a_vcap), -p);
				simp_vector_append(&(translation->b), &(translation->b_vtop), &(translation->b_vcap), k);
				simp_vector_append(&(translation->c), &(translation->c_vtop), &(translation->c_vcap), i);
			}

		}

	}

	__int64 top = translation->a_vtop + 1;

	for (__int64 i = 0; i < first_avail_p_h_ix; i++) {
		
		translation->p[i] += top;
		translation->h[i] += top;

	}

	translation->k = translation->a_vtop + 1;
	translation->n = translation->p_vtop + 1;

	return translation;

}

SAT_VECTOR* SAT_VECTOR_destroy(SAT_VECTOR* sat_vector) {
	if (sat_vector) {
		if (sat_vector->a) {
			delete[] sat_vector->a;
			sat_vector->a = nullptr;
		}
		if (sat_vector->b) {
			delete[] sat_vector->b;
			sat_vector->b = nullptr;
		}
		if (sat_vector->c) {
			delete[] sat_vector->c;
			sat_vector->c = nullptr;
		}
		delete sat_vector;
		sat_vector = nullptr;
	}
	return sat_vector;
}

#endif
