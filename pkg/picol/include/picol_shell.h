/*
 * Copyright (C) 2025-2026 Francois Perrad
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup  pkg_picol
 * @{
 * @file
 *
 */

#ifndef PICOL_SHELL_H
#define PICOL_SHELL_H

#include "picol.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Default shell buffer size (maximum line length shell can handle)
 */
#define PICOL_DEFAULT_BUFSIZE   128

/**
 * @brief           Picol command exec is a brigde to the Shell commands
 *
 * @param[in]       i           ptr to interpreter
 * @param[in]       argc        number of arguments
 * @param[in]       argv        argument list
 * @param[in]       pd          ptr to custom shell_command_t or NULL
 */
extern picolResult riot_picol_command_exec(struct picolInterp *i, int argc, const char *argv[], void *pd);

/**
 * @brief           Start a shell and exit once EOF is reached.
 *
 *                  If `CONFIG_SHELL_SHUTDOWN_ON_EXIT` is set (e.g. on native)
 *                  the shell will instead shut down RIOT once EOF is reached.
 *
 * @param[in]       i           ptr to interpreter
 */
extern void riot_picol_shell_run(struct picolInterp *i);

#ifdef __cplusplus
}
#endif

#endif /* PICOL_SHELL_H */
/** @} */
