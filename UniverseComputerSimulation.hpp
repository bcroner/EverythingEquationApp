#ifndef __UNIVERSECOMPUTERSIMULATION_HPP__
#define __UNIVERSECOMPUTERSIMULATION_HPP__

enum direction {
	reverse, forward
};

enum energy_state {
	ground, excited
};

typedef struct Quantum_Point_tag {

	__int64 x;
	__int64 y;
	__int64 z;

	energy_state quantum_state;

	__int64 mass;

} Quantum_Point;

typedef struct Atom_Star_Galaxy_Dark_Matter_tag {

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

typedef struct QuantumUniverseComputerSimulation_tag {

	direction time_direction;

	__int64 axis_2_pow;

	Quantum_Point** quantum_points;

	__int64 quantum_points_vtop;
	__int64 quantum_points_vcap;

	claim_class claim_classification = mathematically_true;

} QuantumUniverseComputerSimulation;

typedef struct ASGDMUniverseComputerSimulation_tag {

	direction time_direction;

	__int64 axis_2_pow;

	Atom_Star_Galaxy_Dark_Matter** atom_star_galaxy_dark_matter_points;

	__int64 atom_star_galaxy_dark_matter_points_vtop;
	__int64 atom_star_galaxy_dark_matter_points_vcap;

	claim_class claim_classification = explanation;

} ASGDMUniverseComputerSimulation;

Quantum_Point* simp_quantum_point_vector_create(__int64 init_sz);
Quantum_Point* simp_quantum_point_vector_read(Quantum_Point** v, __int64 vtop, __int64 vcap, __int64 loc);
void simp_quantum_point_vector_append(Quantum_Point*** v, __int64* vtop, __int64* vcap, Quantum_Point* data);
Quantum_Point* QuantumUniverseComputerSimulation_create_quantum_point(__int64 x, __int64 y, __int64 z, energy_state quantum_state);

#endif
