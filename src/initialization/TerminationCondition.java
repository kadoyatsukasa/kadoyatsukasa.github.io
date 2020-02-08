package initialization;
//: initialization/TerminationCondition.java
// Using finalize() to detect an object that
// hasn't been properly clean up
class Book{
    boolean checkOut=false;
    Book(boolean checkOut){ this.checkOut=checkOut;}
    void checkIn(){ this.checkOut=false;}

    protected void finalize(){
        if(checkOut)  System.out.println("Error:Check Out");
        // Normally，you'll also do this:
        // super.finalize();  //Call the base-class version
    }
}

public class TerminationCondition{
    public static void main(String[] args) {
        Book novel=new Book(true);
        //Proper cleanup
        novel.checkIn();
        //Drop the reference, forget to clean up
        new Book(true);
        //Fource garbage coolecion & finalization
        System.gc();
    }
}/*Output:
Error:Check Out
 *///:~