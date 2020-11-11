/*******************************************************************************
 * Copyright 2019 Microchip Corporation.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HSS Embedded Software
 *
 */

/**
 * \file HSS DDR Initalization
 * \brief DDR Initialization
 */

#include "config.h"
#include "hss_types.h"
#include "hss_debug.h"

#include <assert.h>
#include "csr_helper.h"

/*!
 * \brief DDR Training
 *
 * The E51 ensures that DDR is setup prior to code download,
 * and thus perform an DDR training and configuration required to achieve this.
 *
 * The intention is to allow as much flexibility as possible in DDR training,
 * so it is driven by MPFS HSS Embedded Software, with hardware hooks to
 * perform real-time critical functions.
 *
 * TBD: is periodic re-calibration required during operation (e.g. temperature induced
 * or other)
 */

#if IS_ENABLED(CONFIG_PLATFORM_MPFS)
#  include "nwc/mss_nwc_init.h"
#endif

/*!
 * \brief Hook for DDR Setup
 */
bool HSS_DDRInit(void)
{
    //mHSS_DEBUG_PRINTF(lOG_NORMAL, "Initializing DDR..." CRLF);
#if IS_ENABLED(CONFIG_PLATFORM_MPFS)
    assert(mss_nwc_init() == 0);
#endif

    return true;
}
