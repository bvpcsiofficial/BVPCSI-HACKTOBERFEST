import java.util.HashMap;
import java.util.Map;

public class AddingElements {

	public static void main(String[] args) {
		HashMap<Integer,String> hm=new HashMap<>();    
	    
	      hm.put(100,"John");    
	      hm.put(101,"Max");    
	      hm.put(102,"Emily");  
 	      System.out.println("Initial list of elements: "+hm);  
	      
	      System.out.println("After invoking put() method ");  
	      for(Map.Entry m:hm.entrySet()){    
	       System.out.println(m.getKey()+" "+m.getValue());    
	      }  
	        
	      hm.putIfAbsent(103, "Gaurav");  
	      System.out.println("After invoking putIfAbsent() method ");  
	      for(Map.Entry m:hm.entrySet()){    
	           System.out.println(m.getKey()+" "+m.getValue());    
	          }  
	      HashMap<Integer,String> map=new HashMap<Integer,String>();  
	      map.put(104,"Rohan");  
	      map.putAll(hm);  
	      System.out.println("After invoking putAll() method ");  
	      for(Map.Entry m:map.entrySet()){    
	           System.out.println(m.getKey()+" "+m.getValue());    
	          }  
	 }  

}
