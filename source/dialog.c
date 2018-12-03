#include "common.h"
#include "fonts/Acknowledge.h"
#include "fonts/Volter.h"
#include "assets/BgTalkie.h"

// static int dialog_scroll_x = 0;
// static int dialog_scroll_y = 0;

static int dialog_timer;

static int next_x;
static int next_duration;
static const char *next_str;

void dialog_init(void) {
	// dialog_has_input = false;
	// dialog_visible = false;
	
	label_dialog.x = Fix(2);
	label_dialog.y = Fix(130);
	dialog_timer = 0;
}

void dialog_say(const char *str, int duration, int x) {
	label_dialog.x = x;
	dialog_timer = duration;
	label_begin_write(&label_dialog);
	tte_write(str);
	next_str = NULL;
}

void dialog_say_next(const char *str, int duration, int x) {
	next_str = str;
	next_duration = duration;
	next_x = x;
}

void dialog_update(void) {
	
	if (dialog_timer > 0) {
		dialog_timer--;
		label_update(&label_dialog);
	} else if (next_str) {
		dialog_say(next_str, next_duration, next_x);
	}
	
	// REG_BG0HOFS = dialog_scroll_x;
	// REG_BG0VOFS = dialog_scroll_y;
}
