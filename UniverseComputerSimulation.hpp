#ifndef __UNIVERSECOMPUTERSIMULATION_HPP__
#define __UNIVERSECOMPUTERSIMULATION_HPP__

enum direction {
	reverse, forward
};

enum energy_state {
	ground, excited
};

typedef struct Point_tag {

	__int64 id;

	__int64 x;
	__int64 y;
	__int64 z;

	energy_state point_state;

	__int64 mass;

} Point;

typedef struct ID_Pool_tag {

	__int64* simulation_entities;

	__int64 simulation_entities_vtop;
	__int64 simulation_entities_vcap;

} ID_Pool;

typedef struct Atom_Star_Galaxy_Dark_Matter_tag {

	__int64 id;

	__int64 x;
	__int64 y;
	__int64 z;
	__int64 mass;

} Atom_Star_Galaxy_Dark_Matter;

typedef struct GRAVITY_VECTOR_tag {

	__int64 direction_x;
	__int64 direction_y;
	__int64 direction_z;
	__int64 magnitude;

} GRAVITY_VECTOR;

enum claim_class { mathematically_false, mathematically_true, factual_claim, explanation }; // mathematically_false: a claim that is logically impossible to be true, mathematically_true: a claim that is logically impossible to be false, factual_claim: a claim that is accepted as knowledge because all claims in it are either mathematically true or other factual claims, explanation: a claim that contains at least one other explanation that has not yet been proven to be mathematically false

typedef struct PointUniverseComputerSimulation_tag {

	direction time_direction;

	__int64 axis_2_pow;

	ID_Pool* points_id_pool;

	Point** points;

	__int64 points_vtop;
	__int64 points_vcap;

	claim_class claim_classification = mathematically_true;

} PointUniverseComputerSimulation;

typedef struct ASGDMUniverseComputerSimulation_tag {

	direction time_direction;

	__int64 axis_2_pow;

	ID_Pool* atom_star_galaxy_dark_matter_points_id_pool;

	Atom_Star_Galaxy_Dark_Matter** atom_star_galaxy_dark_matter_points;

	__int64 atom_star_galaxy_dark_matter_points_vtop;
	__int64 atom_star_galaxy_dark_matter_points_vcap;

	claim_class claim_classification = explanation;

} ASGDMUniverseComputerSimulation;

Point* simp_point_vector_create(__int64 init_sz);
Point* simp_point_vector_read(Point** v, __int64 vtop, __int64 vcap, __int64 loc);
void simp_point_vector_append(Point*** v, __int64* vtop, __int64* vcap, Point* data);
Point* PointUniverseComputerSimulation_create_point(__int64 x, __int64 y, __int64 z, energy_state point_state);
__int64* simp_vector_create(__int64 init_sz);
__int64 simp_vector_read(__int64* v, __int64 vtop, __int64 vcap, __int64 loc);
void simp_vector_append(__int64** v, __int64* vtop, __int64* vcap, __int64 data);
int id_pool_retrieve(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap);
void id_pool_submit(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap, __int64 id);
int id_pool_retrieve(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap);
void id_pool_submit(__int64* id_pool, __int64* id_pool_vtop, __int64* id_pool_vcap, __int64 id);
ID_Pool* create_id_pool();

#endif
