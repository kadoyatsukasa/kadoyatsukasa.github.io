package initialization;
//: initialization/Flower.java
// Calling constructors with this
public class Flower{
    int petalCount=0;
    String s="init values";

    Flower(int petals){
        this.petalCount=petals;
        System.out.println("Constructor w/ int argment only, petalCount = "
            +petalCount);
    }
    Flower(String ss){
        System.out.print("Constructor w/ String argument only, petalCount = "
            +ss);
        s=ss;
    }
    Flower(String s,int petals){
        this(petals);
        // this(s); //can not call two 
        this.s=s;   //Another use this
        System.out.println("String & int args");
    }
    Flower(){
        this("hi",47);
        System.out.println("default constructor (no args)");
    }
    void printPetalCount(){
        System.out.println("petalCount = "+petalCount+" , s = "+ s);
    }

    public static void main(String[] args){
        Flower x=new Flower();
        x.printPetalCount();
    }
}/*output:
Constructor w/ int argment only, petalCount = 47
String & int args
default constructor (no args)
petalCount = 47 , s = hi
*///:~