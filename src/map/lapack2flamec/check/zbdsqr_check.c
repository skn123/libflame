#include "FLA_lapack2flame_return_defs.h"
#include "FLA_f2c.h"

int zbdsqr_check(char *uplo, int *n, int *ncvt, int * nru, int *ncc, 
                 double *d__, double *e, 
                 dcomplex *vt, int *ldvt, 
                 dcomplex *u, int *ldu, 
                 dcomplex *c__, int *ldc, 
                 double *rwork, int *info)
{
    /* System generated locals */
    int c_dim1, c_offset, u_dim1, u_offset, vt_dim1, vt_offset, i__1;
    logical lower;
  
    /* Parameter adjustments */
    --d__;
    --e;
    vt_dim1 = *ldvt;
    vt_offset = 1 + vt_dim1;
    vt -= vt_offset;
    u_dim1 = *ldu;
    u_offset = 1 + u_dim1;
    u -= u_offset;
    c_dim1 = *ldc;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    --rwork;
    /* Function Body */
    *info = 0;
    lower = lsame_(uplo, "L");
    if (! lsame_(uplo, "U") && ! lower)
    {
        *info = -1;
    }
    else if (*n < 0)
    {
        *info = -2;
    }
    else if (*ncvt < 0)
    {
        *info = -3;
    }
    else if (*nru < 0)
    {
        *info = -4;
    }
    else if (*ncc < 0)
    {
        *info = -5;
    }
    else if (*ncvt == 0 && *ldvt < 1 || *ncvt > 0 && *ldvt < max(1,*n))
    {
        *info = -9;
    }
    else if (*ldu < max(1,*nru))
    {
        *info = -11;
    }
    else if (*ncc == 0 && *ldc < 1 || *ncc > 0 && *ldc < max(1,*n))
    {
        *info = -13;
    }
    if (*info != 0)
    {
        i__1 = -(*info);
        xerbla_("ZBDSQR", &i__1);
        return LAPACK_FAILURE;
    }
    if (*n == 0)
    {
        return LAPACK_QUICK_RETURN;
    }
    return LAPACK_SUCCESS;
}
