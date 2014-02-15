#include <pebble.h>
#include <string.h>
#include <stdlib.h>

static Window *window;
static TextLayer *text_layer;
static AppTimer *timer;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Select");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Up");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Down");
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  text_layer_set_text(text_layer, "Press a button");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
	
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void timer_callback(void *data) {
	AccelData accel = (AccelData) {.x = 0, .y = 0, .z = 0}
	accel_service_peek(&accel);
	// two dimensions for now
	int16_t x_accel = accel.x;
	int16_t y_accel = accel.y;
	char x_accel_string[5];
	char y_accel_string[5];
	snprintf(x_accel_string, 5, "%d ", x_accel);
	snprintf(y_accel_string, 5, "%d ", y_accel);
	text_layer_set_text(text_layer, x_accel_string);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
	
	accel_data_service_subscribe(10, &accel_data_handler);
	accel_service_set_sampling_rate(ACCEL_SAMPLING_10HZ);
	
	timer = app_timer_register(100, timer_callback, NULL);
}

static void deinit(void) {
	accel_data_service_unsubscribe();
  window_destroy(window);
}

static void accel_data_handler(AccelData *data, uint32_t num_samples) {
	//
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);
	
  app_event_loop();
  deinit();
}
