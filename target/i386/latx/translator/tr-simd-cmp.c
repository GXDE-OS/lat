#include "common.h"
#include "reg-alloc.h"
#include "latx-options.h"
#include "translate.h"
#include "env.h"

bool translate_pcmpeqb(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_b(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_b(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpeqw(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_h(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_h(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpeqd(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vseq_w(dest, dest, src);
    } else { //mmx
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vseq_w(dest_lo, dest_lo, src_lo);
    }
    return true;
}

bool translate_pcmpgtb(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_b(dest, src, dest);
        return true;
    } else {
        /* transfer_to_mmx_mode */
        transfer_to_mmx_mode();

        IR2_OPND dest_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
        IR2_OPND src_lo =
            load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
        la_vslt_b(dest_lo, src_lo, dest_lo);
    }
    return true;
}

bool translate_pcmpgtw(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_h(dest, src, dest);
        return true;
    }
    /* transfer_to_mmx_mode */
    transfer_to_mmx_mode();

    IR2_OPND dest_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
    IR2_OPND src_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
    la_vslt_h(dest_lo, src_lo, dest_lo);
    return true;
}

bool translate_pcmpgtd(IR1_INST *pir1)
{
    if (ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0))) {
        IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
        IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
        la_vslt_w(dest, src, dest);
        return true;
    }
    /* transfer_to_mmx_mode */
    transfer_to_mmx_mode();

    IR2_OPND dest_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 0), false, IS_INTEGER);
    IR2_OPND src_lo =
        load_freg_from_ir1_1(ir1_get_opnd(pir1, 1), false, IS_INTEGER);
    la_vslt_w(dest_lo, src_lo, dest_lo);
    return true;
}

bool translate_pcmpgtq(IR1_INST *pir1)
{
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vslt_d(dest, src, dest);
    return true;
}

bool translate_cmpeqpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_EQ);
    return true;
}

bool translate_cmpltpd(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_LT);
    return true;
}

bool translate_cmplepd(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_LE);
    return true;
}

bool translate_cmpunordpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_UNORD);
    return true;
}

bool translate_cmpneqpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_NEQ);
    return true;
}

bool translate_cmpnltpd(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_d(dest, src, dest, X86_FCMP_COND_NLT);
    return true;
}

bool translate_cmpnlepd(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_d(dest, src, dest, X86_FCMP_COND_NLE);
    return true;
}

bool translate_cmpordpd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_d(dest, dest, src, X86_FCMP_COND_ORD);
    return true;
}

bool translate_cmpeqps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_EQ);
    return true;
}

bool translate_cmpltps(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_LT);
    return true;
}

bool translate_cmpleps(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_LE);
    return true;
}

bool translate_cmpunordps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_UNORD);
    return true;
}

bool translate_cmpneqps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_NEQ);
    return true;
}

bool translate_cmpnltps(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_s(dest, src, dest, X86_FCMP_COND_NLT);
    return true;
}

bool translate_cmpnleps(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_s(dest, src, dest, X86_FCMP_COND_NLE);
    return true;
}

bool translate_cmpordps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    la_vfcmp_cond_s(dest, dest, src, X86_FCMP_COND_ORD);
    return true;
}
bool translate_cmpps(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqps(pir1);
    case 1:
        return translate_cmpltps(pir1);
    case 2:
        return translate_cmpleps(pir1);
    case 3:
        return translate_cmpunordps(pir1);
    case 4:
        return translate_cmpneqps(pir1);
    case 5:
        return translate_cmpnltps(pir1);
    case 6:
        return translate_cmpnleps(pir1);
    case 7:
        return translate_cmpordps(pir1);
    default:
        lsassert(0);
    }
    return true;
}


bool translate_cmpeqsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_EQ);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpltsd(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LT);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmplesd(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LE);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpunordsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_UNORD);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpneqsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_NEQ);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

/**
 * NOTE:
 * LA has no condition of nlt, it is replaced by sule,
 * and the order of dest and src operand needs to be swapped.
 */
bool translate_cmpnltsd(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLT);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

/**
 * NOTE:
 * LA has no condition of nle, it is replaced by sult,
 * and the order of dest and src operand needs to be swapped.
 */
bool translate_cmpnlesd(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLE);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpordsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_d(src_temp, src, zero_ir2_opnd);
    la_vreplve_d(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_d(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_ORD);
    if (option_enable_lasx) {
        la_xvinsve0_d(dest, dest_transfer, 0);
    } else {
        la_vextrins_d(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpeqss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));

    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_EQ);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpltss(IR1_INST *pir1)
{
    /* LT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LT);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpless(IR1_INST *pir1)
{
    /* LE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_LE);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);
    return true;
}

bool translate_cmpunordss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_UNORD);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpneqss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_NEQ);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpnltss(IR1_INST *pir1)
{
    /* NLT will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    /* A !< B & UOR == B <= A & UOR */
    la_vfcmp_cond_s(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLT);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpnless(IR1_INST *pir1)
{
    /* NLE will cause QNaN Exception */
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    /* A !<= B & UOR == B < A & UOR */
    la_vfcmp_cond_s(dest_transfer, src_temp, dest_temp, X86_FCMP_COND_NLE);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    ra_free_temp(src_temp);
    ra_free_temp(dest_temp);
    ra_free_temp(dest_transfer);

    return true;
}

bool translate_cmpordss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_is_xmm(ir1_get_opnd(pir1, 0)));
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    IR2_OPND src_temp = ra_alloc_ftemp();
    IR2_OPND dest_temp = ra_alloc_ftemp();
    IR2_OPND dest_transfer = ra_alloc_ftemp();

    la_vreplve_w(src_temp, src, zero_ir2_opnd);
    la_vreplve_w(dest_temp, dest, zero_ir2_opnd);
    la_vfcmp_cond_s(dest_transfer, dest_temp, src_temp, X86_FCMP_COND_ORD);
    if (option_enable_lasx) {
        la_xvinsve0_w(dest, dest_transfer, 0);
    } else {
        la_vextrins_w(dest, dest_transfer, 0);
    }

    return true;
}

bool translate_cmpss(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqss(pir1);
    case 1:
        return translate_cmpltss(pir1);
    case 2:
        return translate_cmpless(pir1);
    case 3:
        return translate_cmpunordss(pir1);
    case 4:
        return translate_cmpneqss(pir1);
    case 5:
        return translate_cmpnltss(pir1);
    case 6:
        return translate_cmpnless(pir1);
    case 7:
        return translate_cmpordss(pir1);
    default:
        lsassert(0);
    }
    return true;
}


bool translate_cmppd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqpd(pir1);
    case 1:
        return translate_cmpltpd(pir1);
    case 2:
        return translate_cmplepd(pir1);
    case 3:
        return translate_cmpunordpd(pir1);
    case 4:
        return translate_cmpneqpd(pir1);
    case 5:
        return translate_cmpnltpd(pir1);
    case 6:
        return translate_cmpnlepd(pir1);
    case 7:
        return translate_cmpordpd(pir1);
    default:
        lsassert(0);
    }
    return true;
}

#ifdef CONFIG_LATX_XCOMISX_OPT
#define ZPCF_USEDEF_BIT (ZF_USEDEF_BIT | PF_USEDEF_BIT | CF_USEDEF_BIT)
#define OASF_USEDEF_BIT (OF_USEDEF_BIT | AF_USEDEF_BIT | SF_USEDEF_BIT)
#define OASF_BIT        (OF_BIT | AF_BIT | SF_BIT)

void generate_xcomisx(IR2_OPND src0, IR2_OPND src1, bool is_double,
                      bool qnan_exp, uint8_t eflags)
{
    lsassert(!(eflags & ~(ZPCF_USEDEF_BIT | OASF_USEDEF_BIT)));
    bool calc_zpc = !!(ZPCF_USEDEF_BIT & eflags);
    bool calc_oas = !!(OASF_USEDEF_BIT & eflags);
    /* 1. all need not calculate */
    if (!calc_zpc & !calc_oas)
        return;
    /* 
     * 2. Only OF/AF/SF need calculate
     *    hint: ZF/PF/CF will clear OF/AF/SF
     */
    if (!calc_zpc && calc_oas) {
        /* clear OF/AF/SF manually */
        la_x86mtflag(zero_ir2_opnd, OASF_USEDEF_BIT);
        return;
    }

    bool calc_zf = !!(ZF_USEDEF_BIT & eflags);
    bool calc_pf = !!(PF_USEDEF_BIT & eflags);
    bool calc_cf = !!(CF_USEDEF_BIT & eflags);

    /**
     * 3. ZF/PF/CF need calculate
     * (bit 6)ZF = 1 if EQ || UOR
     * (bit 2)PF = 1 if UOR (= ZF & CF)
     * (bit 0)CF = 1 if LT || UOR
     */

    IR2_OPND flag_zf = ra_alloc_itemp();
    IR2_OPND flag_pf = ra_alloc_itemp();
    IR2_OPND flags   = ra_alloc_itemp();

    lsassert(calc_zpc);
    /* 3.0. set flag = 0 */
    if (calc_oas)
        la_mov64(flags, zero_ir2_opnd);

    /* 3.1. check CF, are they less & unordered? */
    if (calc_cf) {
        if (is_double)
            la_fcmp_cond_d(fcc1_ir2_opnd, src0, src1, FCMP_COND_CULT + qnan_exp);
        else
            la_fcmp_cond_s(fcc1_ir2_opnd, src0, src1, FCMP_COND_CULT + qnan_exp);
        la_movcf2gr(flags, fcc1_ir2_opnd);
    }

    /* 3.2. check ZF, are they equal & unordered? */
    if (calc_zf) {
        if (is_double)
            la_fcmp_cond_d(fcc0_ir2_opnd, src0, src1, FCMP_COND_CUEQ + qnan_exp);
        else
            la_fcmp_cond_s(fcc0_ir2_opnd, src0, src1, FCMP_COND_CUEQ + qnan_exp);
        la_movcf2gr(flag_zf, fcc0_ir2_opnd);
        la_bstrins_w(flags, flag_zf, ZF_BIT_INDEX, ZF_BIT_INDEX);
    }

    /* 3.3. check PF, are they unordered? (= ZF & CF) */
    if (calc_pf) {
        if (calc_zf && calc_cf) {
            la_and(flag_pf, flags, flag_zf);
        } else {
            if (is_double)
                la_fcmp_cond_d(fcc2_ir2_opnd, src0, src1,
                               FCMP_COND_CUN + qnan_exp);
            else
                la_fcmp_cond_s(fcc2_ir2_opnd, src0, src1,
                               FCMP_COND_CUN + qnan_exp);
            la_movcf2gr(flag_pf, fcc2_ir2_opnd);
        }
        la_bstrins_w(flags, flag_pf, PF_BIT_INDEX, PF_BIT_INDEX);
    }

    /* 3.4. mov flag to EFLAGS */
    lsassert(calc_zpc);
    la_x86mtflag(flags, eflags);

    ra_free_temp(flag_pf);
    ra_free_temp(flag_zf);
    ra_free_temp(flags);
}

#undef ZPCF_USEDEF_BIT
#undef OASF_USEDEF_BIT
#undef OASF_BIT

bool translate_xcomisx(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 2);
    IR2_OPND src0 = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src1 = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    generate_eflag_calculation(src0, src0, src1, pir1, false);
    return true;
}

#endif
static inline void xcomisx(IR1_INST *pir1, bool is_double, bool qnan_exp)
{
    /**
     * (bit 6)ZF = 1 if EQ || UOR
     * (bit 2)PF = 1 if UOR (= ZF & CF)
     * (bit 0)CF = 1 if LT || UOR
     */
    lsassert(ir1_opnd_num(pir1) == 2);
    IR2_OPND dest = load_freg128_from_ir1(ir1_get_opnd(pir1, 0));
    IR2_OPND src = load_freg128_from_ir1(ir1_get_opnd(pir1, 1));
    /* 0. set flag = 0 */
    IR2_OPND flag_zf = ra_alloc_itemp();
    IR2_OPND flag_pf = ra_alloc_itemp();
    IR2_OPND flag = ra_alloc_itemp();
    la_mov64(flag, zero_ir2_opnd);

    /* 1. check ZF, are they equal & unordered? */
    if (is_double) {
        la_fcmp_cond_d(fcc0_ir2_opnd, dest, src, FCMP_COND_CUEQ + qnan_exp);
    } else {
        la_fcmp_cond_s(fcc0_ir2_opnd, dest, src, FCMP_COND_CUEQ + qnan_exp);
    }
    la_movcf2gr(flag_zf, fcc0_ir2_opnd);

    /* 2. check CF, are they less & unordered? */
    if (is_double) {
        la_fcmp_cond_d(fcc2_ir2_opnd, dest, src, FCMP_COND_CULT + qnan_exp);
    } else {
        la_fcmp_cond_s(fcc2_ir2_opnd, dest, src, FCMP_COND_CULT + qnan_exp);
    }
    la_movcf2gr(flag, fcc2_ir2_opnd);

    /* 3. check PF, are they unordered? (= ZF & CF) */
    la_and(flag_pf, flag, flag_zf);

    la_bstrins_w(flag, flag_zf, ZF_BIT_INDEX, ZF_BIT_INDEX);
    la_bstrins_w(flag, flag_pf, PF_BIT_INDEX, PF_BIT_INDEX);

    /* 4. mov flag to EFLAGS */
    la_x86mtflag(flag, 0x3f);

    ra_free_temp(flag_pf);
    ra_free_temp(flag_zf);
    ra_free_temp(flag);

}

bool translate_comisd(IR1_INST *pir1)
{
    xcomisx(pir1, true, true);
    return true;
}

bool translate_comiss(IR1_INST *pir1)
{
    xcomisx(pir1, false, true);
    return true;
}

bool translate_ucomisd(IR1_INST *pir1)
{
    xcomisx(pir1, true, false);
    return true;
}

bool translate_ucomiss(IR1_INST *pir1)
{
    xcomisx(pir1, false, false);
    return true;
}

bool translate_cmpsd(IR1_INST *pir1)
{
    lsassert(ir1_opnd_num(pir1) == 3);
    IR1_OPND *opnd2 = ir1_get_opnd(pir1, 2);
    lsassert(ir1_opnd_is_imm(opnd2));
    uint8 predicate = ir1_opnd_uimm(opnd2) & 0x7;
    switch (predicate) {
    case 0:
        return translate_cmpeqsd(pir1);
    case 1:
        return translate_cmpltsd(pir1);
    case 2:
        return translate_cmplesd(pir1);
    case 3:
        return translate_cmpunordsd(pir1);
    case 4:
        return translate_cmpneqsd(pir1);
    case 5:
        return translate_cmpnltsd(pir1);
    case 6:
        return translate_cmpnlesd(pir1);
    case 7:
        return translate_cmpordsd(pir1);
    default:
        lsassert(0);
    }
    return true;
}