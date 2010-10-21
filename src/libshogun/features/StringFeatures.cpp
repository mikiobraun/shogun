/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2010 Christian Widmer
 * Copyright (C) 2010 Max-Planck-Society
 */

#include "features/StringFeatures.h"

#ifdef HAVE_BOOST_SERIALIZATION2
#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_GUID(shogun::CSGString<char>, "CSGString_char");
BOOST_CLASS_EXPORT(shogun::CStringFeatures<char>);

/*
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<float64_t>, "CStringFeatures_float64");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<uint64_t>, "CStringFeatures_uint64");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<int32_t>, "CStringFeatures_int32");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<uint16_t>, "CStringFeatures_uint16");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<uint8_t>, "CStringFeatures_uint8");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<char>, "CStringFeatures_char");
BOOST_CLASS_EXPORT_GUID(shogun::CStringFeatures<bool>, "CStringFeatures_bool");
*/
//BOOST_CLASS_EXPORT(shogun::CSGString<char>);
#endif //HAVE_BOOST_SERIALIZATION
