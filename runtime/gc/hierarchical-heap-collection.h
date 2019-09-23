/* Copyright (C) 2019 Sam Westrick
 * Copyright (C) 2015 Ram Raghunathan.
 *
 * MLton is released under a BSD-style license.
 * See the file MLton-LICENSE for details.
 */

/**
 * @file hierarchical-heap-collection.h
 *
 * @author Ram Raghunathan
 *
 * @brief
 * Definition of the HierarchicalHeap collection interface
 */


#ifndef HIERARCHICAL_HEAP_COLLECTION_H_
#define HIERARCHICAL_HEAP_COLLECTION_H_

#include "chunk.h"

#if (defined (MLTON_GC_INTERNAL_TYPES))
struct ForwardHHObjptrArgs {
  struct HM_HierarchicalHeap* hh;
  uint32_t minLevel;
  uint32_t maxLevel;
  uint32_t toLevel; /* if == HM_HH_INVALID_LEVEL, preserve level of the forwarded object */
  HM_chunkList* toSpace;
  objptr containingObject; /* a hack to keep track of which object is currently being traced */

  size_t bytesCopied;
  uint64_t objectsCopied;
  uint64_t stacksCopied;

  /* large objects are "moved" (rather than copied). */
  size_t bytesMoved;
  uint64_t objectsMoved;
};

#define MAX_NUM_HOLES 512

/**********/
/* Macros */
/**********/
#if ASSERT
#define COPY_OBJECT_HH_VALUE ((struct HM_HierarchicalHeap*)(0xb000deadfee1dead))
#else
#define COPY_OBJECT_HH_VALUE (NULL)
#endif

#endif /* MLTON_GC_INTERNAL_TYPES */

#if (defined (MLTON_GC_INTERNAL_BASIS))
#endif /* MLTON_GC_INTERNAL_BASIS */

#if (defined (MLTON_GC_INTERNAL_FUNCS))
/**
 * This function performs a local collection on the current hierarchical heap
 */
void HM_HHC_collectLocal(uint32_t desiredScope, bool force);

/**
 * Forwards the object pointed to by 'opp' into 'destinationLevelList' starting
 * in its last chunk.
 *
 * @param s The GC_state to use
 * @param opp The objptr to forward
 * @param args The struct ForwardHHObjptrArgs* for this call, cast as a void*
 */
void forwardHHObjptr (GC_state s, objptr* opp, void* rawArgs);

objptr relocateObject(GC_state s, objptr obj, HM_chunkList tgtChunkList, struct ForwardHHObjptrArgs *args);

#endif /* MLTON_GC_INTERNAL_FUNCS */

#endif /* HIERARCHICAL_HEAP_H_ */
