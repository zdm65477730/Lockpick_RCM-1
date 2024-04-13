/*
* Copyright (c) 2018 naehrwert
* Copyright (c) 2018 CTCaer
*
* This program is free software; you can redistribute it and/or modify it
* under the terms and conditions of the GNU General Public License,
* version 2, as published by the Free Software Foundation.
*
* This program is distributed in the hope it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _TUI_H_
#define _TUI_H_

#include <utils/types.h>
#include <gfx_utils.h>

#define MENT_END     0
#define MENT_HANDLER 1
#define MENT_MENU    2
#define MENT_DATA    3
#define MENT_BACK    4
#define MENT_CAPTION 5
#define MENT_CHGLINE 6
#define MENT_HDLR_RE 7

#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_DEFAULT 0xFF1B1B1B
#define COLOR_GREY 0xFF888888
#define COLOR_DARKGREY 0xFF333333
#define COLOR_ORANGE 0xFFFFA500
#define COLOR_GREEN 0xFF008000
#define COLOR_VIOLET 0xFFEE82EE
#define COLOR_BLUE 0xFF0000FF
#define COLOR_RED 0xFF0000FF
#define COLOR_YELLOW 0xFFFF0000

typedef struct _ment_t
{
	u32 type;
	const char *caption;
	u32 color;
	void *data;
	union
	{
		void(*handler)(void *);
		struct _menu_t *menu;
	};
} ment_t;

typedef struct _menu_t
{
	ment_t *ents;
	const char *caption;
	u32 x;
	u32 y;
} menu_t;

#define MDEF_END() {MENT_END}
#define MDEF_HANDLER(caption, _handler, color) { MENT_HANDLER, caption, color, NULL, { .handler = _handler } }
#define MDEF_HANDLER_EX(caption, data, _handler, color) { MENT_HANDLER, caption, color, data, { .handler = _handler } }
#define MDEF_MENU(caption, _menu, color) { MENT_MENU, caption, color, NULL, { .menu = _menu } }
#define MDEF_BACK(color) { MENT_BACK, "Back", color }
#define MDEF_CAPTION(caption, color) { MENT_CAPTION, caption, color }
#define MDEF_CHGLINE() {MENT_CHGLINE}

void tui_sbar(bool force_update);
void tui_pbar(int x, int y, u32 val, u32 fgcol, u32 bgcol);
void *tui_do_menu(menu_t *menu);

#endif
