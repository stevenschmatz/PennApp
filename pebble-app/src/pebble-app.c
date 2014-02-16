#include "pebble.h"
#include <string.h>

static Window *window;
static AppTimer *timer;
static TextLayer *text_layer;

static char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890.!?";
static unsigned int current_char_index = 0;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
		char change_string[6] = "CHANGE";
	  app_log(1, "pebble-app.c", 14, change_string);
		char text_string[2];
		snprintf(text_string, 1, "%c", characters[current_char_index++]);
		text_layer_set_text(text_layer, text_string);
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };

  accel_service_peek(&accel);
	
	static char accel_x_string[8];
	static char accel_y_string[8];
	
	snprintf(accel_x_string, 8, "x: %d", accel.x);
	snprintf(accel_y_string, 8, "y: %d", accel.y);
	
	app_log(1, "pebble-app.c", 43, accel_x_string);
	app_log(1, "pebble-app.c", 44, accel_y_string);
		
  timer = app_timer_register(500, timer_callback, NULL);
}

static void handle_accel(AccelData *accel_data, uint32_t num_samples) {
  // do nothing
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
 	//
}

static void init(void) {
	//characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890.!?";
	//current_char_index = 0;
	
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload
  });
  window_stack_push(window, true);
	
	window_set_click_config_provider(window, click_config_provider);

  accel_data_service_subscribe(0, handle_accel);

  timer = app_timer_register(100, timer_callback, NULL);
}

static void deinit(void) {
  accel_data_service_unsubscribe();

  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}