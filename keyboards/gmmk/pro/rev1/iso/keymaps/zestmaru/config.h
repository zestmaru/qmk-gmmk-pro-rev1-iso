/* Copyright 2021 Jonavin Eng
   Copyright 2022 subhead @subhead
   Copyright 2024 zestmaru

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// RGB Matrix configuration
#ifdef RGB_MATRIX_ENABLE
    // RGB startup effect
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_OUT_IN
        // number of milliseconds to wait until turning off RGB automatically
    #define RGB_DISABLE_TIMEOUT 300000 // 300 seconds / 5 min
    // start fading out before getting disabled
    // fading out is timed (depending on the rgb_matrix_config.speed) to have finished before reaching RGB_DISABLE_TIMEOUT
    #define RGB_DISABLE_WITH_FADE_OUT
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    // number of milliseconds to wait until activating RGB idle effects
    #define RGB_IDLE_TIMEOUT 4500 // 4.5 seconds
    // activate breathe effect when idle
    #define RGB_IDLE_BREATHE
    // fade in when we have been suspended
    #define RGB_FADE_IN
#endif

// IDLE timeouts configuration
#ifdef IDLE_TIMEOUT_ENABLE
    // default timeout minutes
    #define TIMEOUT_THRESHOLD_DEFAULT 15
    // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)
    #define TIMEOUT_THRESHOLD_MAX 140
#endif

// Force n-key rollover
#define FORCE_NKRO

// Set keyboard debounce time (originally 5ms, now 8ms to combat touchy switches)
// #define DEBOUNCE 8

// 1000Hz
#define USB_POLLING_INTERVAL_MS  2