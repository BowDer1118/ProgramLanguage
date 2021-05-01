import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class PB {
    public static void main(String[] args) throws IOException {
        List<Integer[]> inputList = Files.lines(Paths.get("ProblemB_test_input.txt")).map(line -> {
            //Make String[] by using each line
            String[] strings = line.split(" ");
            //Make Integer[](with ascending sort) by using String[]
            Integer[] numbers = Arrays.stream(strings).map(Integer::valueOf).sorted().toArray(Integer[]::new);
            return numbers;
        }).collect(Collectors.toList());

        List<Integer[]> result = inputList.stream().map(integers -> {
            //Find GCD
            int GCD = IntStream.rangeClosed(1, integers[0]).filter(g -> integers[0] % g == 0 && integers[1] % g == 0).max().getAsInt();
            //Calculate LCM
            int LCM = integers[0] * integers[1] / GCD;
            return new Integer[]{GCD, LCM};
        }).collect(Collectors.toList());


        //Output GCD LCM
        System.out.print(result.stream().map(p -> p[0] + " " + p[1]).collect(Collectors.joining("\n")));
    }
}
