import java.util.Arrays;
import java.util.List;

public class ArrangeList{
  public static void main(String[] args) {
    List<Integer> ls=Arrays.asList(1,3,5,7,9);
    int []ar ={1,2,3,4,5};
    int sum=Arrays.stream(ar).filter(n->n%2==1).sum();
    System.out.println(sum);
    List<String> str=Arrays.asList("Box","Robot","simple");
    str.stream().map(s->s,length());

  }
}