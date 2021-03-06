#ifndef _GP_MASTER_MIRRORING_H_
#define _GP_MASTER_MIRRORING_H_

#include "catalog/genbki.h"
/*
 * Defines for gp_master_mirroring table
 */
#define GpMasterMirroringRelationName		"gp_master_mirroring"

/* TIDYCAT_BEGINDEF

   CREATE TABLE gp_master_mirroring
   with (camelcase=GpMasterMirroring, shared=true, oid=false, relid=5008, content=MASTER_ONLY)
   (
   summary_state  text,
   detail_state   text,
   log_time       timestamp with time zone,
   error_message  text
   );

   TIDYCAT_ENDDEF
*/
/* TIDYCAT_BEGIN_CODEGEN 

   WARNING: DO NOT MODIFY THE FOLLOWING SECTION: 
   Generated by tidycat.pl version 21.
   on Wed Nov 24 14:23:25 2010
*/


/*
 TidyCat Comments for gp_master_mirroring:
  Table is shared, so catalog.c:IsSharedRelation is updated.
  Table does not have an Oid column.
  Table does not have static type (only legal for pre-3.3 tables). 
  Table has TOASTable columns, but NO TOAST table.
  Table contents are only maintained on MASTER.
  Table has weird hack for timestamp column.
 
*/

/*
 * The CATALOG definition has to refer to the type of "log_time" as
 * "timestamptz" (lower case) so that bootstrap mode recognizes it.  But
 * the C header files define this type as TimestampTz.	Since the field is
 * potentially-null and therefore cannot be accessed directly from C code,
 * there is no particular need for the C struct definition to show the
 * field type as TimestampTz --- instead we just make it Datum.
 */

#define timestamptz Datum

/* ----------------
 *		gp_master_mirroring definition.  cpp turns this into
 *		typedef struct FormData_gp_master_mirroring
 * ----------------
 */
#define GpMasterMirroringRelationId	5008

CATALOG(gp_master_mirroring,5008) BKI_SHARED_RELATION BKI_WITHOUT_OIDS
{
	text		summary_state;	
	text		detail_state;	
	timestamptz	log_time;		
	text		error_message;	
} FormData_gp_master_mirroring;

#undef timestamptz


/* ----------------
 *		Form_gp_master_mirroring corresponds to a pointer to a tuple with
 *		the format of gp_master_mirroring relation.
 * ----------------
 */
typedef FormData_gp_master_mirroring *Form_gp_master_mirroring;


/* ----------------
 *		compiler constants for gp_master_mirroring
 * ----------------
 */
#define Natts_gp_master_mirroring				4
#define Anum_gp_master_mirroring_summary_state	1
#define Anum_gp_master_mirroring_detail_state	2
#define Anum_gp_master_mirroring_log_time		3
#define Anum_gp_master_mirroring_error_message	4


/* TIDYCAT_END_CODEGEN */

/* ----------------
 *		initial contents of gp_master_mirroring
 * ----------------
 */
DATA(insert (  "Not Configured", _null_, _null_, _null_ ));
DESCR("");

#endif /*_GP_MASTER_MIRRORING_H_*/
