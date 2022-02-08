/**
 * @author: 徐南木
 * @date: 2022/2/8 21:39
 * @description: 
 */

#ifndef SANDBOX_UTILS_H
#define SANDBOX_UTILS_H

#include <stdbool.h>


#define KiB(x) (1024*(x))
#define MiB(x) (1024*KiB(x))
#define GiB(x) (1024*MiB(x))
#define TiB(x) (1024*GiB(x))

#define us(x) (1000*(x))
#define ms(x) (1000*us(x))
#define s(x)  (1000*ms(x))
#define m(x)  (60*s(x))
#define h(x)  (60*m(x))

/**
 * @brief 自动创建文件目录路径
 * @param path_file
 * @return bool
 */
bool create_file(char *path_file);

/**
 * @brief 判断两个文件的路径是不是同一个节点
 * @param first_file_path
 * @param second_file_path
 * @return bool
 */
bool is_same_inode(char *first_file_path,char *second_file_path);
#endif //SANDBOX_UTILS_H
