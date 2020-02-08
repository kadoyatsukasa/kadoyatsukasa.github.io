package initialization;

//：initialization/Overloading.java
//Demonstration of both constructor
//and ordinary method overloading

class Tree{
    int height;
    Tree(){
        System.out.println("Planting a seeding");
        height=0;
    }

    Tree(int initialHeight){
        height=initialHeight;
        System.out.println("Creating new Tree that is "+height+" feet tall");
    }

    void info(){
       System.out.println("Tree is "+ height + " feet tall");
    }

    void info(String s){
        System.out.println(s+" :Tree is "+height+" feet tall");
    }
}

public class Overloading{
    public static void main(String[] args){
        for(int i=0;i<5;i++){
            Tree t=new Tree(i);
            t.info();
            t.info("overloaded method");
        }
        new Tree();//Overloaded constructor
    }
}/*output:
overloaded method :Tree is 0 feet tall
Creating new Tree that is 1 feet tall
Tree is 1 feet tall
overloaded method :Tree is 1 feet tall
Creating new Tree that is 2 feet tall
Tree is 2 feet tall
overloaded method :Tree is 2 feet tall
Creating new Tree that is 3 feet tall
Tree is 3 feet tall
overloaded method :Tree is 3 feet tall
Creating new Tree that is 4 feet tall
Tree is 4 feet tall
overloaded method :Tree is 4 feet tall
Planting a seeding
*///:~