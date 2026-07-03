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

Point* PointUniverseComputerSimulation_create_point(__int64 x, __int64 y, __int64 z, energy_state point_state) {

    Point* point = new Point();

    point->x = x;
    point->y = y;
    point->z = z;
    point->point_state = point_state;

	return point;
}

Atom_Star_Galaxy_Dark_Matter* atom_star_galaxy_dark_matter_point_universe_computer_simulation_create_point(__int64 x, __int64 y, __int64 z, __int64 mass) {

    Atom_Star_Galaxy_Dark_Matter* point = new Atom_Star_Galaxy_Dark_Matter();
    point->x = x;
    point->y = y;
    point->z = z;
    point->mass = mass;
	return point;

}


__int64* simp_vector_create(__int64 init_sz) {

    __int64* ret = new __int64[init_sz];
    return ret;

}

__int64 simp_vector_read(__int64* v, __int64 vtop, __int64 vcap, __int64 loc) {

    if (loc > vtop)
        return 0;

    return v[loc];
}

void simp_vector_append(__int64** v, __int64* vtop, __int64* vcap, __int64 data) {

    *vtop = *vtop + 1;

    if (*vtop < *vcap)
        (*v)[*vtop] = data;
    else {
        __int64* newv = new __int64[*vcap * 2];
        for (__int64 i = 0; i < *vcap * 2; i++)
            newv[i] = 0;
        for (__int64 i = 0; i < *vcap; i++)
            newv[i] = (*v)[i];
        *vcap = *vcap * 2;
        delete[](*v);
        *v = newv;
        (*v)[*vtop] = data;
    }

}


int id_pool_retrieve(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap) {

    if (*id_pool_vtop == -1) {
        simp_vector_append(*id_pool, id_pool_vtop, id_pool_vcap, 0);
        return 0;
    }

    __int64 id = id_pool[*id_pool_vtop + 1];

    __int64 ix = -1;

    for (__int64 i = 0; i <= *id_pool_vtop + 1; i++) {
        if (id_pool[i] > id) {
            ix = i;
            break;
        }
    }

    for (__int64 i = ix; i <= *id_pool_vtop; i++)
        id_pool[i] = id_pool[i + 1];

    return id;

}

void id_pool_submit(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap, __int64 id) {

    __int64 ix = -1;

    for (__int64 i = 0; i <= *id_pool_vtop + 1; i++) {
        if (id_pool[i] > id) {
            ix = i;
            break;
        }
    }

    simp_vector_append(&(id_pool), id_pool_vtop, id_pool_vcap, id_pool[*id_pool_vtop + 1]);

    for (__int64 i = ix; i <= *id_pool_vtop; i++)
        id_pool[i] = id_pool[i + 1];

    id_pool[ix] = id;

}


ID_Pool* create_id_pool() {

    ID_Pool* id_pool = new ID_Pool();

    id_pool->simulation_entities = simp_vector_create(16);

    id_pool->simulation_entities_vtop = -1;
    id_pool->simulation_entities_vcap = 16;

    id_pool_retrieve(id_pool->simulation_entities, &(id_pool->simulation_entities_vtop), &(id_pool->simulation_entities_vcap));
    id_pool_retrieve(id_pool->simulation_entities, &(id_pool->simulation_entities_vtop), &(id_pool->simulation_entities_vcap));

    return id_pool;
}

#endif
