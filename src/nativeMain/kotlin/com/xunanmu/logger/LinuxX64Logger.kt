package com.xunanmu.logger

import com.xunanmu.logger.LoggerLevel.*
import com.xunanmu.logger.LoggerColor.*

class LinuxX64Logger (val name: String)


inline fun LinuxX64Logger.error(msg: String?){
    println(formatMessage(ERROR,this.name,msg).brightRed)
}

inline fun LinuxX64Logger.warn(msg: String?){
    println(formatMessage(WARN,this.name,msg).brightYellow)
}

inline fun LinuxX64Logger.info(msg: String?){
    println(formatMessage(INFO,this.name,msg).brightGreen)
}

inline fun LinuxX64Logger.debug(msg: String?){
    println(formatMessage(DEBUG,this.name,msg).brightBlack)
}

inline fun LinuxX64Logger.trace(msg: String?){
    println(formatMessage(TRACE,this.name,msg).brightPurple)
}
//inline fun LinuxX64Logger.error(msg: String?) {
//    if (ERROR.isLoggerEnabled()){
//        if (LoggerConfig.loggerColor){
//            println(formatMessage(ERROR,this.name,msg).brightRed)
//        }else{
//            println(formatMessage(ERROR,this.name,msg))
//        }
//    }
//}
//
//inline fun LinuxX64Logger.warn(msg: String?) = WARN.logIfEnabled(msg,this.name,YELLOW)
//
//inline fun LinuxX64Logger.info(msg: String?) = INFO.logIfEnabled(msg,this.name,GREEN)
//
//inline fun LinuxX64Logger.debug(msg: String?) = DEBUG.logIfEnabled(msg,this.name,BLUE)
//
//inline fun LinuxX64Logger.trace(msg: String?) = TRACE.logIfEnabled(msg,this.name,PURPLE)
//
//inline fun LoggerLevel.logIfEnabled(msg :String?,loggerName: String,color: LoggerColor){
//    if (isLoggerEnabled()){
//        if (LoggerConfig.loggerColor){
//            println(color.setBrightColor(formatMessage(this,loggerName,msg)))
//        }else{
//            println(formatMessage(this,loggerName,msg))
//        }
//    }
//}
