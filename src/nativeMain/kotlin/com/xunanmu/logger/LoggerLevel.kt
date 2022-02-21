package com.xunanmu.logger

enum class LoggerLevel {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR
}

inline fun LoggerLevel.isLoggerEnabled(): Boolean =
    this.ordinal >= LoggerConfig.level.ordinal

inline fun LoggerLevel.function(string: String): Any = when (this) {
    LoggerLevel.TRACE -> LoggerConfig.Output.trace(string)
    LoggerLevel.DEBUG -> LoggerConfig.Output.debug(string)
    LoggerLevel.INFO  -> LoggerConfig.Output.info(string)
    LoggerLevel.WARN  -> LoggerConfig.Output.warn(string)
    LoggerLevel.ERROR -> LoggerConfig.Output.error(string)
}

inline fun LoggerLevel.color(string: String): String = when (this) {
    LoggerLevel.TRACE -> LoggerConfig.Color.trace.setColor(string)
    LoggerLevel.DEBUG -> LoggerConfig.Color.debug.setColor(string)
    LoggerLevel.INFO  -> LoggerConfig.Color.info.setColor(string)
    LoggerLevel.WARN  -> LoggerConfig.Color.warn.setColor(string)
    LoggerLevel.ERROR -> LoggerConfig.Color.error.setColor(string)
}

inline fun LoggerLevel.logIfEnabled(moduleName: String,msg :String="",throwable: Throwable? = null){
    if (isLoggerEnabled()){
        val throwableMessage = throwable?.stackTraceToString()?:""
        val message = formatMessage(this,moduleName, msg+throwableMessage)
        if(LoggerConfig.Color.stat){
            function((color(message)))
        }else{
            function(message)
        }
    }
}
