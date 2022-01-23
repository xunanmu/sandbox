/**
 * @author: 徐南木
 * @date: 2022/1/23 3:01
 * @description: 
 */

#include <error.h>
#include "log/log.h"
#include "namespace/uts.h"

int main(int argc, char *argv[]) {

    system("umount /root/ns/uts");
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname="test_uts",
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    return 0;
}
