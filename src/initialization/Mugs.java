package initialization;
//:initialization/Mugs.java

class Mug{
    Mug(int maker){
        System.out.println("Mug("+maker+")");
    }
    void f_Mug(int marker){
        System.out.println("f_Mug("+marker+")");
    }
}

public class Mugs{
    Mug mug1;
    Mug mug2;
    {
        mug1=new Mug(1);
        mug2=new Mug(2);
        System.out.println("mug1 & mug2 initialized");
    }

    Mugs(){
        System.out.println("Mugs()");
    }

    Mugs(int i){
        System.out.println("Mug(int)");
    }
    public static void main(String[] args) {
        System.out.println("Inside main()");
        new Mugs();
        System.out.println("new Mugs() completed");
        new Mugs();
        System.out.println("new Mugs() completed");
    }
}/*Output:
Inside main()
Mug(1)
Mug(2)
mug1 & mug2 initialized
Mugs()
new Mugs() completed
Mug(1)
Mug(2)
mug1 & mug2 initialized
Mugs()
new Mugs() completed
*///:~