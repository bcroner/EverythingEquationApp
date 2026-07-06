#ifndef __UNIVERSECOMPUTERSIMULATION_CPP__
#define __UNIVERSECOMPUTERSIMULATION_CPP__

#include "UniverseComputerSimulation.hpp"

void check_claims(KNOWLEDGE_BASE* knowledge_base) {

    for (__int64 i = 0; i <= knowledge_base->claims_vtop; i++) {

        CLAIM* claim = knowledge_base->claims[i];
        
        for (__int64 j = 0; j <= claim->claim->a_vtop; j++) {

            __int64 a = claim->claim->a[j];
            __int64 b = claim->claim->b[j];

			bool a_passes = false;
			bool b_passes = false;

            for (__int64 k = 0; k <= knowledge_base->claimoid_classifications->claimoids_vtop; k++) {

                if (knowledge_base->claimoid_classifications->claimoids[k] == a && (knowledge_base->claimoid_classifications->claimoid_classes[k] == mathematically_true || knowledge_base->claimoid_classifications->claimoid_classes[k] == factual_claim))
					a_passes = true;
                if (knowledge_base->claimoid_classifications->claimoids[k] == b && (knowledge_base->claimoid_classifications->claimoid_classes[k] == mathematically_true || knowledge_base->claimoid_classifications->claimoid_classes[k] == factual_claim))
                    b_passes = true;

                if (a_passes && b_passes)
					break;

			}
            
            if (a_passes && b_passes) {

                claim->classification = factual_claim;

				// check for internal consistency of all claims considered to be factual claims in the knowledge base
				// if consistent, exit the check_claims function
				// if the set of all factual claims in the knowledge base is internally inconsistent, then each claim is checked on a claimoid basis and the values of the claimoids are stored
				// if the stored value of any claimoid is found to be inconsistent with the stored value of that claimoid in any other claim, then the claim's classification is set to explanation
				// all claims containing any claimoid that is found to be inconsistent with the stored value of that claimoid in any other claim are set to explanation

            }

		}
	}   

}

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

Point* create_point(__int64 x, __int64 y, __int64 z, __int64 mass) {

    Point* point = new Point();
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
