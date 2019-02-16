package initialization;
//:initialization/ArrayOfPrimitives.java

public class ArrayOfPrimitives{
    public static void main(String[] args) {
        int[] a1={1,2,3,4,5};
        //Initialize the array by copy from another array,
        //It only copy a reference 
        int[] a2;  
        a2=a1;

        for(int item:a2) item+=1;
        for(int i=0;i<a1.length;i++)
            System.out.println("a1["+i+"] = "+a1[i]);
    }
}/*Output:
a1[0] = 1
a1[1] = 2
a1[2] = 3
a1[3] = 4
a1[4] = 5
*///:~