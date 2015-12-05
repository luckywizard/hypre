/*
 * File:          SIDL_BaseClass_IOR.c
 * Symbol:        SIDL.BaseClass-v0.8.2
 * Symbol Type:   class
 * Babel Version: 0.8.4
 * Release:       $Name: V1-9-0b $
 * Revision:      @(#) $Id: SIDL_BaseClass_IOR.c,v 1.4 2003/04/07 21:44:31 painter Exp $
 * Description:   Intermediate Object Representation for SIDL.BaseClass
 * 
 * Copyright (c) 2000-2002, The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.4
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "SIDL_BaseClass_IOR.h"
#ifndef included_SIDL_BaseClass_Impl_h
#include "SIDL_BaseClass_Impl.h"
#endif
#ifndef included_SIDL_BaseClass_h
#include "SIDL_BaseClass.h"
#endif
#ifndef included_SIDL_ClassInfo_h
#include "SIDL_ClassInfo.h"
#endif
#ifndef included_SIDL_ClassInfoI_h
#include "SIDL_ClassInfoI.h"
#endif

#ifndef NULL
#define NULL 0
#endif

/*
 * Static variables to hold version of IOR
 */

static const int32_t s_IOR_MAJOR_VERSION = 0;
static const int32_t s_IOR_MINOR_VERSION = 8;
/*
 * Static variable to hold shared ClassInfo interface.
 */

static SIDL_ClassInfo s_classInfo = NULL;
static int s_classInfo_init = 1;

/*
 * Static variables for managing EPV initialization.
 */

static int s_method_initialized = 0;
static int s_remote_initialized = 0;

static struct SIDL_BaseClass__epv s_new__sidl_baseclass;
static struct SIDL_BaseClass__epv s_rem__sidl_baseclass;

static struct SIDL_BaseInterface__epv s_new__sidl_baseinterface;
static struct SIDL_BaseInterface__epv s_rem__sidl_baseinterface;

/*
 * Declare EPV routines defined in the skeleton file.
 */

extern void SIDL_BaseClass__set_epv(
  struct SIDL_BaseClass__epv* epv);

/*
 * CAST: dynamic type casting support.
 */

static void* ior_SIDL_BaseClass__cast(
  struct SIDL_BaseClass__object* self,
  const char* name)
{
  void* cast = NULL;

  struct SIDL_BaseClass__object* s0 = self;

  if (!strcmp(name, "SIDL.BaseClass")) {
    cast = (void*) s0;
  } else if (!strcmp(name, "SIDL.BaseInterface")) {
    cast = (void*) &s0->d_sidl_baseinterface;
  }

  return cast;
}

/*
 * DELETE: call destructor and free object memory.
 */

static void ior_SIDL_BaseClass__delete(
  struct SIDL_BaseClass__object* self)
{
  SIDL_BaseClass__fini(self);
  memset((void*)self, 0, sizeof(struct SIDL_BaseClass__object));
  free((void*) self);
}

/*
 * EPV: create method entry point vector (EPV) structure.
 */

static void SIDL_BaseClass__init_epv(
  struct SIDL_BaseClass__object* self)
{
  struct SIDL_BaseClass__epv*     epv = &s_new__sidl_baseclass;
  struct SIDL_BaseInterface__epv* e0  = &s_new__sidl_baseinterface;

  epv->f__cast        = ior_SIDL_BaseClass__cast;
  epv->f__delete      = ior_SIDL_BaseClass__delete;
  epv->f__ctor        = NULL;
  epv->f__dtor        = NULL;
  epv->f_addRef       = NULL;
  epv->f_deleteRef    = NULL;
  epv->f_isSame       = NULL;
  epv->f_queryInt     = NULL;
  epv->f_isType       = NULL;
  epv->f_getClassInfo = NULL;

  SIDL_BaseClass__set_epv(epv);

  e0->f__cast        = (void* (*)(void*,const char*)) epv->f__cast;
  e0->f__delete      = (void (*)(void*)) epv->f__delete;
  e0->f_addRef       = (void (*)(void*)) epv->f_addRef;
  e0->f_deleteRef    = (void (*)(void*)) epv->f_deleteRef;
  e0->f_isSame       = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInt;
  e0->f_isType       = (SIDL_bool (*)(void*,const char*)) epv->f_isType;
  e0->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(void*)) 
    epv->f_getClassInfo;

  s_method_initialized = 1;
}

/*
 * initClassInfo: create a ClassInfo interface if necessary.
 */

static void
initClassInfo(SIDL_ClassInfo *info)
{
  if (s_classInfo_init) {
    SIDL_ClassInfoI impl;
    s_classInfo_init = 0;
    impl = SIDL_ClassInfoI__create();
    s_classInfo = SIDL_ClassInfo__cast(impl);
    if (impl) {
      SIDL_ClassInfoI_setName(impl, "SIDL.BaseClass");
      SIDL_ClassInfoI_setIORVersion(impl, s_IOR_MAJOR_VERSION,
        s_IOR_MINOR_VERSION);
    }
  }
  if (s_classInfo) {
    if (*info) {
      SIDL_ClassInfo_deleteRef(*info);
    }
    *info = s_classInfo;
    SIDL_ClassInfo_addRef(*info);
  }
}

/*
 * initMetadata: store IOR version & class in SIDL.BaseClass's data
 */

static void
initMetadata(struct SIDL_BaseClass__object* self)
{
  if (self) {
    struct SIDL_BaseClass__data *data = 
      SIDL_BaseClass__get_data(SIDL_BaseClass__cast(self));
    if (data) {
      data->d_IOR_major_version = s_IOR_MAJOR_VERSION;
      data->d_IOR_minor_version = s_IOR_MINOR_VERSION;
      initClassInfo(&(data->d_classinfo));
    }
  }
}

/*
 * NEW: allocate object and initialize it.
 */

struct SIDL_BaseClass__object*
SIDL_BaseClass__new(void)
{
  struct SIDL_BaseClass__object* self =
    (struct SIDL_BaseClass__object*) malloc(
      sizeof(struct SIDL_BaseClass__object));
  SIDL_BaseClass__init(self);
  initMetadata(self);
  return self;
}

/*
 * INIT: initialize a new instance of the class object.
 */

void SIDL_BaseClass__init(
  struct SIDL_BaseClass__object* self)
{
  struct SIDL_BaseClass__object* s0 = self;

  if (!s_method_initialized) {
    SIDL_BaseClass__init_epv(s0);
  }

  s0->d_sidl_baseinterface.d_epv = &s_new__sidl_baseinterface;
  s0->d_epv                      = &s_new__sidl_baseclass;

  s0->d_sidl_baseinterface.d_object = self;

  s0->d_data = NULL;

  (*(self->d_epv->f__ctor))(self);
}

/*
 * FINI: deallocate a class instance (destructor).
 */

void SIDL_BaseClass__fini(
  struct SIDL_BaseClass__object* self)
{
  struct SIDL_BaseClass__object* s0 = self;

  (*(s0->d_epv->f__dtor))(s0);
}

/*
 * VERSION: Return the version of the IOR used to generate this IOR.
 */

void
SIDL_BaseClass__IOR_version(int32_t *major, int32_t *minor)
{
  *major = s_IOR_MAJOR_VERSION;
  *minor = s_IOR_MINOR_VERSION;
}
static const struct SIDL_BaseClass__external
s_externalEntryPoints = {
  SIDL_BaseClass__new,
  SIDL_BaseClass__remote,
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 * loading DLLs
 */

const struct SIDL_BaseClass__external*
SIDL_BaseClass__externals(void)
{
  return &s_externalEntryPoints;
}

/*
 * REMOTE CAST: dynamic type casting for remote objects.
 */

static void* remote_SIDL_BaseClass__cast(
  struct SIDL_BaseClass__object* self,
  const char* name)
{
  return NULL;
}

/*
 * REMOTE DELETE: call the remote destructor for the object.
 */

static void remote_SIDL_BaseClass__delete(
  struct SIDL_BaseClass__object* self)
{
  free((void*) self);
}

/*
 * REMOTE METHOD STUB:addRef
 */

static void
remote_SIDL_BaseClass_addRef(
  struct SIDL_BaseClass__object* self)
{
}

/*
 * REMOTE METHOD STUB:deleteRef
 */

static void
remote_SIDL_BaseClass_deleteRef(
  struct SIDL_BaseClass__object* self)
{
}

/*
 * REMOTE METHOD STUB:isSame
 */

static SIDL_bool
remote_SIDL_BaseClass_isSame(
  struct SIDL_BaseClass__object* self,
  struct SIDL_BaseInterface__object* iobj)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:queryInt
 */

static struct SIDL_BaseInterface__object*
remote_SIDL_BaseClass_queryInt(
  struct SIDL_BaseClass__object* self,
  const char* name)
{
  return (struct SIDL_BaseInterface__object*) 0;
}

/*
 * REMOTE METHOD STUB:isType
 */

static SIDL_bool
remote_SIDL_BaseClass_isType(
  struct SIDL_BaseClass__object* self,
  const char* name)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:getClassInfo
 */

static struct SIDL_ClassInfo__object*
remote_SIDL_BaseClass_getClassInfo(
  struct SIDL_BaseClass__object* self)
{
  return (struct SIDL_ClassInfo__object*) 0;
}

/*
 * REMOTE EPV: create remote entry point vectors (EPVs).
 */

static void SIDL_BaseClass__init_remote_epv(void)
{
  struct SIDL_BaseClass__epv*     epv = &s_rem__sidl_baseclass;
  struct SIDL_BaseInterface__epv* e0  = &s_rem__sidl_baseinterface;

  epv->f__cast        = remote_SIDL_BaseClass__cast;
  epv->f__delete      = remote_SIDL_BaseClass__delete;
  epv->f__ctor        = NULL;
  epv->f__dtor        = NULL;
  epv->f_addRef       = remote_SIDL_BaseClass_addRef;
  epv->f_deleteRef    = remote_SIDL_BaseClass_deleteRef;
  epv->f_isSame       = remote_SIDL_BaseClass_isSame;
  epv->f_queryInt     = remote_SIDL_BaseClass_queryInt;
  epv->f_isType       = remote_SIDL_BaseClass_isType;
  epv->f_getClassInfo = remote_SIDL_BaseClass_getClassInfo;

  e0->f__cast        = (void* (*)(void*,const char*)) epv->f__cast;
  e0->f__delete      = (void (*)(void*)) epv->f__delete;
  e0->f_addRef       = (void (*)(void*)) epv->f_addRef;
  e0->f_deleteRef    = (void (*)(void*)) epv->f_deleteRef;
  e0->f_isSame       = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInt;
  e0->f_isType       = (SIDL_bool (*)(void*,const char*)) epv->f_isType;
  e0->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(void*)) 
    epv->f_getClassInfo;

  s_remote_initialized = 1;
}

/*
 * REMOTE: generate remote instance given URL string.
 */

struct SIDL_BaseClass__object*
SIDL_BaseClass__remote(const char *url)
{
  struct SIDL_BaseClass__object* self =
    (struct SIDL_BaseClass__object*) malloc(
      sizeof(struct SIDL_BaseClass__object));

  struct SIDL_BaseClass__object* s0 = self;

  if (!s_remote_initialized) {
    SIDL_BaseClass__init_remote_epv();
  }

  s0->d_sidl_baseinterface.d_epv    = &s_rem__sidl_baseinterface;
  s0->d_sidl_baseinterface.d_object = NULL; /* FIXME */

  s0->d_data = NULL; /* FIXME */
  s0->d_epv  = &s_rem__sidl_baseclass;

  return self;
}