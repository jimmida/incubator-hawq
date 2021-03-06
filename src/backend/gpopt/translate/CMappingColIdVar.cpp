//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CMappingColIdVar.cpp
//
//	@doc:
//		Implementation of base ColId-> Var mapping class
//
//
//	@owner:
//		raghav
//
//	@test:
//
//
//---------------------------------------------------------------------------

#include "gpopt/translate/CMappingColIdVar.h"

using namespace gpdxl;

//---------------------------------------------------------------------------
//	@function:
//		CMappingColIdVar::CMappingColIdVar
//
//	@doc:
//		Constructor
//
//---------------------------------------------------------------------------
CMappingColIdVar::CMappingColIdVar
	(
	IMemoryPool *pmp
	)
	:
	m_pmp(pmp)
{
}

// EOF
