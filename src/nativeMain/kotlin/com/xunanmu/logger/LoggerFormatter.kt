package com.xunanmu.logger

import datetime.getDateTimeNanosecond_t
import kotlinx.cinterop.*
import platform.linux.SYS_gettid
import platform.posix.*


inline fun formatMessage(level: LoggerLevel, moduleName: String, msg: String): String {
    return "${getDateTime()} {$moduleName} ${level.name} pid:${getpid()} ppid:${getppid()} tid:${syscall(SYS_gettid.toLong())} $msg"
}

inline fun getDateTime():String{
    val dateTimeCString = getDateTimeNanosecond_t("%Z %Y-%m-%d %H:%M:%S")
    val dateTimeKString = dateTimeCString?.toKString()?:"C lib Memory OOM"
    nativeHeap.free(dateTimeCString.rawValue)
    return dateTimeKString
}