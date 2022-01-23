/**
 * @author: 徐南木
 * @date: 2022/1/23 3:01
 * @description: 
 */

#include <error.h>
#include "log/log.h"
#include "namespace/uts.h"

int main(int argc, char *argv[]) {

    system("umount /root/ns/ust");
    struct uts uts ={
            .path="/root/ns/ust",
            .hostname="test_ust",
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    return 0;
}
