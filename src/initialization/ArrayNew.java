package initialization;

//:initialization/ArrayNew.java
//Creating arrays with new
import java.util.*;

public class ArrayNew{
    public static void main(String[] args) {
        int[] a;
        Random random=new Random(47);
        a=new int[random.nextInt(20)];
        System.out.println("length of a = "+a.length);
        System.out.println(Arrays.toString(a));
    }
}/**Output:
length of a = 18
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
*///:~