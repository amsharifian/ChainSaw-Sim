/*
 * simics/util/fphex.h
 *
 * This file is part of Virtutech Simics
 *
 * Copyright (C) 1998-2005 Virtutech AB, All Rights Reserved
 *
 * The Virtutech Simics API is distributed under license. Please refer to
 * the 'LICENSE' file for details.
 *
 * For documentation on the Virtutech Simics API, please refer to the
 * Simics Reference Manual. Please report any difficulties you encounter
 * with this API through the Virtutech Simics website at www.simics.com
 *
 */

#ifndef _SIMICS_UTIL_FPHEX_H
#define _SIMICS_UTIL_FPHEX_H

const char *double_hex_str(double _d, int type, int sign);
double fphex_strtod(const char *nptr, char **endptr);

#endif /* _SIMICS_UTIL_FPHEX_H */
