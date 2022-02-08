/**
 * @author: 徐南木
 * @date: 2022/2/8 21:39
 * @description: 
 */

#ifndef SANDBOX_UTILS_H
#define SANDBOX_UTILS_H

#include <base_sandbox.h>

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
