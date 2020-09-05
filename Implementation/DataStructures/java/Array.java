import java.util.Arrays;

public class Array
{
    public static void main(String[] args)
    {
        //array declaration
        int[] intArr = {
            10,
            2,
            5,
            6,
            22
        };

        int[][] multiDimArr = {
            {23, 6},
            {22, 63},
            {63, 12}
        };

        String[] stringArr = {
            "jOSh",
            "maRIa",
            "ricHard",
            "JoSue",
            "Tanaka"
        };

        boolean[] boolArr = {true, false};

        //array modification 
        intArr[3] = 2 + 3;
        stringArr[2] = String.valueOf(intArr[3]);
        intArr[4] = boolArr[1] ? intArr[1] + intArr[2] : intArr[4] - intArr[0];
        
        //get size
        System.out.println(intArr.length);
        System.out.println(boolArr.length);

        //sorting
        Arrays.sort(intArr);

        //transform
        StringBuilder sb = new StringBuilder(stringArr[0]);
        sb.reverse();
        System.out.println(sb.toString());

        //tolower
        for (int i = 0; i < stringArr.length; ++i)
            stringArr[i] = stringArr[i].toLowerCase();
    
        //tolower
        stringArr[3] = stringArr[3].toUpperCase();

        //hashing
        for (int i = 0; i < intArr.length; ++i)
            System.out.println(intArr[i]);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                System.out.println(multiDimArr[i][j]);
            }
        }

        for (int i = 0; i < stringArr.length; ++i)
            System.out.println(stringArr[i]);

        for (int i = 0; i < boolArr.length; ++i)
            System.out.println(boolArr[i]);

    }
}
