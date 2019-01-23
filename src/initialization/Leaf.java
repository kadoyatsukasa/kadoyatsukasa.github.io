//:initialization/Leaf.java
//Simple use of the "this" keyword
//usage : return the reference of the current object
package initialization;
 
public class Leaf{
    int i=0;
    Leaf increment(){
        i++;
        return this;
    }

    void print(){
        System.out.println("i="+i);
    }
    public static void main(String[] args){
        Leaf x=new Leaf();
        x.increment().increment().increment().print();
    }
} /*Output:
i=3
*///:~