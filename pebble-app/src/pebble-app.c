#include "pebble.h"
#include <string.h>

static Window *window;

static AppTimer *timer;

void out_sent_handler(DictionaryIterator *sent, void *context) {
	
}

void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
	
}

void in_received_handler(DictionaryIterator *received, void *context) {
	
}

void in_dropped_handler(AppMessageResult reason, void *context) {
	
}

static void timer_callback(void *data) {
  AccelData accel = (AccelData) { .x = 0, .y = 0, .z = 0 };

  accel_service_peek(&accel);
	
	DictionaryIterator *iter;
	app_message_outbox_begin(&iter);
	
	Tuplet x_value_tuplet = TupletInteger(1, accel.x);
	Tuplet y_value_tuplet = TupletInteger(2, accel.y);
	
	static char accel_x_string[8];
	static char accel_y_string[8];
	
	snprintf(accel_x_string, 8, "x: %d", accel.x);
	snprintf(accel_y_string, 8, "y: %d", accel.y);
	
	app_log(1, "pebble-app.c", 43, accel_x_string);
	app_log(1, "pebble-app.c", 44, accel_y_string);
	
	/*dict_write_tuplet(iter, &x_value_tuplet);
	dict_write_tuplet(iter, &y_value_tuplet);
	
	app_message_outbox_send();*/
		
  timer = app_timer_register(200, timer_callback, NULL);
}

static void handle_accel(AccelData *accel_data, uint32_t num_samples) {
  // do nothing
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
}

static void window_unload(Window *window) {
 	//
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload
  });
  window_stack_push(window, true /* Animated */);

  accel_data_service_subscribe(0, handle_accel);
	
	app_message_register_inbox_received(in_received_handler);
	app_message_register_inbox_dropped(in_dropped_handler);
	app_message_register_outbox_sent(out_sent_handler);
	app_message_register_outbox_failed(out_failed_handler);
	
	const uint32_t inbound_size = 64;
	const uint32_t outbound_size = 64;
	app_message_open(inbound_size, outbound_size);

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