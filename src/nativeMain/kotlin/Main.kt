
import com.xunanmu.logger.LinuxX64Logger
import com.xunanmu.utils.createFile


val logger = LinuxX64Logger("test")

fun main() {
    println(Uts("scs","hello"))
    val stat1 = cValue<stat>()
    stat1.placeTo(MemScope()).pointed
    stat1.useContents {
        println(this@useContents)
        stat("r",ptr)
        println("1 $st_ino")
    }
    val stat2 = cValue<stat>()
    memScoped {
        stat("t",stat2.ptr)
        println(stat2.placeTo(memScope).pointed.st_ino)

    }
    wait
    stat2.useContents {
        println("2 $st_ino")
    }
    memScoped {

        val stat = alloc<stat>()
        stat("e",stat.ptr)
        println("3 ${stat.st_ino}")
    }


}
