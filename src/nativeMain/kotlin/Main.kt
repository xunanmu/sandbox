import com.xunanmu.logger.*

val logger = LinuxX64Logger("test")

fun main() {
    val throwable = Throwable()
    logger.error("这是个程序错误信息",throwable)
    logger.warn("这是个程序警告信息",throwable)
    logger.info("这是个程序一般消息",throwable)
    logger.debug("这是个程序调试信息",throwable)
    logger.trace("这是个程序追踪内容",throwable)
    logger.error()
    logger.warn()
    logger.info()
    logger.debug()
    logger.trace()
}
