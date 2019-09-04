import java.io.*;
import java.util.Scanner;  // Import the Scanner class
public class Students {
  public static void names(String name){
    // boolean empty = isEmpty(name);

    if ( name.length() != 0) {
      System.out.println("\nUsername is " + name);
    }else{
      System.out.println("\nUnknown");

    }

  }

  // public static boolean isEmpty(String name){
  //   boolean empty = false;
  //   for(int i=0;name.charAt(i)!='\0';i++){
  //     if (name.charAt(i) != '\0'){
  //       empty = false;
  //
  //     }else{
  //       empty = true;
  //     }
  //   }
  //   return empty;
  // }
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);

      Students obj = new Students();
      System.out.println("\nEnter username");

      String userName = sc.nextLine();  // Read user input
      obj.names(userName);
  }
}
