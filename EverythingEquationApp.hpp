#ifndef __EVERYTHINGEQUATIONAPP_HPP__
#define __EVERYTHINGEQUATIONAPP_HPP__

typedef struct NAND_VECTOR_tag {

	__int64* a;
	__int64* b;

	__int64 a_vtop;
	__int64 a_vcap;
	__int64 b_vtop;
	__int64 b_vcap;

} NAND_VECTOR;

typedef struct SAT_VECTOR_tag {

	__int64 k;
	__int64 n;

	__int64* a;
	__int64* b;
	__int64* c;

	__int64* p;
	__int64* h;

	__int64 a_vtop;
	__int64 a_vcap;
	__int64 b_vtop;
	__int64 b_vcap;
	__int64 c_vtop;
	__int64 c_vcap;

	__int64 p_vtop;
	__int64 p_vcap;
	__int64 h_vtop;
	__int64 h_vcap;

} SAT_VECTOR;

NAND_VECTOR* NAND_VECTOR_create();
NAND_VECTOR* NAND_VECTOR_destroy(NAND_VECTOR* nand_vector);
void NAND_VECTOR_create_entry(NAND_VECTOR* nand_vector, __int64 a, __int64 b);
SAT_VECTOR* SAT_VECTOR_create(NAND_VECTOR* definition);
SAT_VECTOR* SAT_VECTOR_destroy(SAT_VECTOR* sat_vector);

#endif
