/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Marina Ir
 */
public class StudentE_1301174319 {
    public String name;
    public long studentid;
    boolean isMale;
    
    public StudentE_1301174319 (){
        this.isMale = true;
    
    }
    
    public StudentE_1301174319(String name, long studentid, boolean isMale){
        this.name=name;
        this.studentid=studentid;
        this.isMale=isMale;
    }   
    
     public void set_name(String name){
        this.name=name;
    }
     
     public void set_studentid(long studentid){
        this.studentid=studentid;
    }
     
     public void set_isMale(boolean isMale){
        this.isMale=true;
    }
     
     
     public String get_name(String name){
        return name;
    }
     
     public long get_studentid(long studentid){
        return studentid;
    }
     
     public boolean get_isMale(boolean isMale){
        return isMale;
    }
}
