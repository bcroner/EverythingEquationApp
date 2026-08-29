#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>

#include "EverythingEquationApp.hpp"
#include "EverythingEquationApp.cpp"

int main() {

	NAND_VECTOR* definition = NAND_VECTOR_create();
	SAT_VECTOR* translation = SAT_VECTOR_create(definition);

	if (translation) {
		bool* arr = new bool[translation->n];

		bool is_sat = SATSolver_threads(translation->a, translation->b, translation->c, translation->k, translation->n, arr, 0);

		std::cout << "Satisfiable: " << (is_sat ? "true" : "false") << std::endl;

		delete[] arr;
		SAT_VECTOR_destroy(translation);
	}

	NAND_VECTOR_destroy(definition);

    return 0;
}

#endif