package initialization;

//:initialization/OrderOfInitialization.java

//When the constructor is coalled to create a 
//Window object,you'll see a message
class Window{
    Window(int mark){ System.out.println("Windows("+mark+")");} 
}

class House{
    Window w1=new Window(1);  //Before constructor

    House(){
        System.out.println("House()");
        w3=new Window(33);  //Reinitialize w3
    }

    Window w2=new Window(2); //After constructor
    void f(){System.out.println("f()");}
    Window w3=new Window(3); //At the end
}

public class OrderOfInitialization{
    public static void main(String[] args) {
        House h=new House();
        h.f();
    }
}/*OutPut:
Windows(1)
Windows(2)
Windows(3)
House()
Windows(33)
f()
 *///:~