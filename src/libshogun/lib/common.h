/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2009 Soeren Sonnenburg
 * Written (W) 1999-2008 Gunnar Raetsch
 * Written (W) 2006 Fabio De Bona
 * Written (W) 2006 Konrad Rieck
 * Written (W) 2006-2008 Christian Gehl
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "lib/memory.h"

#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdlib.h>
#include <stdio.h>
#include "lib/config.h"

#ifndef LINUX
#define RANDOM_MAX 2147483647
#else
#define RANDOM_MAX RAND_MAX
#endif

/**@name Standard Types
 * Definition of Platform independent Types
*/
//@{

#include <stdint.h>

/* No feature test:
 * ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 *
 * If not supported make sure that your development environment is
 * supporting ISO C99!
 */
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>

/**
 * Implementations tend to follow IEEE754
 * @see http://ieeexplore.ieee.org/xpl/freeabs_all.jsp?arnumber=4610935
 */
typedef float float32_t;
typedef double float64_t;
typedef long double floatmax_t;

//@}

#ifdef HAVE_BOOST_SERIALIZATION

#define GLOBAL_BOOST_SERIALIZATION_SPLIT_MEMBER()                  \
template<class Archive>                                            \
void serialize(Archive &ar, const unsigned int file_version)       \
{                                                                  \
    ::boost::serialization::split_member(ar, *this, file_version); \
}
/**/

#define GLOBAL_BOOST_CLASS_EXPORT_KEY(T)                           \
    BOOST_CLASS_EXPORT_KEY2(T, BOOST_PP_STRINGIZE(T))              \
/**/


#endif //HAVE_BOOST_SERIALIZATION

#define STRING_LEN                 256
#define STRING_LEN_STR             "256"
typedef char                       string_t[STRING_LEN];

typedef int                        machine_int_t;

#endif //__COMMON_H__
