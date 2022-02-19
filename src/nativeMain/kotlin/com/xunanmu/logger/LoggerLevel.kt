package com.xunanmu.logger

import com.xunanmu.logger.LoggerConfig.loggerLevel

enum class LoggerLevel {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR
}
fun LoggerLevel.isLoggerEnabled(): Boolean = this.ordinal >= loggerLevel.ordinal