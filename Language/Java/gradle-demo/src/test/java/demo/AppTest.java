package demo;
import org.junit.Test;
import static org.junit.Assert.*;
public class AppTest{
    @Test
    public void testappHasACreeting(){
        App classUnderTest = new App();
        assertNotNull("app should hava a greeting", classUnderTest.getString());
    }
}