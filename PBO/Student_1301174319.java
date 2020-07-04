/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package student_1301174319;

/**
 *
 * @author Marina Ir
 */
public class Student_1301174319 {
    public String name;
    public long studentid;
    public boolean isMale;
    private double grade;
    
    public Student_1301174319 (){
    
    }

    public Student_1301174319(String Anny, long studentid, boolean isMale) {
        this.name=Anny;
        this.studentid=studentid;
        this.isMale=isMale;  
    }

    public Student_1301174319(String Bobby, long studentid) {
        this.name=Bobby;
        this.studentid=studentid;
    }
    
    public void display(){
        System.out.println("Name: "+name);
        System.out.println("StudentID: "+studentid);
        if(isMale){
            System.out.println("Sex: Male");
        }else{
            System.out.println("Sex: Female");
        }
        System.out.println("Grade: "+grade);
    }
    
    public Student_1301174319(String name, long studentid, boolean isMale, double grade){
        this.name=name;
        this.studentid=studentid;
        this.isMale=isMale;
        this.grade=grade;
    }
}
