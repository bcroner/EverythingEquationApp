#ifndef __UNIVERSECOMPUTERSIMULATION_CPP__
#define __UNIVERSECOMPUTERSIMULATION_CPP__

#include "UniverseComputerSimulation.hpp"

Point* simp_point_vector_create(__int64 init_sz) {

    Point* ret = new Point[init_sz];
    return ret;

}

Point* simp_point_vector_read(Point** v, __int64 vtop, __int64 vcap, __int64 loc) {

    if (loc > vtop)
        return 0;

    return v[loc];
}

void simp_point_vector_append(Point*** v, __int64* vtop, __int64* vcap, Point* data) {

    *vtop = *vtop + 1;

    if (*vtop < *vcap)
        (*v)[*vtop] = data;
    else {
        Point*** newv = new Point**[*vcap * 2];
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

Point* QuantumUniverseComputerSimulation_create_point(__int64 x, __int64 y, __int64 z, energy_state point_state) {

    Point* point = new Point();

    point->x = x;
    point->y = y;
    point->z = z;
    point->point_state = point_state;

	return point;
}

#endif
