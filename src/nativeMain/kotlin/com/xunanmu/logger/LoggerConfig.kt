package com.xunanmu.logger


@kotlin.native.concurrent.ThreadLocal
object LoggerConfig{
    var loggerLevel= LoggerLevel.INFO
    var loggerColor = true
}