package com.xunanmu.logger

import kotlinx.cinterop.*
import platform.posix.*

inline fun formatMessage(level: LoggerLevel, loggerName: String, msg: String?): String {
    var formatMessage = ""
    memScoped {
        var timespec = alloc<timespec>()
        clock_gettime(CLOCK_REALTIME,timespec.ptr)
        val dataTime = localtime(cValuesOf(timespec.tv_sec))
        val dateTimeFormat = "+0800 2022-2-19 19:11:00"
        strftime(
            dateTimeFormat.cstr,
            dateTimeFormat.length.toULong(),
            "%Z %Y-%m-%d %H:%M:%S",
            dataTime
        )
        formatMessage = "${dateTimeFormat}.${timespec.tv_nsec} {$loggerName} ${level.name} pid:${getpid()} ppid:${getppid()} $msg"
    }
    return formatMessage
}