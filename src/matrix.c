#include "include/matrix.h"
#include <stdlib.h>


matrix4x4 init_matrix4x4() {
    matrix4x4 m = calloc(16, sizeof(float));

    m[0] = 1;    m[1] = 0;    m[2] = 0;    m[3] = 0;
    m[4] = 0;    m[5] = 1;    m[6] = 0;    m[7] = 0;
    m[8] = 0;    m[9] = 0;    m[10] = 1;   m[11] = 0;
    m[12] = 0;   m[13] = 0;   m[14] = 0;   m[15] = 1;

    return m;
}

void translate_matrix4x4(matrix4x4* matrix, float x, float y, float z) {
    matrix4x4 m = (*matrix);

    m[12] = m[0] * x + m[4] * y + m[8] * z + m[12];
    m[13] = m[1] * x + m[5] * y + m[9] * z + m[13];
    m[14] = m[2] * x + m[6] * y + m[10] * z + m[14];
    m[15] = m[3] * x + m[7] * y + m[11] * z + m[15]; 
}
