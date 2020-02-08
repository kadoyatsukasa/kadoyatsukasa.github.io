//:initalization/ArrayCLassObj.java
//Creating an array of noprimitive objects
import java.util.*;

public class ArrayClassObj{
    public static void main(String[] args) {
        Random rand=new Random(47);
        Integer[] a=new Integer[rand.nextInt(20)];
        System.out.println("Length of a = "+ a.length);

       for(int i=0;i<a.length;i++)
            a[i]=rand.nextInt(500); //Autoboxing
        
        System.out.println(Arrays.toString(a));
    }
}/*Output:
Length of a = 18
[55, 193, 361, 461, 429, 368, 200, 22, 207, 288, 128, 51, 89, 309, 278, 498, 361, 20]
*/