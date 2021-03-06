// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "Windows.h"

// TODO: reference additional headers your program requires here

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include "Graph.h"

#if defined max
#undef max
#endif

#if defined min
#undef min
#endif

#include "Algorithm.h"
#include "LRUCache.h"
#include "GraphAlgorithm.h"


