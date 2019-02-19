package initialization;

import java.util.Arrays;

//:initialization/ArrayInit.java
//Array initialization
public class ArrayInit{
    public static void main(String[] args) {
        Integer[] a={
            new Integer(1),
            new Integer(2),
            3, //Autoboxing
        }; 

        Integer[] b=new Integer[]{
            new Integer(1),
            new Integer(2),
            3,  //Autoboxing
        };

        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
    }
}/*Oytput:
[1, 2, 3]
[1, 2, 3]
*///:~