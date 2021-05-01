import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class PA {
    public static void main(String[] args) throws IOException {
        //Scan string from test_input file
        String[] inputData= Files.lines(Paths.get("ProblemA_test_input.txt")).toArray(String[]::new);

        String result=Arrays.stream(inputData).mapToInt(Integer::parseInt)    //String[] to int[]
                                .mapToObj(num->{
                                    //Find all factors
                                    int[] factors= IntStream.rangeClosed(1,num).filter(f->num%f==0).toArray();
                                    //Use BigInteger isProbablePrime method to check all factors is prime or not
                                    int[] primeFactors= Arrays.stream(factors).filter(f->new BigInteger(String.valueOf(f)).isProbablePrime(10)).toArray();
                                    //Find all pair of primeFactor and times
                                    Map<Integer,Integer> map= Arrays.stream(primeFactors).boxed().collect(Collectors.toMap(integer -> integer,integer -> {
                                        long times=IntStream.iterate(integer,t->num%t==0,t->t*=integer).count();
                                        return Long.valueOf(times).intValue();
                                    }));

                                    //Make a output String
                                    StringBuffer sb=new StringBuffer();
                                    String temp;
                                    temp=Arrays.stream(factors).mapToObj(String::valueOf).collect(Collectors.joining(" "));
                                    sb.append(temp+"\n");

                                    temp=Arrays.stream(primeFactors).mapToObj(String::valueOf).collect(Collectors.joining(" "));
                                    sb.append(temp+"\n");

                                    List<Map.Entry<Integer,Integer>> list=new ArrayList<>(map.entrySet());
                                    temp=list.stream().map(e->"("+e.getKey()+", "+e.getValue()+")").collect(Collectors.joining(""));
                                    sb.append(temp);
                                    return sb.toString();   //Return each input response answer
                                })
                                .collect(Collectors.joining("\n\n"));
        System.out.print(result);
    }

}
