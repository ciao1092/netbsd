/*	$NetBSD: w_acosf.c,v 1.8 2024/06/09 13:35:38 riastradh Exp $	*/

/*
 * w_acosf.c -- float version of w_acos.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#include <sys/cdefs.h>
#if defined(LIBM_SCCS) && !defined(lint)
__RCSID("$NetBSD: w_acosf.c,v 1.8 2024/06/09 13:35:38 riastradh Exp $");
#endif

/*
 * wrap_acosf(x)
 */

#include "namespace.h"

#include "math.h"
#include "math_private.h"

__weak_alias(acosf, _acosf)

float
acosf(float x)		/* wrapper acosf */
{
#ifdef _IEEE_LIBM
	return __ieee754_acosf(x);
#else
	float z;
	z = __ieee754_acosf(x);
	if(_LIB_VERSION == _IEEE_ || isnanf(x)) return z;
	if(fabsf(x)>(float)1.0) {
	        /* acosf(|x|>1) */
	        return (float)__kernel_standard((double)x,(double)x,101);
	} else
	    return z;
#endif
}
