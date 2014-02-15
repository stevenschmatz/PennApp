#include "pebble.h"

static Window *window;

static AppTimer *timer;

static TextLayer *text_layer;

static char accel_string[10];

static void out_sent_handler(DictionaryIterator *sent, void *context) {
	app_message_outbox_release();
}

static void out_fail_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
	app_message_outbox_release();
}

static void in_rcv_handler(void *context, AppMessageResult reason) {
	
}

static void in_drp_handler(void *context, AppMessageResult reason) {
	
}

static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };

  accel_service_peek(&accel);
	
	static DictionaryIterator *iter;
	app_message_outbox_get(&iter);
	
	char x[1] = "x";
	char y[1] = "y";
	
	char accel_x_string[5]; 
	char accel_y_string[5];
	snprintf(accel_x_string, 5, "%d", accel.x);
	snprintf(accel_y_string, 5, "%d", accel.y);
	
	dict_write_data(&iter, x, accel_x_string);
	dict_write_data(&iter, y, accel_y_string);
	
	app_message_outbox_send();
		
  timer = app_timer_register(100, timer_callback, NULL);
}

static void handle_accel(AccelData *accel_data, uint32_t num_samples) {
  // do nothing
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = {0, 72}, .size = {bounds.size.w, 50}});
	text_layer_set_text(text_layer, "Move me around");
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
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