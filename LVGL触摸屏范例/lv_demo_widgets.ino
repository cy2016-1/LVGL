#include <lvgl.h>  // 引入 LVGL 库
#include <TFT_eSPI.h>  // 引入 TFT_eSPI 库

#include <examples/lv_examples.h>  // 引入 LVGL 示例
#include <demos/lv_demos.h>  // 引入 LVGL 演示

TFT_eSPI tft = TFT_eSPI();  // 初始化 TFT_eSPI 对象

/* 设置屏幕分辨率 */
#define TFT_HOR_RES 320  // 水平分辨率
#define TFT_VER_RES 240  // 垂直分辨率

/* LVGL 将图像渲染到此缓冲区中，通常使用屏幕大小的 1/10 大小。大小以字节为单位 */
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

#if LV_USE_LOG != 0
// 调试打印函数
void my_print(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

/* LVGL 在需要将渲染的图像复制到显示设备上时调用此函数 */
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  /* 调用此函数告诉 LVGL 准备好刷新显示内容 */
  lv_disp_flush_ready(disp);
}

/* 读取触摸板 */
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY, 600);

  if (!touched) {
    data->state = LV_INDEV_STATE_REL; // 触摸板释放状态
  } else {
    data->state = LV_INDEV_STATE_PR; // 触摸板按下状态

    /* 设置坐标 */
    data->point.x = touchY; // X 坐标
    data->point.y = 240-touchX; // Y 坐标

    // 输出坐标信息
    Serial.print("Data x ");
    Serial.println(data->point.x);

    Serial.print("Data y ");
    Serial.println(data->point.y);
  }
}

void setup() {
  // 设置触摸屏校准数据
  uint16_t calData[5] = { 371, 3390, 265, 3336, 4 }; //修改这行内容//
  tft.setTouch(calData);
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  lv_init();

  /* 注册用于调试的打印函数 */
#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print);
#endif

  lv_display_t *disp;
#if LV_USE_TFT_ESPI
  /* 可以在 lv_conf.h 中启用 TFT_eSPI，以简单方式初始化显示屏 */
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
#else
  /* 否则创建一个显示器 */
  disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_flush_cb(disp, my_disp_flush);
  lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
#endif

  /* 初始化（虚拟）输入设备驱动 */
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /* 触摸板应该具有 POINTER 类型 */
  lv_indev_set_read_cb(indev, my_touchpad_read);
  lv_demo_widgets(); // 创建小部件演示
  Serial.println("Setup done");
}

void loop() {
  lv_task_handler(); /* 让 GUI 完成其工作 */
  lv_tick_inc(5);    /* 告诉 LVGL 经过了多少时间 */
  delay(5);          // 延时等待
}
