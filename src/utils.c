/**
 * @author: 徐南木
 * @date: 2022/2/8 21:39
 * @description: 
 */

#include "utils.h"

bool create_file(char *path_file) {
    char dir[256];
    char *path = path_file;
    int i = 0;
    while (*path){
        while (*path != '/' &&*path){
            dir[i] = *path;
            ++path;
            ++i;
        }
        dir[i] = *path;
        ++path;
        ++i;
        dir[i] = 0;
        if (path[-1] != 0){
            DIR *flag = opendir(dir);
            if(flag == NULL){
                if (mkdir(dir,0300)==-1){
                    log_e("create dir fail.[dir:%s]",dir);
                    return false;
                }
            }
        } else{
            if (open(dir,O_CREAT)==-1){
                log_e("create file fail.[file:%s]",dir);
                return false;
            }
            log_d("[%s,%c]",dir,*path);
            break;
        }
        log_d("[%s,%c]",dir,*path);
    }
    log_i("create file success.[file:%s]",path_file);
    return true;
}