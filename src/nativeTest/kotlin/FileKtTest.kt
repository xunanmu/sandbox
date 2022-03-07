import com.xunanmu.utils.createFile
import com.xunanmu.utils.popen
import kotlin.test.AfterTest
import kotlin.test.Test
import kotlin.test.assertEquals

class FileKtTest {
    @Test
    fun testCreateFile(){
        if(createFile("test/test")){
           assertEquals("test/test",popen("ls test/test"))
        }
        assertEquals(false, createFile("test/test/test"))
    }

    @AfterTest
    fun deleteFile(){
        popen("rm -rf test")
    }
}