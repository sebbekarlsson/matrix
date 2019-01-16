#ifndef MATRIX_H
#define MATRIX_H
typedef float* matrix4x4;

matrix4x4 init_matrix4x4();

void translate_matrix4x4(matrix4x4* matrix, float x, float y, float z);
#endif
