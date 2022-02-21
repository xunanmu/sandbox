package com.xunanmu.logger

/**
 * Logger 全局配置
 */
@Suppress("VARIABLE_IN_SINGLETON_WITHOUT_THREAD_LOCAL")
object LoggerConfig{
    var level= LoggerLevel.TRACE
    object Color{
        var stat = true
        var error = LoggerColor.BRIGHT_RED
        var warn = LoggerColor.BRIGHT_YELLOW
        var info = LoggerColor.BRIGHT_GREEN
        var debug = LoggerColor.BRIGHT_BLUE
        var trace = LoggerColor.BRIGHT_PURPLE
    }
    object Output{
        var error = ::outputError
        var warn = ::output
        var info = ::output
        var debug = ::output
        var trace = ::output
    }
}