package com.xunanmu.logger

class LinuxX64Logger (val moduleName: String = "")

inline fun LinuxX64Logger.error(msg: String ="", throwable: Throwable? = null) {
    return LoggerLevel.ERROR.logIfEnabled(this.moduleName,msg,throwable)
}
inline fun LinuxX64Logger.warn(msg: String ="", throwable: Throwable? = null) {
    return LoggerLevel.WARN.logIfEnabled(this.moduleName,msg,throwable)
}
inline fun LinuxX64Logger.info(msg: String ="", throwable: Throwable? = null) {
    return LoggerLevel.INFO.logIfEnabled(this.moduleName,msg,throwable)
}
inline fun LinuxX64Logger.debug(msg: String ="", throwable: Throwable? = null) {
    return LoggerLevel.DEBUG.logIfEnabled(this.moduleName,msg,throwable)
}
inline fun LinuxX64Logger.trace(msg: String ="", throwable: Throwable? = null) {
    return LoggerLevel.TRACE.logIfEnabled(this.moduleName,msg,throwable)
}