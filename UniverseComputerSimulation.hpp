#ifndef __UNIVERSECOMPUTERSIMULATION_HPP__
#define __UNIVERSECOMPUTERSIMULATION_HPP__

#include "EverythingEquationApp.hpp"

typedef struct ID_Pool_tag {

	__int64* simulation_entities;

	__int64 simulation_entities_vtop;
	__int64 simulation_entities_vcap;

} ID_Pool;

enum claim_class { mathematically_false, mathematically_true, factual_claim, explanation }; // mathematically_false: a claim that is logically impossible to be true, mathematically_true: a claim that is logically impossible to be false, factual_claim: a claim that is accepted as knowledge because all claims in it are either mathematically true or other factual claims, explanation: a claim that contains at least one other explanation that has not yet been proven to be mathematically false

typedef struct CLAIMOID_CLASS_tag {

	__int64* claimoids;
	claim_class* claimoid_classes;

	__int64 claimoid_vtop;
	__int64 claimoids_vcap;
	__int64 claimoid_classes_vtop;
	__int64 claimoid_classes_vcap;

} CLAIMOID_CLASS;

typedef struct CLAIM_tag {

	__int64 id;

	NAND_VECTOR* claim;

	claim_class classification;

} CLAIM;

typedef struct KNOWLEDGE_BASE_tag {

	__int64 id;

	CLAIM** claims;

	CLAIMOID_CLASS* claimoid_classifications;

	__int64 claims_vtop;
	__int64 claims_vcap;

} KNOWLEDGE_BASE;

typedef struct Point_tag {

	__int64 id;

	__int64 x;
	__int64 y;
	__int64 z;

	__int64 mass;

} Point;


typedef struct GRAVITY_VECTOR_tag {

	__int64 direction_x;
	__int64 direction_y;
	__int64 direction_z;
	__int64 magnitude;

} GRAVITY_VECTOR;

typedef struct Universe_Computer_Simulation_State_tag {

	__int64 axis_2_pow;

	ID_Pool* id_pool;

	Point** points;

	__int64 points_vtop;
	__int64 points_vcap;

	claim_class points_claim_classification;

} Universe_Computer_Simulation_State;

enum direction {
	reverse, forward
};

typedef struct Universe_Computer_Simulation_tag {

	direction time_direction;

	Universe_Computer_Simulation_State* omega_state; // beginning state of the universe computer simulation, earlier in time than the alpha state
	Universe_Computer_Simulation_State* alpha_state; // end state of the universe computer simulation, later in time than the omega state

	NAND_VECTOR* shortest_satisfiable_nand_vector;	// the shortest NAND vector that satisfies the universe computer simulation logic, if one exists, otherwise nullptr
	NAND_VECTOR* current_nand_vector;				// the current NAND logic vector that is being tested to see if it satisfies the universe computer simulation
	SAT_VECTOR* current_sat_vector;					// the current SAT vector derived from the current NAND vector built from the universe computer simulation NAND logic

	__int64 initial_nand_vector_length;				// the initial length of the NAND vector that is being tested to see if it satisfies the universe computer simulation

} Universe_Computer_Simulation;

void check_claims(KNOWLEDGE_BASE* knowledge_base);
Point* simp_point_vector_create(__int64 init_sz);
Point* simp_point_vector_read(Point** v, __int64 vtop, __int64 vcap, __int64 loc);
void simp_point_vector_append(Point*** v, __int64* vtop, __int64* vcap, Point* data);
Point* create_point(__int64 x, __int64 y, __int64 z, __int64 mass);
__int64* simp_vector_create(__int64 init_sz);
__int64 simp_vector_read(__int64* v, __int64 vtop, __int64 vcap, __int64 loc);
void simp_vector_append(__int64** v, __int64* vtop, __int64* vcap, __int64 data);
int id_pool_retrieve(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap);
void id_pool_submit(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap, __int64 id);
int id_pool_retrieve(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap);
void id_pool_submit(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap, __int64 id);
ID_Pool* create_id_pool();

#endif
