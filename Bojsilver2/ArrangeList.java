import java.util.Arrays;
import java.util.Collections;
import java.util.List;
public class ArrangeList{
  public static void main(String[] args) {
    List<Integer> ls=Arrays.asList(1,3,5,7,9);
    Collections.reverse(ls);
    System.out.println(ls);
  }
}