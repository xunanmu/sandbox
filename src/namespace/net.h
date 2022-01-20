/**
 * @author: 徐南木
 * @date: 2022/1/20 16:44
 * @description: 
 */

#ifndef SANDBOX_NET_H
#define SANDBOX_NET_H

/**
 * @brief 网络配置，你可以通过下面网址了解相关信息
 * https://learnku.com/docs/go-micro-build/1.0/explain-the-network-mode-of-vmware-and-docker/8879
 */
struct net{
    char *path;
    enum {
        host   = 0,         /*主机模式，即与宿主机IP一样*/
        bridge = 1,         /*桥接模式，与宿主机处于同一个网段下*/
        nat    = 2,         /*nat模式，即创建虚拟交换机，默认10.10.0.0*/
        none   = 4,         /*无网模式，就存在一个lo本地环回设备*/
    }net_mode;              /* nat|none,能实现类似VMware的主机模式*/
    unsigned char ipv4[4];  /*ipv4,ipv6默认可以不用设置，host，none设置无效，目前暂时不支持IPV6*/
    unsigned char ipv6[];   /*bridge设置IP必须在同一网段下，nat设置IP若无交换机网段则重新创建虚拟交换机*/
};
#endif //SANDBOX_NET_H
