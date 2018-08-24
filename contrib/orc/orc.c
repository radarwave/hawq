#include <json-c/json.h>

#include "c.h"
#include "port.h"
#include "postgres.h"
#include "fmgr.h"
#include "funcapi.h"
#include "nodes/pg_list.h"
#include "utils/hawq_type_mapping.h"
#include "utils/memutils.h"
#include "utils/relcache.h"
#include "utils/uri.h"
#include "utils/formatting.h"
#include "utils/lsyscache.h"
#include "utils/datetime.h"
#include "mb/pg_wchar.h"
#include "commands/defrem.h"
#include "commands/copy.h"
#include "access/tupdesc.h"
#include "access/filesplit.h"
#include "access/plugstorage.h"
#include "cdb/cdbvars.h"
#include "catalog/pg_exttable.h"
#include "catalog/namespace.h"
#include "postmaster/identity.h"
#include "nodes/makefuncs.h"
#include "nodes/plannodes.h"
#include "utils/uri.h"


#define ORC_TIMESTAMP_EPOCH_JDATE	2457024 /* == date2j(2015, 1, 1) */
#define MAX_ORC_ARRAY_DIMS        10000

/* Do the module magic dance */
PG_MODULE_MAGIC;

/* Validators for pluggable storage format ORC */
PG_FUNCTION_INFO_V1(orc_validate_interfaces);
PG_FUNCTION_INFO_V1(orc_validate_options);
PG_FUNCTION_INFO_V1(orc_validate_encodings);
PG_FUNCTION_INFO_V1(orc_validate_datatypes);

/* Accessors for pluggable storage format ORC */
PG_FUNCTION_INFO_V1(orc_beginscan);
PG_FUNCTION_INFO_V1(orc_getnext_init);
PG_FUNCTION_INFO_V1(orc_getnext);
PG_FUNCTION_INFO_V1(orc_rescan);
PG_FUNCTION_INFO_V1(orc_endscan);
PG_FUNCTION_INFO_V1(orc_stopscan);
PG_FUNCTION_INFO_V1(orc_insert_init);
PG_FUNCTION_INFO_V1(orc_insert);
PG_FUNCTION_INFO_V1(orc_insert_finish);

/* Definitions of validators for pluggable storage format ORC */
Datum orc_validate_interfaces(PG_FUNCTION_ARGS);
Datum orc_validate_options(PG_FUNCTION_ARGS);
Datum orc_validate_encodings(PG_FUNCTION_ARGS);
Datum orc_validate_datatypes(PG_FUNCTION_ARGS);

/* Definitions of accessors for pluggable storage format ORC */
Datum orc_beginscan(PG_FUNCTION_ARGS);
Datum orc_getnext_init(PG_FUNCTION_ARGS);
Datum orc_getnext(PG_FUNCTION_ARGS);
Datum orc_rescan(PG_FUNCTION_ARGS);
Datum orc_endscan(PG_FUNCTION_ARGS);
Datum orc_stopscan(PG_FUNCTION_ARGS);
Datum orc_insert_init(PG_FUNCTION_ARGS);
Datum orc_insert(PG_FUNCTION_ARGS);
Datum orc_insert_finish(PG_FUNCTION_ARGS);

typedef struct ORCFormatFileSplit {


} ORCFormatFileSplit;


typedef struct ORCFormatC {

}ORCFormatC;


typedef struct {

} TimestampType;

typedef struct ORCFormatUserData
{

} ORCFormatUserData;


static FmgrInfo *get_orc_function(char *formatter_name, char *function_name);
static void get_scan_functions(FileScanDesc file_scan_desc);
static void get_insert_functions(ExternalInsertDesc ext_insert_desc);
static void init_format_user_data_for_read(TupleDesc tup_desc, ORCFormatUserData *user_data);
static void init_format_user_data_for_write(TupleDesc tup_desc, ORCFormatUserData *user_data);
static void build_options_in_json(List *fmt_opts_defelem, int encoding, char **json_str);
static ORCFormatC *create_formatter_instance(List *fmt_opts_defelem, int encoding, int segno);
static void build_file_splits(Uri *uri, ScanState *scan_state, ORCFormatUserData *user_data);
static void build_tuple_descrition_for_read(Plan *plan, Relation relation, ORCFormatUserData *user_data);
static void build_tuple_descrition_for_write(Relation relation, ORCFormatUserData *user_data);
static void orc_scan_error_callback(void *arg);
static void orc_parse_format_string(CopyState pstate, char *fmtstr);
static char *orc_strtokx2(const char *s, const char *whitespace, const char *delim,
                          const char *quote, char escape, bool e_strings,
                          bool del_quotes, int encoding);
static void orc_strip_quotes(char *source, char quote, char escape, int encoding);

/* Implementation of validators for pluggable storage format ORC */

/*
 * void
 * orc_validate_interfaces(char *formatName)
 */
Datum orc_validate_interfaces(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_validate_interfaces has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_validate_options(List *formatOptions,
 *                      char *formatStr,
 *                      bool isWritable)
 */
Datum orc_validate_options(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_validate_options has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_validate_encodings(char *encodingName)
 */
Datum orc_validate_encodings(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_validate_encodings has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_validate_datatypes(TupleDesc tupDesc)
 */
Datum orc_validate_datatypes(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_validate_datatypes has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * FileScanDesc
 * orc_beginscan(ExternalScan *extScan,
 *               ScanState *scanState,
 *               Relation relation,
 *               int formatterType,
 *               char *formatterName)
 */
Datum orc_beginscan(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_beginscan has not be completed, please fill it");
	PG_RETURN_POINTER(NULL);
}

/*
 * ExternalSelectDesc
 * orc_getnext_init(PlanState *planState,
 *                  ExternalScanState *extScanState)
 */
Datum orc_getnext_init(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_getnext_init has not be completed, please fill it");
	PG_RETURN_POINTER(NULL);
}

/*
 * bool
 * orc_getnext(FileScanDesc fileScanDesc,
 *             ScanDirection direction,
 *             ExternalSelectDesc extSelectDesc,
 *             ScanState *scanState,
 *             TupleTableSlot *tupTableSlot)
 */
Datum orc_getnext(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_getnext has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_rescan(FileScanDesc scan)
 */
Datum orc_rescan(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_rescan has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_endscan(FileScanDesc scan)
 */
Datum orc_endscan(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_endscan has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * void
 * orc_stopscan(FileScanDesc scan)
 */
Datum orc_stopscan(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_stopscan has not be completed, please fill it");
	PG_RETURN_VOID();
}

/*
 * ExternalInsertDesc
 * orc_insert_init(Relation relation,
 *                 int formatterType,
 *                 char *formatterName)
 */
Datum orc_insert_init(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_insert_init has not be completed, please fill it");
	PG_RETURN_POINTER(NULL);
}

/*
 * Oid
 * orc_insert(ExternalInsertDesc extInsertDesc,
 *            TupleTableSlot *tupTableSlot)
 */
Datum orc_insert(PG_FUNCTION_ARGS)
{

	elog(ERROR, "Funtion orc_insert has not be completed, please fill it");
	PG_RETURN_OID(InvalidOid);
}

/*
 * void
 * orc_insert_finish(ExternalInsertDesc extInsertDesc)
 */
Datum orc_insert_finish(PG_FUNCTION_ARGS)
{
	elog(ERROR, "Funtion orc_insert_finish has not be completed, please fill it");
	PG_RETURN_VOID();
}

static FmgrInfo *get_orc_function(char *formatter_name, char *function_name)
{
	elog(ERROR, "Funtion get_orc_function has not be completed, please fill it");
	return NULL;
}

static void get_scan_functions(FileScanDesc file_scan_desc)
{
	elog(ERROR, "Funtion get_scan_functions has not be completed, please fill it");
}

static void get_insert_functions(ExternalInsertDesc ext_insert_desc)
{
	elog(ERROR, "Funtion get_insert_functions has not be completed, please fill it");
}

static void init_format_user_data_for_read(TupleDesc tup_desc, ORCFormatUserData *user_data)
{
	elog(ERROR, "Funtion init_format_user_data_for_read has not be completed, please fill it");
}

static void init_format_user_data_for_write(TupleDesc tup_desc, ORCFormatUserData *user_data)
{
	elog(ERROR, "Funtion init_format_user_data_for_write has not be completed, please fill it");
}

static void build_options_in_json(List *fmt_opts_defelem, int encoding, char **json_str)
{
	elog(ERROR, "Funtion build_options_in_json has not be completed, please fill it");
}

static ORCFormatC *create_formatter_instance(List *fmt_opts_defelem, int fmt_encoding, int segno)
{
	elog(ERROR, "Funtion create_formatter_instance has not be completed, please fill it");
	return NULL;
}

static void build_file_splits(Uri *uri, ScanState *scan_state, ORCFormatUserData *user_data)
{
	elog(ERROR, "Funtion build_file_splits has not be completed, please fill it");
}

static void build_tuple_descrition_for_read(Plan *plan,
                                            Relation relation,
                                            ORCFormatUserData *user_data)
{
	elog(ERROR, "Funtion build_tuple_descrition_for_read has not be completed, please fill it");
}

static void build_tuple_descrition_for_write(Relation relation, ORCFormatUserData *user_data)
{
	elog(ERROR, "Funtion build_tuple_descrition_for_write has not be completed, please fill it");
}

static void orc_scan_error_callback(void *arg)
{
	elog(ERROR, "Funtion orc_scan_error_callback has not be completed, please fill it");
}

static void orc_parse_format_string(CopyState pstate, char *fmtstr)
{
	elog(ERROR, "Funtion orc_parse_format_string has not be completed, please fill it");
}

static char *orc_strtokx2(const char *s,
                          const char *whitespace,
                          const char *delim,
                          const char *quote,
                          char escape,
                          bool e_strings,
                          bool del_quotes,
                          int encoding)
{

	elog(ERROR, "Funtion orc_strtokx2 has not be completed, please fill it");
	return NULL;
}

static void orc_strip_quotes(char *source, char quote, char escape, int encoding)
{
	elog(ERROR, "Funtion orc_strip_quotes has not be completed, please fill it");
}
