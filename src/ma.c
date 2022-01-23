/**
 * @author: 徐南木
 * @date: 2022/1/23 3:01
 * @description: 
 */

#include "namespace/uts.h"

int main(int argc, char *argv[]) {

    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_WARN,  ELOG_FMT_TAG|ELOG_FMT_LVL  | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL  );
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();

    system("umount /root/ns/ust");
    struct uts uts ={
            .path="/root/ns/ust",
            .hostname="test_ust",
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    sleep(100000);
    return 0;
}
