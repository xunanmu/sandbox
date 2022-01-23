/**
 * @author: 徐南木
 * @date: 2021/12/9 16:52
 * @description: 
 */

#include "base_sandbox.h"


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
                    log_e("create [dir:%s] fail.\n",dir);
                    return false;
                }
            }
        } else if (fopen(dir,"w")==NULL){
            log_e("create [file:%s] fail.\n",dir);
            return false;
        }
        log_d("[%s,%c]",dir,*path);
    }
    log_i("create %s success.\n",path_file);
    return true;
}