package initialization;

//:initialization/StaticInitialization.java
// Specifying initial values a class definition

class Bowl{
    Bowl(int mark){System.out.println("Bow("+mark+")");}

    void f_Bowl(int mark){System.out.println("f_Bowl(" + mark +")");}
}

class Table {
    static Bowl bowl1=new Bowl(1);
    Table(){
        System.out.println("Table()");
        bowl2.f_Bowl(1);
    }

    void f_Table(int mark){System.out.println("f_Table("+mark+")");}

    static Bowl bowl2=new Bowl(2);
}

class Cupboard{
    Bowl bowl3=new Bowl(3);
    static Bowl bowl4=new Bowl(4);
    Cupboard(){
        System.out.println("Cupboard()");
        bowl4.f_Bowl(2);
    }
    void f_Cupboard(int mark){System.out.println("f_Cupboard("+mark+")");}
    static Bowl bowl5=new Bowl(5);
}

public class StaticInitialization{
    public static void main(String[] args) {
        System.out.println("Creating a new Cupboard in main");
        new Cupboard();
        System.out.println("Creating a new Cupboard in main");
        new Cupboard();
        table.f_Table(1);
        cupboard.f_Cupboard(1);
    }
    static Table table=new Table();
    static Cupboard cupboard=new Cupboard();
}/*Output:
Bow(1)
Bow(2)
Table()
f_Bowl(1)
Bow(4)
Bow(5)
Bow(3)
Cupboard()
f_Bowl(2)
Creating a new Cupboard in main
Bow(3)
Cupboard()
f_Bowl(2)
Creating a new Cupboard in main
Bow(3)
Cupboard()
f_Bowl(2)
 *///:~