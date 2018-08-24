/*-------------------------------------------------------------------------
 *
 * hawq_type_mapping.h
 *     Definitions for hawq type and its mapping
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 *-------------------------------------------------------------------------
 */
#ifndef HAWQTYPE_H
#define HAWQTYPE_H

#include "postgres.h"


// primitive type
#define HAWQ_TYPE_BOOL			16
#define HAWQ_TYPE_CHAR			18
#define HAWQ_TYPE_NAME			19
#define HAWQ_TYPE_INT8			20
#define HAWQ_TYPE_INT2			21
#define HAWQ_TYPE_INT4			23
#define HAWQ_TYPE_FLOAT4		700
#define HAWQ_TYPE_FLOAT8		701
#define HAWQ_TYPE_MONEY 		790
#define HAWQ_TYPE_NUMERIC		1700
#define HAWQ_TYPE_BYTE			17
#define HAWQ_TYPE_TEXT			25
#define HAWQ_TYPE_XML			  142
#define HAWQ_TYPE_MACADDR		829
#define HAWQ_TYPE_INET			869
#define HAWQ_TYPE_CIDR			650
#define HAWQ_TYPE_BPCHAR		1042
#define HAWQ_TYPE_VARCHAR		1043
#define HAWQ_TYPE_DATE			1082
#define HAWQ_TYPE_TIME			1083
#define HAWQ_TYPE_TIMESTAMP	1114
#define HAWQ_TYPE_TIMETZ		1266
#define HAWQ_TYPE_TIMESTAMPTZ	1184
#define HAWQ_TYPE_INTERVAL	1186
#define HAWQ_TYPE_BIT			  1560
#define HAWQ_TYPE_VARBIT		1562

// group type
#define HAWQ_TYPE_POINT			600
#define HAWQ_TYPE_LSEG			601
#define HAWQ_TYPE_PATH			602
#define HAWQ_TYPE_BOX			  603
#define HAWQ_TYPE_POLYGON		604
#define HAWQ_TYPE_CIRCLE		718
#define HAWQ_TYPE_INT2_ARRAY    1005
#define HAWQ_TYPE_INT4_ARRAY    1007
#define HAWQ_TYPE_INT8_ARRAY    1016
#define HAWQ_TYPE_FLOAT4_ARRAY  1021
#define HAWQ_TYPE_FLOAT8_ARRAY  1022

#define HAWQ_TYPE_INVALID		-1

enum TypeKind {
  /* Predefined types begin(0~999) */
  // 0~9 Special Types
  INVALIDTYPEID = 0,
  UNKNOWNID = 1,  // unknown yet
  ANYID = 2,      // can be any type

  // 10~99 reserved

  // 100~149 integer
  TINYINTID = 100,
  SMALLINTID = 101,
  INTID = 102,
  BIGINTID = 103,

  // 150~199 float
  FLOATID = 150,
  DOUBLEID = 151,
  DECIMALID = 152,

  // 200~249 date/time
  TIMESTAMPID = 200,
  TIMESTAMPTZID = 201,
  DATEID = 202,
  TIMEID = 203,
  TIMETZID = 204,
  INTERVALID = 205,

  // 250~299 string
  STRINGID = 250,
  VARCHARID = 251,
  CHARID = 252,

  // 300~349 misc
  BOOLEANID = 300,
  BINARYID = 301,

  // 350~999 reserved

  /* Predefined types end */

  /* Constructed types begin(1000~1999) */
  // 1000~1199 array
  SMALLINTARRAYID = 1000,
  INTARRAYID = 1001,
  BIGINTARRAYID = 1002,
  FLOATARRAYID = 1003,
  DOUBLEARRAYID = 1004,

  // 1200~1299 reference

  // 1300~1399 row types

  /* Constructed types end */

  /* User defined types begin(2000~5999) */

  // 2000~2099 complex
  ARRAYID = 2000,
  MAPID = 2001,
  STRUCTID = 2002,
  UNIONID = 2003,
  IOBASETYPEID = 2004,  // base type
  STRUCTEXID = 2005,   // struct extension

// 2100~2199 format(ps:xml not support yet)

// 2200~2799 reserved

// 2800~2899 pesudo types(not support yet)

// 2900~2999 net(not supported yet)

// 3000~3099 postgis(not support yet)

/* User defined types end   */

/* Catalog types begin(6000~)   */

// 6000~6099 catalog type(not support yet)
/* Catalog types end   */
};

int32_t map_hawq_type_to_common_plan(int32_t hawqTypeID);

// if hawq type unsupported, return true
bool checkUnsupportedDataType(int32_t hawqTypeID);

#endif   /* HAWQTYPE_H */
