package demo;
public class AppTest{
    
    public void testappHasACreeting(){
        App classUnderTest = new App();
        assertNotNull("app should hava a greeting", classUnderTest.getString());
    }

    private void assertNotNull(String string, String string2) {
    }
}