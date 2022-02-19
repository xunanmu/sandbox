import com.xunanmu.logger.*
import logger.*
import kotlin.system.measureNanoTime
import kotlin.system.measureTimeMicros
import kotlin.time.ExperimentalTime
import kotlin.time.measureTime
import kotlin.time.measureTimedValue

@OptIn(ExperimentalTime::class)
fun main() {
    val logger = LinuxX64Logger("test")
    LoggerConfig.loggerLevel = LoggerLevel.TRACE
    println(measureTimedValue {
        logger.error("这是个错误信息")
        logger.warn("这是一个警告信息")
        logger.info("这是一个普通消息")
        logger.debug("这是debug信息")
        logger.trace("这是一个追踪信息")
        logger.error("这是个错误信息")
        logger.warn("这是一个警告信息")
        logger.info("这是一个普通消息")
        logger.debug("这是debug信息")
        logger.trace("这是一个追踪信息")
    })
    println(measureTimedValue {
        logger_output(LOGGER_ERROR, 0, null, null, "这是个错误信息%d", 1)
        logger_output(LOGGER_WARN, 0, null, null, "这是个错误信息%d", 2)
        logger_output(LOGGER_INFO, 0, null, null, "这是个错误信息%d", 3)
        logger_output(LOGGER_DEBUG, 0, null, null, "这是个错误信息%d", 4)
        logger_output(LOGGER_TRACE, 0, null, null, "这是个错误信息%d", 5)
        logger_output(LOGGER_ERROR, 0, null, null, "这是个错误信息%d", 1)
        logger_output(LOGGER_WARN, 0, null, null, "这是个错误信息%d", 2)
        logger_output(LOGGER_INFO, 0, null, null, "这是个错误信息%d", 3)
        logger_output(LOGGER_DEBUG, 0, null, null, "这是个错误信息%d", 4)
        logger_output(LOGGER_TRACE, 0, null, null, "这是个错误信息%d", 5)
    })
    println(measureTimedValue{
        logger_output(LOGGER_ERROR, 0, null, null, "这是个错误信息%d", 1)
        logger_output(LOGGER_WARN, 0, null, null, "这是个错误信息%d", 2)
        logger_output(LOGGER_INFO, 0, null, null, "这是个错误信息%d", 3)
        logger_output(LOGGER_DEBUG, 0, null, null, "这是个错误信息%d", 4)
        logger_output(LOGGER_TRACE, 0, null, null, "这是个错误信息%d", 5)
    })
}