#ifndef __UNIVERSECOMPUTERSIMULATION_CPP__
#define __UNIVERSECOMPUTERSIMULATION_CPP__

#include "UniverseComputerSimulation.hpp"

Quantum_Point* simp_quantum_point_vector_create(__int64 init_sz) {

    Quantum_Point* ret = new Quantum_Point[init_sz];
    return ret;

}

Quantum_Point* simp_quantum_point_vector_read(Quantum_Point** v, __int64 vtop, __int64 vcap, __int64 loc) {

    if (loc > vtop)
        return 0;

    return v[loc];
}

void simp_quantum_point_vector_append(Quantum_Point*** v, __int64* vtop, __int64* vcap, Quantum_Point* data) {

    *vtop = *vtop + 1;

    if (*vtop < *vcap)
        (*v)[*vtop] = data;
    else {
        Quantum_Point*** newv = new Quantum_Point**[*vcap * 2];
        for (__int64 i = 0; i < *vcap * 2; i++)
            newv[i] = 0;
        for (__int64 i = 0; i < *vcap; i++)
            newv[i] = v[i];
        *vcap = *vcap * 2;
        delete[](*v);
        *v = *newv;
        (*v)[*vtop] = data;
    }

}

Quantum_Point* UniverseComputerSimulation_create_quantum_point(__int64 x, __int64 y, __int64 z, energy_state quantum_state) {

    Quantum_Point* q_point = new Quantum_Point();

    q_point->x = x;
    q_point->y = y;
    q_point->z = z;
    q_point->quantum_state = quantum_state;

	return q_point;
}

#endif
