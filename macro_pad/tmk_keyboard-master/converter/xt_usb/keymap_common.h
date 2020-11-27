/*
Copyright 2011,2012,2013 Jun Wako <wakojun@gmail.com>

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
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


/* IBM XT keyobard layout
 * ,-------.  ,--------------------------------------------------------------------------.
 * | F1| F2|  |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BS  |NumLck |ScrLck |
 * |-------|  |--------------------------------------------------------------------------|
 * | F3| F4|  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ] |   |  7|  8|  9|  -|
 * |-------|  |------------------------------------------------------|Ent|---------------|
 * | F5| F6|  | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  `|   |  4|  5|  6|   |
 * |-------|  |----------------------------------------------------------------------|   |
 * | F7| F8|  |Shif|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift|  *|  1|  2|  3|  +|
 * |-------|  |----------------------------------------------------------------------|   |
 * | F9|F10|  |  Alt  |               Space                  |CapsLck|   0   |   .   |   |
 * `-------'  `--------------------------------------------------------------------------'
 * Scan code set 1
 * ,-------.  ,--------------------------------------------------------------------------.
 * | 3B| 3C|  | 01| 02| 03| 04| 05| 06| 07| 08| 09| 0A| 0B| 0C| 0D|  0E  |  45   |  46   |
 * |-------|  |--------------------------------------------------------------------------|
 * | 3D| 3E|  | 0F  | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 1A| 1B |   | 47| 48| 49| 4A|
 * |-------|  |------------------------------------------------------| 1C|---------------|
 * | 3F| 40|  | 1D   | 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29|   | 4B| 4C| 4D|   |
 * |-------|  |----------------------------------------------------------------------|   |
 * | 41| 42|  | 2A | 2B| 2C| 2D| 2E| 2F| 30| 31| 32| 33| 34| 35|  36 | 37| 4F| 50| 51| 4E|
 * |-------|  |----------------------------------------------------------------------|   |
 * | 43| 44|  |  38   |              39                      |  3A   |  52   |  53   |   |
 * `-------'  `--------------------------------------------------------------------------'
 */
#define KEYMAP_XT( \
    K3B,K3C,  K01,K02,K03,K04,K05,K06,K07,K08,K09,K0A,K0B,K0C,K0D,K0E,    K45,    K46, \
    K3D,K3E,  K0F,K10,K11,K12,K13,K14,K15,K16,K17,K18,K19,K1A,K1B,    K47,K48,K49,K4A, \
    K3F,K40,  K1D,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K28,K29,K1C,K4B,K4C,K4D,     \
    K41,K42,  K2A,K2B,K2C,K2D,K2E,K2F,K30,K31,K32,K33,K34,K35,K36,K37,K4F,K50,K51,K4E, \
    K43,K44,  K38,                    K39,                    K3A,    K52,    K53      \
) { \
    { KC_NO,    KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27 }, \
    { KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }  \
}

/* Extended keyboard layout
 *         ,-----------------------------------------------.
 *         |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
 * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|     |PrS|ScL|Pau|     |VDn|VUp|Mut|
 * `---'   `-----------------------------------------------'     `-----------'     `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Entr|               |  4|  5|  6|KP,|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |---------------|
 * |Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|KP=|
 * `-----------------------------------------------------------' `-----------' `---------------'
 *         ,-----------------------------------------------.
 *         | 64| 65| 66| 67| 68| 69| 6A| 6B| 6C| 6D| 6E| 76|
 * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
 * | 01|   | 3B| 3C| 3D| 3E| 3F| 40| 41| 42| 43| 44| 57| 58|     |*37| 46|*45|     |e5E|e5F|e63|
 * `---'   `-----------------------------------------------'     `-----------'     `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * | 29| 02| 03| 04| 05| 06| 07| 08| 09| 0A| 0B| 0C| 0D| 7D| 0E| |e52|e47|e49| | 45|e35| 37| 4A|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * | 0F  | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 1A| 1B|  2B | |e53|e4F|e51| | 47| 48| 49| 4E|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * |  3A  | 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 00| 1C |               | 4B| 4C| 4D| 7E|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * | 2A | 56| 2C| 2D| 2E| 2F| 30| 31| 32| 33| 34| 35| 73|  36  |     |e48|     | 4F| 50| 51|e1C|
 * |-----------------------------------------------------------| ,-----------. |---------------|
 * | 1D|e5B| 38| 7B |       39       | 79 | 70 |e38|e5C|e5D|e1D| |e4B|e50|e4D| |     52| 53| 59|
 * `-----------------------------------------------------------' `-----------' `---------------'
 * e: E0-escaped codes
 * *: special handling codes
 */
#define KEYMAP( \
            K64,K65,K66,K67,K68,K69,K6A,K6B,K6C,K6D,K6E,K76,                                     \
    K01,    K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K57,K58,      K54,K46,K55,      K5D,K5E,K5F, \
    K29,K02,K03,K04,K05,K06,K07,K08,K09,K0A,K0B,K0C,K0D,K7D,K0E,  K71,K74,K77,  K45,K7F,K37,K4A, \
    K0F,K10,K11,K12,K13,K14,K15,K16,K17,K18,K19,K1A,K1B,    K2B,  K72,K75,K78,  K47,K48,K49,K4E, \
    K3A,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K28,    K00,K1C,                K4B,K4C,K4D,K7E, \
    K2A,K56,K2C,K2D,K2E,K2F,K30,K31,K32,K33,K34,K35,    K73,K36,      K60,      K4F,K50,K51,K6F, \
    K1D,K5A,K38,K7B,        K39,        K79,K70,K7C,K5B,K5C,K7A,  K61,K62,K63,      K52,K53,K59  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07 }, \
    { KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27 }, \
    { KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K58, KC_##K59, KC_##K5A, KC_##K5B, KC_##K5C, KC_##K5D, KC_##K5E, KC_##K5F }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
    { KC_##K68, KC_##K69, KC_##K6A, KC_##K6B, KC_##K6C, KC_##K6D, KC_##K6E, KC_##K6F }, \
    { KC_##K70, KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
    { KC_##K78, KC_##K79, KC_##K7A, KC_##K7B, KC_##K7C, KC_##K7D, KC_##K7E, KC_##K7F }  \
}

#endif