#ifndef __EVERYTHINGEQUATIONAPP_HPP__
#define __EVERYTHINGEQUATIONAPP_HPP__

typedef struct XNOR_VECTOR_tag {

	__int64* a;
	__int64* b;

	_int64 a_vtop;
	_int64 a_vcap;
	_int64 b_vtop;
	_int64 b_vcap;

} XNOR_VECTOR;

typedef struct SAT_VECTOR_tag {
	__int64* a;
	__int64* b;
	__int64* c;
	_int64 a_vtop;
	_int64 a_vcap;
	_int64 b_vtop;
	_int64 b_vcap;
	_int64 c_vtop;
	_int64 c_vcap;
} SAT_VECTOR;

XNOR_VECTOR* XNOR_VECTOR_create();
XNOR_VECTOR* XNOR_VECTOR_destroy(XNOR_VECTOR* xnor_vector);
void XNOR_VECTOR_create_entry(XNOR_VECTOR* xnor_vector, __int64 a, __int64 b);
SAT_VECTOR* SAT_VECTOR_create(XNOR_VECTOR* definition);
SAT_VECTOR* SAT_VECTOR_destroy(SAT_VECTOR* sat_vector);

#endif
