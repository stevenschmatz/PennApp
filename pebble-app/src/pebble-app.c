#include "pebble.h"

static Window *window;

static AppTimer *timer;

static TextLayer *x_text_layer;
static TextLayer *y_text_layer;

static char x_accel_string[5];
static char y_accel_string[5];

static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };

  accel_service_peek(&accel);
	
	snprintf(x_accel_string, 5, "%d ", accel.x);
	snprintf(y_accel_string, 5, "%d ", accel.y);
	
	text_layer_set_text(x_text_layer, x_accel_string);
	text_layer_set_text(y_text_layer, y_accel_string);

  timer = app_timer_register(100, timer_callback, NULL);
}

static void handle_accel(AccelData *accel_data, uint32_t num_samples) {
  // do nothing
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  x_text_layer = text_layer_create((GRect) { .origin = {0, 72}, .size = {bounds.size.w, 20}});
	y_text_layer = text_layer_create((GRect) { .origin = {0, 100}, .size = {bounds.size.w, 20}});
	text_layer_set_text(x_text_layer, "Move me around");
	text_layer_set_text_alignment(x_text_layer, GTextAlignmentCenter);
	text_layer_set_text_alignment(y_text_layer, GTextAlignmentRight);
  layer_add_child(window_layer, text_layer_get_layer(x_text_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(x_text_layer);
	text_layer_destroy(y_text_layer);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload
  });
  window_stack_push(window, true /* Animated */);

  accel_data_service_subscribe(0, handle_accel);

  timer = app_timer_register(100 /* milliseconds */, timer_callback, NULL);
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