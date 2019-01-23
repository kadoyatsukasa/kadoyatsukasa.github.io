//:initialization/PassingThis.java

 class Person{
    public void eat(Apple apple){
        Apple peeler=apple.getPeeled();
        System.out.println("Yummy");
    }
}

class Peeler{
    static Apple peel(Apple apple){
        //...remove peel
        return apple;
    }
}

class Apple{
    Apple getPeeled(){
        return Peeler.peel(this);
    }
}

public class PassingThis{
    public static void main(String[] args){
        new Person().eat(new Apple());
    }
}///:~