/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2008 Soeren Sonnenburg
 * Copyright (C) 2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdlib.h>
#include <new>

void* operator new(size_t size) throw (std::bad_alloc);
void operator delete(void *p);

void* operator new[](size_t size);
void operator delete[](void *p);

#endif // __MEMORY_H__