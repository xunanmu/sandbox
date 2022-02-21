package com.xunanmu.logger

/**
 * 前景色枚举值
 * @param i
 */
enum class LoggerColor(val i: Int) {
    BLACK(30),
    RED(31),
    GREEN(32),
    YELLOW(33),
    BLUE(34),
    PURPLE(35),
    CYAN(36),
    WHITE(37),
    BRIGHT_BLACK(90),
    BRIGHT_RED(91),
    BRIGHT_GREEN(92),
    BRIGHT_YELLOW(93),
    BRIGHT_BLUE(94),
    BRIGHT_PURPLE(95),
    BRIGHT_CYAN(96),
    BRIGHT_WHITE(97),
}


/**
 * 设置字符串的颜色
 *
 * @param string
 * @return Sting
 */
inline fun LoggerColor.setColor(string: String): String {
    return "\u001b[${this.i}m${string}\u001b[0m"
}


/**
 * 下面这些函数供Sting使用
 */
val String.black : String
    get() = LoggerColor.BLACK.setColor(this)

val String.red : String
    get() = LoggerColor.RED.setColor(this)

val String.green : String
    get() = LoggerColor.GREEN.setColor(this)

val String.yellow : String
    get() = LoggerColor.YELLOW.setColor(this)

val String.blue : String
    get() = LoggerColor.BLUE.setColor(this)

val String.purple : String
    get() = LoggerColor.PURPLE.setColor(this)

val String.cyan : String
    get() = LoggerColor.CYAN.setColor(this)

val String.white : String
    get() = LoggerColor.WHITE.setColor(this)

val String.brightBlack : String
    get() = LoggerColor.BRIGHT_BLACK.setColor(this)

val String.brightRed : String
    get() = LoggerColor.BRIGHT_RED.setColor(this)

val String.brightGreen : String
    get() = LoggerColor.BRIGHT_GREEN.setColor(this)

val String.brightYellow : String
    get() = LoggerColor.BRIGHT_YELLOW.setColor(this)

val String.brightBlue : String
    get() = LoggerColor.BRIGHT_BLUE.setColor(this)

val String.brightPurple : String
    get() = LoggerColor.BRIGHT_PURPLE.setColor(this)

val String.brightCyan : String
    get() = LoggerColor.BRIGHT_CYAN.setColor(this)

val String.brightWhite : String
    get() = LoggerColor.BRIGHT_WHITE.setColor(this)
