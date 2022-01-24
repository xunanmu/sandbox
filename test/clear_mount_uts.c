/**
 * @author: 徐南木
 * @date: 2022/1/24 16:04
 * @description: 
 */
#include <stdlib.h>
int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) {
        system("umount /root/ns/uts");
    }
    return 0;
}