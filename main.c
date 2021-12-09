#define LOG_TAG "main"

#include "elog.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void test_elog(void);

int main(void) {
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN,  ELOG_FMT_TAG|ELOG_FMT_LVL  | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL &~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL  );
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();

    /* dynamic set enable or disable for output logs (true or false) */
//    elog_set_output_enabled(false);
    /* dynamic set output logs's level (from ELOG_LVL_ASSERT to ELOG_LVL_VERBOSE) */
//    elog_set_filter_lvl(ELOG_LVL_WARN);
    /* dynamic set output logs's filter for tag */
//    elog_set_filter_tag("main");
    /* dynamic set output logs's filter for keyword */
//    elog_set_filter_kw("Hello");
    /* dynamic set output logs's tag filter */
//    elog_set_filter_tag_lvl("main", ELOG_LVL_WARN);

    /* test logger output */
    test_elog();

    return EXIT_SUCCESS;
}

/**
 * EasyLogger demo
 */
void test_elog(void) {
    uint8_t buf[256]= {0};
    int i = 0;

    for (i = 0; i < sizeof(buf); i++)
    {
        buf[i] = i;
    }
    while(true) {
        /* test log output for all level */
        log_a("%d",123);
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
#define LOG_TAG "maingnfghf"
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
//        elog_raw("Hello EasyLogger!");
        elog_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }
}



