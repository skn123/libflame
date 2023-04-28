#ifdef FLA_ENABLE_XBLAS
/* ../netlib/zla_gbrfsx_extended.f -- translated by f2c (version 20100827). You must link the resulting object file with libf2c: on Microsoft Windows system, link with libf2c.lib;
 on Linux or Unix systems, link with .../path/to/libf2c.a -lm or, if you install libf2c.a in a standard place, with -lf2c -lm -- in that order, at the end of the command line, as in cc *.o -lf2c -lm Source for libf2c is in /netlib/f2c/libf2c.zip, e.g., http://www.netlib.org/f2c/libf2c.zip */
#include "FLA_f2c.h" /* Table of constant values */
static integer c__1 = 1;
static doublecomplex c_b6 =
{
    -1.,0.
}
;
static doublecomplex c_b8 =
{
    1.,0.
}
;
static doublereal c_b31 = 1.;
/* > \brief \b ZLA_GBRFSX_EXTENDED improves the computed solution to a system of linear equations for general banded matrices by performing extra-precise iterative refinement and provides error bounds and backwar d error estimates for the solution. */
/* =========== DOCUMENTATION =========== */
/* Online html documentation available at */
/* http://www.netlib.org/lapack/explore-html/ */
/* > \htmlonly */
/* > Download ZLA_GBRFSX_EXTENDED + dependencies */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.tgz?format=tgz&filename=/lapack/lapack_routine/zla_gbr fsx_extended.f"> */
/* > [TGZ]</a> */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.zip?format=zip&filename=/lapack/lapack_routine/zla_gbr fsx_extended.f"> */
/* > [ZIP]</a> */
/* > <a href="http://www.netlib.org/cgi-bin/netlibfiles.txt?format=txt&filename=/lapack/lapack_routine/zla_gbr fsx_extended.f"> */
/* > [TXT]</a> */
/* > \endhtmlonly */
/* Definition: */
/* =========== */
/* SUBROUTINE ZLA_GBRFSX_EXTENDED( PREC_TYPE, TRANS_TYPE, N, KL, KU, */
/* NRHS, AB, LDAB, AFB, LDAFB, IPIV, */
/* COLEQU, C, B, LDB, Y, LDY, */
/* BERR_OUT, N_NORMS, ERR_BNDS_NORM, */
/* ERR_BNDS_COMP, RES, AYB, DY, */
/* Y_TAIL, RCOND, ITHRESH, RTHRESH, */
/* DZ_UB, IGNORE_CWISE, INFO ) */
/* .. Scalar Arguments .. */
/* INTEGER INFO, LDAB, LDAFB, LDB, LDY, N, KL, KU, NRHS, */
/* $ PREC_TYPE, TRANS_TYPE, N_NORMS, ITHRESH */
/* LOGICAL COLEQU, IGNORE_CWISE */
/* DOUBLE PRECISION RTHRESH, DZ_UB */
/* .. */
/* .. Array Arguments .. */
/* INTEGER IPIV( * ) */
/* COMPLEX*16 AB( LDAB, * ), AFB( LDAFB, * ), B( LDB, * ), */
/* $ Y( LDY, * ), RES( * ), DY( * ), Y_TAIL( * ) */
/* DOUBLE PRECISION C( * ), AYB(*), RCOND, BERR_OUT( * ), */
/* $ ERR_BNDS_NORM( NRHS, * ), */
/* $ ERR_BNDS_COMP( NRHS, * ) */
/* .. */
/* > \par Purpose: */
/* ============= */
/* > */
/* > \verbatim */
/* > */
/* > ZLA_GBRFSX_EXTENDED improves the computed solution to a system of */
/* > linear equations by performing extra-precise iterative refinement */
/* > and provides error bounds and backward error estimates for the solution. */
/* > This subroutine is called by ZGBRFSX to perform iterative refinement. */
/* > In addition to normwise error bound, the code provides maximum */
/* > componentwise error bound if possible. See comments for ERR_BNDS_NORM */
/* > and ERR_BNDS_COMP for details of the error bounds. Note that this */
/* > subroutine is only resonsible for setting the second fields of */
/* > ERR_BNDS_NORM and ERR_BNDS_COMP. */
/* > \endverbatim */
/* Arguments: */
/* ========== */
/* > \param[in] PREC_TYPE */
/* > \verbatim */
/* > PREC_TYPE is INTEGER */
/* > Specifies the intermediate precision to be used in refinement. */
/* > The value is defined by ILAPREC(P) where P is a CHARACTER and */
/* > P = 'S': Single */
/* > = 'D': Double */
/* > = 'I': Indigenous */
/* > = 'X', 'E': Extra */
/* > \endverbatim */
/* > */
/* > \param[in] TRANS_TYPE */
/* > \verbatim */
/* > TRANS_TYPE is INTEGER */
/* > Specifies the transposition operation on A. */
/* > The value is defined by ILATRANS(T) where T is a CHARACTER and */
/* > T = 'N': No transpose */
/* > = 'T': Transpose */
/* > = 'C': Conjugate transpose */
/* > \endverbatim */
/* > */
/* > \param[in] N */
/* > \verbatim */
/* > N is INTEGER */
/* > The number of linear equations, i.e., the order of the */
/* > matrix A. N >= 0. */
/* > \endverbatim */
/* > */
/* > \param[in] KL */
/* > \verbatim */
/* > KL is INTEGER */
/* > The number of subdiagonals within the band of A. KL >= 0. */
/* > \endverbatim */
/* > */
/* > \param[in] KU */
/* > \verbatim */
/* > KU is INTEGER */
/* > The number of superdiagonals within the band of A. KU >= 0 */
/* > \endverbatim */
/* > */
/* > \param[in] NRHS */
/* > \verbatim */
/* > NRHS is INTEGER */
/* > The number of right-hand-sides, i.e., the number of columns of the */
/* > matrix B. */
/* > \endverbatim */
/* > */
/* > \param[in] AB */
/* > \verbatim */
/* > AB is COMPLEX*16 array, dimension (LDAB,N) */
/* > On entry, the N-by-N matrix A. */
/* > \endverbatim */
/* > */
/* > \param[in] LDAB */
/* > \verbatim */
/* > LDAB is INTEGER */
/* > The leading dimension of the array A. LDAB >= max(1,N). */
/* > \endverbatim */
/* > */
/* > \param[in] AFB */
/* > \verbatim */
/* > AFB is COMPLEX*16 array, dimension (LDAF,N) */
/* > The factors L and U from the factorization */
/* > A = P*L*U as computed by ZGBTRF. */
/* > \endverbatim */
/* > */
/* > \param[in] LDAFB */
/* > \verbatim */
/* > LDAFB is INTEGER */
/* > The leading dimension of the array AF. LDAF >= max(1,N). */
/* > \endverbatim */
/* > */
/* > \param[in] IPIV */
/* > \verbatim */
/* > IPIV is INTEGER array, dimension (N) */
/* > The pivot indices from the factorization A = P*L*U */
/* > as computed by ZGBTRF;
row i of the matrix was interchanged */
/* > with row IPIV(i). */
/* > \endverbatim */
/* > */
/* > \param[in] COLEQU */
/* > \verbatim */
/* > COLEQU is LOGICAL */
/* > If .TRUE. then column equilibration was done to A before calling */
/* > this routine. This is needed to compute the solution and error */
/* > bounds correctly. */
/* > \endverbatim */
/* > */
/* > \param[in] C */
/* > \verbatim */
/* > C is DOUBLE PRECISION array, dimension (N) */
/* > The column scale factors for A. If COLEQU = .FALSE., C */
/* > is not accessed. If C is input, each element of C should be a power */
/* > of the radix to ensure a reliable solution and error estimates. */
/* > Scaling by powers of the radix does not cause rounding errors unless */
/* > the result underflows or overflows. Rounding errors during scaling */
/* > lead to refining with a matrix that is not equivalent to the */
/* > input matrix, producing error estimates that may not be */
/* > reliable. */
/* > \endverbatim */
/* > */
/* > \param[in] B */
/* > \verbatim */
/* > B is COMPLEX*16 array, dimension (LDB,NRHS) */
/* > The right-hand-side matrix B. */
/* > \endverbatim */
/* > */
/* > \param[in] LDB */
/* > \verbatim */
/* > LDB is INTEGER */
/* > The leading dimension of the array B. LDB >= max(1,N). */
/* > \endverbatim */
/* > */
/* > \param[in,out] Y */
/* > \verbatim */
/* > Y is COMPLEX*16 array, dimension (LDY,NRHS) */
/* > On entry, the solution matrix X, as computed by ZGBTRS. */
/* > On exit, the improved solution matrix Y. */
/* > \endverbatim */
/* > */
/* > \param[in] LDY */
/* > \verbatim */
/* > LDY is INTEGER */
/* > The leading dimension of the array Y. LDY >= max(1,N). */
/* > \endverbatim */
/* > */
/* > \param[out] BERR_OUT */
/* > \verbatim */
/* > BERR_OUT is DOUBLE PRECISION array, dimension (NRHS) */
/* > On exit, BERR_OUT(j) contains the componentwise relative backward */
/* > error for right-hand-side j from the formula */
/* > max(i) ( f2c_abs(RES(i)) / ( f2c_abs(op(A_s))*f2c_abs(Y) + f2c_abs(B_s) )(i) ) */
/* > where f2c_abs(Z) is the componentwise absolute value of the matrix */
/* > or vector Z. This is computed by ZLA_LIN_BERR. */
/* > \endverbatim */
/* > */
/* > \param[in] N_NORMS */
/* > \verbatim */
/* > N_NORMS is INTEGER */
/* > Determines which error bounds to return (see ERR_BNDS_NORM */
/* > and ERR_BNDS_COMP). */
/* > If N_NORMS >= 1 return normwise error bounds. */
/* > If N_NORMS >= 2 return componentwise error bounds. */
/* > \endverbatim */
/* > */
/* > \param[in,out] ERR_BNDS_NORM */
/* > \verbatim */
/* > ERR_BNDS_NORM is DOUBLE PRECISION array, dimension */
/* > (NRHS, N_ERR_BNDS) */
/* > For each right-hand side, this array contains information about */
/* > various error bounds and condition numbers corresponding to the */
/* > normwise relative error, which is defined as follows: */
/* > */
/* > Normwise relative error in the ith solution vector: */
/* > max_j (f2c_abs(XTRUE(j,i) - X(j,i))) */
/* > ------------------------------ */
/* > max_j f2c_abs(X(j,i)) */
/* > */
/* > The array is indexed by the type of error information as described */
/* > below. There currently are up to three pieces of information */
/* > returned. */
/* > */
/* > The first index in ERR_BNDS_NORM(i,:) corresponds to the ith */
/* > right-hand side. */
/* > */
/* > The second index in ERR_BNDS_NORM(:,err) contains the following */
/* > three fields: */
/* > err = 1 "Trust/don't trust" boolean. Trust the answer if the */
/* > reciprocal condition number is less than the threshold */
/* > sqrt(n) * slamch('Epsilon'). */
/* > */
/* > err = 2 "Guaranteed" error bound: The estimated forward error, */
/* > almost certainly within a factor of 10 of the true error */
/* > so long as the next entry is greater than the threshold */
/* > sqrt(n) * slamch('Epsilon'). This error bound should only */
/* > be trusted if the previous boolean is true. */
/* > */
/* > err = 3 Reciprocal condition number: Estimated normwise */
/* > reciprocal condition number. Compared with the threshold */
/* > sqrt(n) * slamch('Epsilon') to determine if the error */
/* > estimate is "guaranteed". These reciprocal condition */
/* > numbers are 1 / (norm(Z^{
-1}
,inf) * norm(Z,inf)) for some */
/* > appropriately scaled matrix Z. */
/* > Let Z = S*A, where S scales each row by a power of the */
/* > radix so all absolute row sums of Z are approximately 1. */
/* > */
/* > This subroutine is only responsible for setting the second field */
/* > above. */
/* > See Lapack Working Note 165 for further details and extra */
/* > cautions. */
/* > \endverbatim */
/* > */
/* > \param[in,out] ERR_BNDS_COMP */
/* > \verbatim */
/* > ERR_BNDS_COMP is DOUBLE PRECISION array, dimension */
/* > (NRHS, N_ERR_BNDS) */
/* > For each right-hand side, this array contains information about */
/* > various error bounds and condition numbers corresponding to the */
/* > componentwise relative error, which is defined as follows: */
/* > */
/* > Componentwise relative error in the ith solution vector: */
/* > f2c_abs(XTRUE(j,i) - X(j,i)) */
/* > max_j ---------------------- */
/* > f2c_abs(X(j,i)) */
/* > */
/* > The array is indexed by the right-hand side i (on which the */
/* > componentwise relative error depends), and the type of error */
/* > information as described below. There currently are up to three */
/* > pieces of information returned for each right-hand side. If */
/* > componentwise accuracy is not requested (PARAMS(3) = 0.0), then */
/* > ERR_BNDS_COMP is not accessed. If N_ERR_BNDS .LT. 3, then at most */
/* > the first (:,N_ERR_BNDS) entries are returned. */
/* > */
/* > The first index in ERR_BNDS_COMP(i,:) corresponds to the ith */
/* > right-hand side. */
/* > */
/* > The second index in ERR_BNDS_COMP(:,err) contains the following */
/* > three fields: */
/* > err = 1 "Trust/don't trust" boolean. Trust the answer if the */
/* > reciprocal condition number is less than the threshold */
/* > sqrt(n) * slamch('Epsilon'). */
/* > */
/* > err = 2 "Guaranteed" error bound: The estimated forward error, */
/* > almost certainly within a factor of 10 of the true error */
/* > so long as the next entry is greater than the threshold */
/* > sqrt(n) * slamch('Epsilon'). This error bound should only */
/* > be trusted if the previous boolean is true. */
/* > */
/* > err = 3 Reciprocal condition number: Estimated componentwise */
/* > reciprocal condition number. Compared with the threshold */
/* > sqrt(n) * slamch('Epsilon') to determine if the error */
/* > estimate is "guaranteed". These reciprocal condition */
/* > numbers are 1 / (norm(Z^{
-1}
,inf) * norm(Z,inf)) for some */
/* > appropriately scaled matrix Z. */
/* > Let Z = S*(A*diag(x)), where x is the solution for the */
/* > current right-hand side and S scales each row of */
/* > A*diag(x) by a power of the radix so all absolute row */
/* > sums of Z are approximately 1. */
/* > */
/* > This subroutine is only responsible for setting the second field */
/* > above. */
/* > See Lapack Working Note 165 for further details and extra */
/* > cautions. */
/* > \endverbatim */
/* > */
/* > \param[in] RES */
/* > \verbatim */
/* > RES is COMPLEX*16 array, dimension (N) */
/* > Workspace to hold the intermediate residual. */
/* > \endverbatim */
/* > */
/* > \param[in] AYB */
/* > \verbatim */
/* > AYB is DOUBLE PRECISION array, dimension (N) */
/* > Workspace. */
/* > \endverbatim */
/* > */
/* > \param[in] DY */
/* > \verbatim */
/* > DY is COMPLEX*16 array, dimension (N) */
/* > Workspace to hold the intermediate solution. */
/* > \endverbatim */
/* > */
/* > \param[in] Y_TAIL */
/* > \verbatim */
/* > Y_TAIL is COMPLEX*16 array, dimension (N) */
/* > Workspace to hold the trailing bits of the intermediate solution. */
/* > \endverbatim */
/* > */
/* > \param[in] RCOND */
/* > \verbatim */
/* > RCOND is DOUBLE PRECISION */
/* > Reciprocal scaled condition number. This is an estimate of the */
/* > reciprocal Skeel condition number of the matrix A after */
/* > equilibration (if done). If this is less than the machine */
/* > precision (in particular, if it is zero), the matrix is singular */
/* > to working precision. Note that the error may still be small even */
/* > if this number is very small and the matrix appears ill- */
/* > conditioned. */
/* > \endverbatim */
/* > */
/* > \param[in] ITHRESH */
/* > \verbatim */
/* > ITHRESH is INTEGER */
/* > The maximum number of residual computations allowed for */
/* > refinement. The default is 10. For 'aggressive' set to 100 to */
/* > permit convergence using approximate factorizations or */
/* > factorizations other than LU. If the factorization uses a */
/* > technique other than Gaussian elimination, the guarantees in */
/* > ERR_BNDS_NORM and ERR_BNDS_COMP may no longer be trustworthy. */
/* > \endverbatim */
/* > */
/* > \param[in] RTHRESH */
/* > \verbatim */
/* > RTHRESH is DOUBLE PRECISION */
/* > Determines when to stop refinement if the error estimate stops */
/* > decreasing. Refinement will stop when the next solution no longer */
/* > satisfies norm(dx_{
i+1}
) < RTHRESH * norm(dx_i) where norm(Z) is */
/* > the infinity norm of Z. RTHRESH satisfies 0 < RTHRESH <= 1. The */
/* > default value is 0.5. For 'aggressive' set to 0.9 to permit */
/* > convergence on extremely ill-conditioned matrices. See LAWN 165 */
/* > for more details. */
/* > \endverbatim */
/* > */
/* > \param[in] DZ_UB */
/* > \verbatim */
/* > DZ_UB is DOUBLE PRECISION */
/* > Determines when to start considering componentwise convergence. */
/* > Componentwise convergence is only considered after each component */
/* > of the solution Y is stable, which we definte as the relative */
/* > change in each component being less than DZ_UB. The default value */
/* > is 0.25, requiring the first bit to be stable. See LAWN 165 for */
/* > more details. */
/* > \endverbatim */
/* > */
/* > \param[in] IGNORE_CWISE */
/* > \verbatim */
/* > IGNORE_CWISE is LOGICAL */
/* > If .TRUE. then ignore componentwise convergence. Default value */
/* > is .FALSE.. */
/* > \endverbatim */
/* > */
/* > \param[out] INFO */
/* > \verbatim */
/* > INFO is INTEGER */
/* > = 0: Successful exit. */
/* > < 0: if INFO = -i, the ith argument to ZGBTRS had an illegal */
/* > value */
/* > \endverbatim */
/* Authors: */
/* ======== */
/* > \author Univ. of Tennessee */
/* > \author Univ. of California Berkeley */
/* > \author Univ. of Colorado Denver */
/* > \author NAG Ltd. */
/* > \date September 2012 */
/* > \ingroup complex16GBcomputational */
/* ===================================================================== */
/* Subroutine */
int zla_gbrfsx_extended_(integer *prec_type__, integer * trans_type__, integer *n, integer *kl, integer *ku, integer *nrhs, doublecomplex *ab, integer *ldab, doublecomplex *afb, integer *ldafb, integer *ipiv, logical *colequ, doublereal *c__, doublecomplex *b, integer *ldb, doublecomplex *y, integer *ldy, doublereal *berr_out__, integer *n_norms__, doublereal *err_bnds_norm__, doublereal * err_bnds_comp__, doublecomplex *res, doublereal *ayb, doublecomplex * dy, doublecomplex *y_tail__, doublereal *rcond, integer *ithresh, doublereal *rthresh, doublereal *dz_ub__, logical *ignore_cwise__, integer *info)
{
    /* System generated locals */
    integer ab_dim1, ab_offset, afb_dim1, afb_offset, b_dim1, b_offset, y_dim1, y_offset, err_bnds_norm_dim1, err_bnds_norm_offset, err_bnds_comp_dim1, err_bnds_comp_offset, i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;
    char ch__1[1];
    /* Builtin functions */
    double d_imag(doublecomplex *);
    /* Local variables */
    doublereal dxratmax, dzratmax;
    integer i__, j, m;
    extern /* Subroutine */
    int zla_gbamv_(integer *, integer *, integer *, integer *, integer *, doublereal *, doublecomplex *, integer *, doublecomplex *, integer *, doublereal *, doublereal *, integer *) ;
    logical incr_prec__;
    doublereal prev_dz_z__, yk, final_dx_x__, final_dz_z__;
    extern /* Subroutine */
    int zla_wwaddw_(integer *, doublecomplex *, doublecomplex *, doublecomplex *);
    doublereal prevnormdx;
    integer cnt;
    doublereal dyk, eps, incr_thresh__, dx_x__, dz_z__, ymin;
    extern /* Subroutine */
    int zla_lin_berr_(integer *, integer *, integer * , doublecomplex *, doublereal *, doublereal *), blas_zgbmv_x_( integer *, integer *, integer *, integer *, integer *, doublecomplex *, doublecomplex *, integer *, doublecomplex *, integer *, doublecomplex *, doublecomplex *, integer *, integer *) ;
    integer y_prec_state__;
    extern /* Subroutine */
    int blas_zgbmv2_x_(integer *, integer *, integer *, integer *, integer *, doublecomplex *, doublecomplex *, integer *, doublecomplex *, doublecomplex *, integer *, doublecomplex *, doublecomplex *, integer *, integer *);
    doublereal dxrat, dzrat;
    extern /* Subroutine */
    int zgbmv_(char *, integer *, integer *, integer * , integer *, doublecomplex *, doublecomplex *, integer *, doublecomplex *, integer *, doublecomplex *, doublecomplex *, integer *);
    char trans[1];
    doublereal normx, normy;
    extern /* Subroutine */
    int zcopy_(integer *, doublecomplex *, integer *, doublecomplex *, integer *), zaxpy_(integer *, doublecomplex *, doublecomplex *, integer *, doublecomplex *, integer *);
    extern doublereal dlamch_(char *);
    doublereal normdx;
    extern /* Subroutine */
    int zgbtrs_(char *, integer *, integer *, integer *, integer *, doublecomplex *, integer *, integer *, doublecomplex *, integer *, integer *);
    extern /* Character */
    VOID chla_transtype_(char *, integer *);
    doublereal hugeval;
    integer x_state__, z_state__;
    /* -- LAPACK computational routine (version 3.4.2) -- */
    /* -- LAPACK is a software package provided by Univ. of Tennessee, -- */
    /* -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..-- */
    /* September 2012 */
    /* .. Scalar Arguments .. */
    /* .. */
    /* .. Array Arguments .. */
    /* .. */
    /* ===================================================================== */
    /* .. Local Scalars .. */
    /* .. */
    /* .. Parameters .. */
    /* .. */
    /* .. External Subroutines .. */
    /* .. */
    /* .. Intrinsic Functions.. */
    /* .. */
    /* .. Statement Functions .. */
    /* .. */
    /* .. Statement Function Definitions .. */
    /* .. */
    /* .. Executable Statements .. */
    /* Parameter adjustments */
    err_bnds_comp_dim1 = *nrhs;
    err_bnds_comp_offset = 1 + err_bnds_comp_dim1;
    err_bnds_comp__ -= err_bnds_comp_offset;
    err_bnds_norm_dim1 = *nrhs;
    err_bnds_norm_offset = 1 + err_bnds_norm_dim1;
    err_bnds_norm__ -= err_bnds_norm_offset;
    ab_dim1 = *ldab;
    ab_offset = 1 + ab_dim1;
    ab -= ab_offset;
    afb_dim1 = *ldafb;
    afb_offset = 1 + afb_dim1;
    afb -= afb_offset;
    --ipiv;
    --c__;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    y_dim1 = *ldy;
    y_offset = 1 + y_dim1;
    y -= y_offset;
    --berr_out__;
    --res;
    --ayb;
    --dy;
    --y_tail__;
    /* Function Body */
    if (*info != 0)
    {
        return 0;
    }
    chla_transtype_(ch__1, trans_type__);
    *(unsigned char *)trans = *(unsigned char *)&ch__1[0];
    eps = dlamch_("Epsilon");
    hugeval = dlamch_("Overflow");
    /* Force HUGEVAL to Inf */
    hugeval *= hugeval;
    /* Using HUGEVAL may lead to spurious underflows. */
    incr_thresh__ = (doublereal) (*n) * eps;
    m = *kl + *ku + 1;
    i__1 = *nrhs;
    for (j = 1;
            j <= i__1;
            ++j)
    {
        y_prec_state__ = 1;
        if (y_prec_state__ == 2)
        {
            i__2 = *n;
            for (i__ = 1;
                    i__ <= i__2;
                    ++i__)
            {
                i__3 = i__;
                y_tail__[i__3].r = 0.;
                y_tail__[i__3].i = 0.; // , expr subst
            }
        }
        dxrat = 0.;
        dxratmax = 0.;
        dzrat = 0.;
        dzratmax = 0.;
        final_dx_x__ = hugeval;
        final_dz_z__ = hugeval;
        prevnormdx = hugeval;
        prev_dz_z__ = hugeval;
        dz_z__ = hugeval;
        dx_x__ = hugeval;
        x_state__ = 1;
        z_state__ = 0;
        incr_prec__ = FALSE_;
        i__2 = *ithresh;
        for (cnt = 1;
                cnt <= i__2;
                ++cnt)
        {
            /* Compute residual RES = B_s - op(A_s) * Y, */
            /* op(A) = A, A**T, or A**H depending on TRANS (and type). */
            zcopy_(n, &b[j * b_dim1 + 1], &c__1, &res[1], &c__1);
            if (y_prec_state__ == 0)
            {
                zgbmv_(trans, &m, n, kl, ku, &c_b6, &ab[ab_offset], ldab, &y[ j * y_dim1 + 1], &c__1, &c_b8, &res[1], &c__1);
            }
            else if (y_prec_state__ == 1)
            {
                blas_zgbmv_x_(trans_type__, n, n, kl, ku, &c_b6, &ab[ ab_offset], ldab, &y[j * y_dim1 + 1], &c__1, &c_b8, & res[1], &c__1, prec_type__);
            }
            else
            {
                blas_zgbmv2_x_(trans_type__, n, n, kl, ku, &c_b6, &ab[ ab_offset], ldab, &y[j * y_dim1 + 1], &y_tail__[1], & c__1, &c_b8, &res[1], &c__1, prec_type__);
            }
            /* XXX: RES is no longer needed. */
            zcopy_(n, &res[1], &c__1, &dy[1], &c__1);
            zgbtrs_(trans, n, kl, ku, &c__1, &afb[afb_offset], ldafb, &ipiv[1] , &dy[1], n, info);
            /* Calculate relative changes DX_X, DZ_Z and ratios DXRAT, DZRAT. */
            normx = 0.;
            normy = 0.;
            normdx = 0.;
            dz_z__ = 0.;
            ymin = hugeval;
            i__3 = *n;
            for (i__ = 1;
                    i__ <= i__3;
                    ++i__)
            {
                i__4 = i__ + j * y_dim1;
                yk = (d__1 = y[i__4].r, f2c_abs(d__1)) + (d__2 = d_imag(&y[i__ + j * y_dim1]), f2c_abs(d__2));
                i__4 = i__;
                dyk = (d__1 = dy[i__4].r, f2c_abs(d__1)) + (d__2 = d_imag(&dy[i__] ), f2c_abs(d__2));
                if (yk != 0.)
                {
                    /* Computing MAX */
                    d__1 = dz_z__;
                    d__2 = dyk / yk; // , expr subst
                    dz_z__ = max(d__1,d__2);
                }
                else if (dyk != 0.)
                {
                    dz_z__ = hugeval;
                }
                ymin = min(ymin,yk);
                normy = max(normy,yk);
                if (*colequ)
                {
                    /* Computing MAX */
                    d__1 = normx;
                    d__2 = yk * c__[i__]; // , expr subst
                    normx = max(d__1,d__2);
                    /* Computing MAX */
                    d__1 = normdx;
                    d__2 = dyk * c__[i__]; // , expr subst
                    normdx = max(d__1,d__2);
                }
                else
                {
                    normx = normy;
                    normdx = max(normdx,dyk);
                }
            }
            if (normx != 0.)
            {
                dx_x__ = normdx / normx;
            }
            else if (normdx == 0.)
            {
                dx_x__ = 0.;
            }
            else
            {
                dx_x__ = hugeval;
            }
            dxrat = normdx / prevnormdx;
            dzrat = dz_z__ / prev_dz_z__;
            /* Check termination criteria. */
            if (! (*ignore_cwise__) && ymin * *rcond < incr_thresh__ * normy && y_prec_state__ < 2)
            {
                incr_prec__ = TRUE_;
            }
            if (x_state__ == 3 && dxrat <= *rthresh)
            {
                x_state__ = 1;
            }
            if (x_state__ == 1)
            {
                if (dx_x__ <= eps)
                {
                    x_state__ = 2;
                }
                else if (dxrat > *rthresh)
                {
                    if (y_prec_state__ != 2)
                    {
                        incr_prec__ = TRUE_;
                    }
                    else
                    {
                        x_state__ = 3;
                    }
                }
                else
                {
                    if (dxrat > dxratmax)
                    {
                        dxratmax = dxrat;
                    }
                }
                if (x_state__ > 1)
                {
                    final_dx_x__ = dx_x__;
                }
            }
            if (z_state__ == 0 && dz_z__ <= *dz_ub__)
            {
                z_state__ = 1;
            }
            if (z_state__ == 3 && dzrat <= *rthresh)
            {
                z_state__ = 1;
            }
            if (z_state__ == 1)
            {
                if (dz_z__ <= eps)
                {
                    z_state__ = 2;
                }
                else if (dz_z__ > *dz_ub__)
                {
                    z_state__ = 0;
                    dzratmax = 0.;
                    final_dz_z__ = hugeval;
                }
                else if (dzrat > *rthresh)
                {
                    if (y_prec_state__ != 2)
                    {
                        incr_prec__ = TRUE_;
                    }
                    else
                    {
                        z_state__ = 3;
                    }
                }
                else
                {
                    if (dzrat > dzratmax)
                    {
                        dzratmax = dzrat;
                    }
                }
                if (z_state__ > 1)
                {
                    final_dz_z__ = dz_z__;
                }
            }
            /* Exit if both normwise and componentwise stopped working, */
            /* but if componentwise is unstable, let it go at least two */
            /* iterations. */
            if (x_state__ != 1)
            {
                if (*ignore_cwise__)
                {
                    goto L666;
                }
                if (z_state__ == 3 || z_state__ == 2)
                {
                    goto L666;
                }
                if (z_state__ == 0 && cnt > 1)
                {
                    goto L666;
                }
            }
            if (incr_prec__)
            {
                incr_prec__ = FALSE_;
                ++y_prec_state__;
                i__3 = *n;
                for (i__ = 1;
                        i__ <= i__3;
                        ++i__)
                {
                    i__4 = i__;
                    y_tail__[i__4].r = 0.;
                    y_tail__[i__4].i = 0.; // , expr subst
                }
            }
            prevnormdx = normdx;
            prev_dz_z__ = dz_z__;
            /* Update soluton. */
            if (y_prec_state__ < 2)
            {
                zaxpy_(n, &c_b8, &dy[1], &c__1, &y[j * y_dim1 + 1], &c__1);
            }
            else
            {
                zla_wwaddw_(n, &y[j * y_dim1 + 1], &y_tail__[1], &dy[1]);
            }
        }
        /* Target of "IF (Z_STOP .AND. X_STOP)". Sun's f77 won't CALL F90_EXIT. */
L666: /* Set final_* when cnt hits ithresh. */
        if (x_state__ == 1)
        {
            final_dx_x__ = dx_x__;
        }
        if (z_state__ == 1)
        {
            final_dz_z__ = dz_z__;
        }
        /* Compute error bounds. */
        if (*n_norms__ >= 1)
        {
            err_bnds_norm__[j + (err_bnds_norm_dim1 << 1)] = final_dx_x__ / ( 1 - dxratmax);
        }
        if (*n_norms__ >= 2)
        {
            err_bnds_comp__[j + (err_bnds_comp_dim1 << 1)] = final_dz_z__ / ( 1 - dzratmax);
        }
        /* Compute componentwise relative backward error from formula */
        /* max(i) ( f2c_abs(R(i)) / ( f2c_abs(op(A_s))*f2c_abs(Y) + f2c_abs(B_s) )(i) ) */
        /* where f2c_abs(Z) is the componentwise absolute value of the matrix */
        /* or vector Z. */
        /* Compute residual RES = B_s - op(A_s) * Y, */
        /* op(A) = A, A**T, or A**H depending on TRANS (and type). */
        zcopy_(n, &b[j * b_dim1 + 1], &c__1, &res[1], &c__1);
        zgbmv_(trans, n, n, kl, ku, &c_b6, &ab[ab_offset], ldab, &y[j * y_dim1 + 1], &c__1, &c_b8, &res[1], &c__1);
        i__2 = *n;
        for (i__ = 1;
                i__ <= i__2;
                ++i__)
        {
            i__3 = i__ + j * b_dim1;
            ayb[i__] = (d__1 = b[i__3].r, f2c_abs(d__1)) + (d__2 = d_imag(&b[i__ + j * b_dim1]), f2c_abs(d__2));
        }
        /* Compute f2c_abs(op(A_s))*f2c_abs(Y) + f2c_abs(B_s). */
        zla_gbamv_(trans_type__, n, n, kl, ku, &c_b31, &ab[ab_offset], ldab, &y[j * y_dim1 + 1], &c__1, &c_b31, &ayb[1], &c__1);
        zla_lin_berr_(n, n, &c__1, &res[1], &ayb[1], &berr_out__[j]);
        /* End of loop for each RHS. */
    }
    return 0;
}
/* zla_gbrfsx_extended__ */
#endif