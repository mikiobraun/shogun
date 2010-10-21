/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2010 Soeren Sonnenburg
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 * Copyright (C) 2010 Berlin Institute of Technology
 */

#include "lib/common.h"
#include "kernel/GaussianKernel.h"
#include "features/DotFeatures.h"
#include "lib/io.h"

using namespace shogun;

CGaussianKernel::CGaussianKernel()
	: CDotKernel(), width(1), sq_lhs(NULL), sq_rhs(NULL)
{
	init();
}


CGaussianKernel::CGaussianKernel(int32_t size, float64_t w)
: CDotKernel(size), width(w), sq_lhs(NULL), sq_rhs(NULL)
{
	init();
}

CGaussianKernel::CGaussianKernel(
	CDotFeatures* l, CDotFeatures* r, float64_t w, int32_t size)
: CDotKernel(size), width(w), sq_lhs(NULL), sq_rhs(NULL)
{
	init();

	init(l,r);
}

CGaussianKernel::~CGaussianKernel()
{
	cleanup();
}

void
CGaussianKernel::init(void)
{
	m_parameters->add(&width, "width", "Kernel width.");
}

void CGaussianKernel::cleanup()
{
	if (sq_lhs != sq_rhs)
		delete[] sq_rhs;
	sq_rhs = NULL;

	delete[] sq_lhs;
	sq_lhs = NULL;

	CKernel::cleanup();
}

void CGaussianKernel::precompute_squared(float64_t* &buf, CDotFeatures* df)
{
	ASSERT(df);
	int32_t num_vec=df->get_num_vectors();
	buf=new float64_t[num_vec];

	for (int32_t i=0; i<num_vec; i++)
		buf[i]=df->dot(i,df, i);
}

bool CGaussianKernel::init(CFeatures* l, CFeatures* r)
{
	///free sq_{r,l}hs first
	cleanup();

	CDotKernel::init(l, r);

	precompute_squared(sq_lhs, (CDotFeatures*) lhs);

	if (lhs==rhs)
		sq_rhs=sq_lhs;
	else
		precompute_squared(sq_rhs, (CDotFeatures*) rhs);

	return init_normalizer();
}

float64_t CGaussianKernel::compute(int32_t idx_a, int32_t idx_b)
{
	float64_t result=sq_lhs[idx_a]+sq_rhs[idx_b]-2*CDotKernel::compute(idx_a,idx_b);
	return exp(-result/width);
}
