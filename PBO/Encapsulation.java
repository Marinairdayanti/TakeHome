
import student_1301174319.Student_1301174319;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Marina Ir
 */
public class Encapsulation {
     public static void main(String[] args) {
     Student_1301174319 s1 = new Student_1301174319("Max",321032,true,3.7);
     Student_1301174319 s2 = new Student_1301174319("Anny",23331,true);
     Student_1301174319 s3 = new Student_1301174319("Bobby",22122);
     System.out.println("Student 1");
     s1.display();
     System.out.println("Student 2");
     s2.display();
     System.out.println("Student 3");
     s3.display();
     }
}
