package initialization;
//: initialization/ExplicitStatic.java
class Cup{

    Cup(int marker){
        System.out.println("Cup("+marker+")");
    }
    void f_Cup(int marker){
         System.out.println("f_Cup("+marker+")");
    }
}

class Cups{
    static Cup cup1;
    static Cup cup2;
    static {
        cup1=new Cup(1);
        cup2=new Cup(2);
    }
    Cups(){
        System.out.println("Cups()");
    }
}

public class ExplicitStatic{
    public static void main(String[] args) {
        System.out.println("Inside main()");
        Cups.cup1.f_Cup(99);
    }
}/*Output: 
Inside main()
Cup(1)
Cup(2)
f_Cup(99)
*///:~